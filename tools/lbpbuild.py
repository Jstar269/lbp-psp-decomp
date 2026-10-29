#!/usr/bin/env python3
"""Whole-module build (tier T2): link every accepted source's object in its place, scaffold the rest from the user's
own module, assemble the file, compare it with the retail module and count the bytes produced from source.

    python tools/lbpbuild.py [--module EBOOT.BIN] [--mode both|private|public] [--parallel 4] [--reuse-match]
                             [--out-dir DIR]

The design is docs/PLAN.md "Whole-module build (T2) design"; the counting rules are docs/COMPLETION.md. In short:

  1. INPUTS. The accepted ledger (data/accepted-ledger.jsonl, validated by tools/lbpproof.py) is the only list of
     sources. A source whose file no longer has its proof's SHA-256 is left out. tools/lbpmatch.py compiles and
     matches every proved source (LBPMATCH_BUILD_ROOT=build/whole/<module>/match, chunks that fit the Windows command
     line); a source counts only when it is EXACT again and its object (GCC's random-seed digits normalized,
     lbpproof.normalized_object) has the SHA-256 its proof records.
  2. OBJECTS. Each object is reduced to what its proof compared: the claimed code range (code inputs laid out as the
     isolated link laid them out, sliced to [start, end)) and the compared data (rodata=/data=/sdata=, placed
     .gnu.linkonce data, and the placed .bss/.sbss). Every symbol of a removed part becomes an absolute symbol at the
     address it had in the isolated link (globals renamed so they cannot clash), so each kept relocation resolves to
     the value the proof saw. One owner per byte: overlapping data (GCC's merged constants, shared library tables) is
     placed by the first proof in ledger order and the other copies are left out of the link.
  3. SCAFFOLDING. Every byte of a loaded section that no kept piece covers is a scaffolding tile cut from the retail
     module at build time (code: one tile per function of the boundary map; data: one per uncovered run), written as
     one generated relocatable object (scaffold.o, alignment 1, no relocations: the executable is static). The ELF
     header, program header, file padding, .shstrtab and the section header table are the container. Scaffolding and
     the container never count.
  4. LINK. link.ld (generated from the retail section headers) puts every tile at its retail offset of its retail
     output section, in address order, between __lbp_at_<addr> and __lbp_end_<addr> markers; the zero-initialised area
     is NOLOAD; everything else is discarded. syms.ld defines the undefined names no kept object defines, from
     symbols/<module>.txt and address names, as the matcher does. One psp-ld run (WSL) links it all.
  5. COMPARE. Every marker must sit where it was planned and every loaded section must equal the retail section. The
     file is assembled from the linked sections (at the retail file offsets) and the container; its SHA-256 is compared
     with the retail module's. provenance.json lists the whole file as runs [offset, length, kind, source]; T2 = bytes
     in source-code/source-data runs, reported only when the image is byte-identical (otherwise `t2: refused`).

Modes: `private` links every accepted source; `public` only those whose origin class the public tree publishes
(tools/lbppublish.py EXCLUDED_CLASSES are left to scaffolding, supplied from the user's executable). Outputs:
build/whole/<module>/<mode>/{obj/, scaffold.o, link.ld, syms.ld, linked.elf, linked.map, image.bin, report.json,
provenance.json} (gitignored: they hold retail-derived bytes). Nothing is written outside build/.
"""
from __future__ import annotations

import argparse
import bisect
import contextlib
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
import time
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpmatch as M  # noqa: E402
import lbpproof as P  # noqa: E402

ROOT = M.ROOT
SCHEMA = "lbp-decomp.build-report.v1"
CMDLINE_BUDGET = 24000          # characters of source paths per lbpmatch.py call (Windows: 32,767 per command line)
SHT_NULL, SHT_PROGBITS, SHT_SYMTAB, SHT_STRTAB, SHT_RELA, SHT_NOBITS, SHT_REL = 0, 1, 2, 3, 4, 8, 9
SHF_WRITE, SHF_ALLOC, SHF_EXECINSTR = 1, 2, 4
SHN_UNDEF, SHN_ABS, SHN_COMMON = 0, 0xFFF1, 0xFFF2
STB_LOCAL, STT_NOTYPE, STT_SECTION, STT_FILE = 0, 0, 3, 4
# what ld's default script (the isolated link) gathers into each output section, by the first matching rule
# (the same patterns as tools/lbppromote.py's independent check)
CODE_INPUT = re.compile(r"\.text|\.stub|\.text\..+|\.gnu\.linkonce\.t\..+")
EARLY_CODE = re.compile(r"\.text\.(?:unlikely|exit|startup|hot|sorted)(?:\..*)?|\.text\..*_unlikely")
DATA_INPUT = {"rodata": re.compile(r"\.rodata|\.rodata\..+|\.gnu\.linkonce\.r\..+"),
              "data": re.compile(r"\.data|\.data\..+|\.gnu\.linkonce\.d\..+"),
              "sdata": re.compile(r"\.sdata|\.sdata\..+|\.gnu\.linkonce\.s\..+")}
NOBITS_INPUT = {"bss": re.compile(r"\.bss|\.bss\..+|\.gnu\.linkonce\.b\..+"),
                "sbss": re.compile(r"\.sbss|\.sbss\..+|\.gnu\.linkonce\.sb\..+")}
LINKONCE_DATA = re.compile(r"\.gnu\.linkonce\.(?:b|sb|d|s|r)\.(?P<symbol>.+)")
KINDS = ("source-code", "source-data", "scaffold-code", "scaffold-data", "container")
EH = struct.Struct("<16sHHIIIIIHHHHHH")
SH = struct.Struct("<10I")
SYM = struct.Struct("<IIIBBH")


class Excluded(Exception):
    """A source that cannot be placed in the whole link (it then counts nothing; the reason is reported)."""


# --------------------------------------------------------------------------------------------------------------
# a small ELF32 little-endian reader and writer for relocatable objects

@dataclass
class Sec:
    name: str
    type: int
    flags: int
    addr: int
    size: int
    link: int
    info: int
    align: int
    entsize: int
    data: bytes | None              # None for SHT_NOBITS


@dataclass
class Obj:
    ehdr: list
    secs: list[Sec]

    @property
    def shstrndx(self) -> int:
        return self.ehdr[13]


def read_obj(b: bytes) -> Obj:
    if b[:4] != b"\x7fELF" or b[4] != 1 or b[5] != 1:
        raise Excluded("not a 32-bit little-endian ELF object")
    ehdr = list(EH.unpack_from(b, 0))
    shoff, shentsize, shnum, shstrndx = ehdr[6], ehdr[11], ehdr[12], ehdr[13]
    raw = [SH.unpack_from(b, shoff + i * shentsize) for i in range(shnum)]
    stroff = raw[shstrndx][4]
    secs = []
    for n, t, fl, addr, off, size, link, info, align, ent in raw:
        name = b[stroff + n:b.index(b"\0", stroff + n)].decode("latin-1")
        secs.append(Sec(name, t, fl, addr, size, link, info, align, ent, None if t == SHT_NOBITS else bytes(b[off:off + size])))
    return Obj(ehdr, secs)


def write_obj(obj: Obj) -> bytes:
    """Serialize: sections keep their order and indices; offsets, .shstrtab and the section header table are rebuilt."""
    names, name_off = bytearray(b"\0"), []
    for s in obj.secs:
        name_off.append(len(names) if s.name else 0)
        if s.name:
            names += s.name.encode("latin-1") + b"\0"
    obj.secs[obj.shstrndx].data = bytes(names)
    obj.secs[obj.shstrndx].size = len(names)
    out = bytearray(EH.size)
    offs = [0] * len(obj.secs)
    for i, s in enumerate(obj.secs):
        if i == 0:
            continue
        if s.type == SHT_NOBITS:
            offs[i] = len(out)
            continue
        out += b"\0" * (-len(out) % max(s.align, 1))
        offs[i] = len(out)
        out += s.data or b""
    out += b"\0" * (-len(out) % 4)
    shoff = len(out)
    for i, s in enumerate(obj.secs):
        out += SH.pack(name_off[i], s.type, s.flags, s.addr, offs[i], s.size, s.link, s.info, s.align, s.entsize)
    e = list(obj.ehdr)
    e[1] = 1                        # ET_REL
    e[4], e[5], e[6] = 0, 0, shoff  # e_entry, e_phoff, e_shoff
    e[9], e[10], e[11], e[12] = 0, 0, SH.size, len(obj.secs)
    out[:EH.size] = EH.pack(*e)
    return bytes(out)


def obj_symbols(obj: Obj) -> tuple[int, list[list], list[str]]:
    """(symtab index, [[st_name, value, size, info, other, shndx]], names)."""
    idx = next((i for i, s in enumerate(obj.secs) if s.type == SHT_SYMTAB), None)
    if idx is None:
        raise Excluded("object has no symbol table")
    data, strtab = obj.secs[idx].data, obj.secs[obj.secs[idx].link].data
    syms = [list(SYM.unpack_from(data, o)) for o in range(0, len(data), SYM.size)]
    names = [strtab[s[0]:strtab.index(b"\0", s[0])].decode("latin-1") for s in syms]
    return idx, syms, names


def rel_rows(sec: Sec) -> list[tuple[int, int]]:
    return [struct.unpack_from("<II", sec.data, o) for o in range(0, len(sec.data), 8)]


def layout(secs: list[tuple[int, Sec]], base: int) -> dict[int, int]:
    """{section index: address}: `secs` (file order) laid out from `base`, each at the next address aligned to its
    sh_addralign (ld's rule for one input file; lbpproof.Elf.layout)."""
    out, addr = {}, base
    for i, s in secs:
        a = max(s.align, 1)
        addr = (addr + a - 1) // a * a
        out[i] = addr
        addr += s.size
    return out


# --------------------------------------------------------------------------------------------------------------
# 1. analysing one proved object: where the isolated link put each part, what the proof claims

@dataclass
class Claim:
    kind: str                       # "code", "data" or "bss"
    addr: int
    size: int
    secs: list[int]                 # object section indices (code: one; data/bss: the inputs, in file order)
    key: str                        # header key ("text", "rodata", ...) or "linkonce"
    lo: int = 0                     # code: the part of the section kept, [lo, hi) section offsets
    hi: int = 0


@dataclass
class Analysis:
    path: str
    proof: dict
    obj: Obj
    iso: dict[int, int]             # section index -> address in the isolated link (sections the matcher placed)
    code: list[Claim]
    data: list[Claim]
    bss: list[Claim]
    common: dict[int, int] = field(default_factory=dict)   # symbol index -> isolated address (COMMON symbols)


def analyse(proof: dict, h: dict, obj_bytes: bytes, linked_syms: dict[str, list[int]] | None = None) -> Analysis:
    """Where the isolated link (tools/lbpmatch.py) put each section of the object, and the pieces the proof claims."""
    obj = read_obj(obj_bytes)
    _symidx, syms, names = obj_symbols(obj)
    start, end = h["start"], h["end"]
    if (P.unhx(proof["start"]), P.unhx(proof["end"])) != (start, end) or proof["symbol"] != h["symbol"]:
        raise Excluded("the header's range or symbol differs from the proof")
    secs = list(enumerate(obj.secs))
    if any(s.type == SHT_RELA for _i, s in secs):
        raise Excluded("RELA relocations (not produced by these compilers)")
    code = [(i, s) for i, s in secs if s.type == SHT_PROGBITS and CODE_INPUT.fullmatch(s.name)]
    early = [s.name for _i, s in secs if EARLY_CODE.fullmatch(s.name)]
    if not code or early:
        raise Excluded("no code section" if not code else f"code sections the isolated layout does not cover: {early}")
    code_idx = {i for i, _s in code}
    iso: dict[int, int] = {}
    helpers = h.get("helpers") or []
    if helpers:
        # tools/lbpmatch.py placed every function of the file in its own section at its own address; only the target's
        # bytes are this proof's (each helper counts through its own proof), the helpers' sections are removed
        for name, fstart, _fend in M.placed_functions(h):
            hit = [s for s, n in zip(syms, names) if n == name and s[5] in code_idx]
            if len(hit) != 1 or hit[0][1] != 0:
                raise Excluded(f"helpers=: {name} is not alone at the start of one code section")
            iso[hit[0][5]] = fstart
        if any(s.size and i not in iso for i, s in code):
            raise Excluded("helpers=: a code section that the header does not place")
    else:
        # lbpmatch: -Ttext=start - (offset of the symbol in the first .text), code inputs in file order from there
        first_text = next((i for i, s in secs if s.name == ".text"), -1)
        text_off = next((s[1] for s, n in zip(syms, names) if n == h["symbol"] and s[5] == first_text), 0)
        iso = layout(code, start - text_off)
    target = [s for s, n in zip(syms, names) if n == h["symbol"] and s[5] in code_idx]
    if len(target) != 1 or iso[target[0][5]] + target[0][1] != start:
        raise Excluded(f"{h['symbol']} is not laid out at its retail address 0x{start:08x}")
    claims_code = []
    for i, s in code:
        a = iso[i]
        lo, hi = max(a, start), min(a + s.size, end)
        if lo < hi and (not helpers or i == target[0][5]):
            claims_code.append(Claim("code", lo, hi - lo, [i], "text", lo - a, hi - a))
    covered = sum(c.size for c in claims_code)
    if not claims_code or claims_code[0].addr != start or claims_code[-1].addr + claims_code[-1].size != end:
        raise Excluded("the claimed range is not inside the object's code")
    if covered != end - start:
        # alignment fill between two code inputs inside the claim: bytes no object section holds
        raise Excluded(f"{end - start - covered} bytes of the claim are linker fill between code sections")
    compared = proof["compared"]
    if set(k for k in compared if k.startswith(".text")) != {".text"} and not helpers:
        raise Excluded("the proof compared code this build does not lay out")
    # placed linkonce data objects (lbpmatch renames each to .lbp_loN and puts it at its symbol-map address)
    placed_lo = {sym: P.unhx(addr) for sym, addr in proof.get("deps", {}).get("placed_symbols") or []}
    lo_secs: dict[int, int] = {}
    for i, s in secs:
        m = LINKONCE_DATA.fullmatch(s.name)
        if m and m["symbol"] in placed_lo and s.size:
            lo_secs[i] = placed_lo[m["symbol"]]
    data, bss = [], []
    for key, pat in DATA_INPUT.items():
        if key not in h or not any(s.size for _i, s in secs if s.name == "." + key and s.type == SHT_PROGBITS):
            continue
        inputs = [(i, s) for i, s in secs if s.type == SHT_PROGBITS and pat.fullmatch(s.name) and i not in lo_secs]
        addr = int(h[key], 16)
        lay = layout(inputs, addr)
        iso.update(lay)
        size = max(lay[i] + s.size for i, s in inputs) - addr
        want = compared.get("." + key)
        if not want or (P.unhx(want["addr"]), want["size"]) != (addr, size):
            raise Excluded(f".{key}: the layout (0x{addr:08x}+{size}) differs from what the proof compared")
        data.append(Claim("data", addr, size, [i for i, _s in inputs], key))
    for i, addr in sorted(lo_secs.items()):
        s = obj.secs[i]
        iso[i] = addr
        if s.type == SHT_NOBITS:
            bss.append(Claim("bss", addr, s.size, [i], "linkonce"))
            continue
        want = compared.get(f"linkonce:{s.name}")
        if not want or (P.unhx(want["addr"]), want["size"]) != (addr, s.size):
            raise Excluded(f"{s.name}: the proof did not compare it at 0x{addr:08x}")
        data.append(Claim("data", addr, s.size, [i], "linkonce"))
    for key, pat in NOBITS_INPUT.items():
        if key not in h or not any(s.size for _i, s in secs if s.name == "." + key and s.type == SHT_NOBITS):
            continue
        inputs = [(i, s) for i, s in secs if s.type == SHT_NOBITS and pat.fullmatch(s.name) and i not in lo_secs]
        addr = int(h[key], 16)
        lay = layout(inputs, addr)
        iso.update(lay)
        bss.append(Claim("bss", addr, max(lay[i] + s.size for i, s in inputs) - addr, [i for i, _s in inputs], key))
    extra = {k for k in compared if not k.startswith(".text")} - {"." + c.key for c in data if c.key != "linkonce"} \
        - {f"linkonce:{obj.secs[c.secs[0]].name}" for c in data if c.key == "linkonce"}
    if extra:
        raise Excluded(f"the proof compared sections this build does not place: {sorted(extra)}")
    an = Analysis(proof["source"], proof, obj, iso, claims_code, data, bss)
    for k, s in enumerate(syms):
        if s[5] == SHN_COMMON and linked_syms is not None and len(linked_syms.get(names[k], [])) == 1:
            an.common[k] = linked_syms[names[k]][0]
    if linked_syms is not None:
        check_isolated(an, syms, names, linked_syms)
    return an


def check_isolated(an: Analysis, syms: list[list], names: list[str], linked: dict[str, list[int]]) -> None:
    """Every named symbol of a section the layout places is where the isolated link (its linked.elf) put it."""
    for s, n in zip(syms, names):
        if n and s[5] in an.iso and s[3] & 15 not in (STT_SECTION, STT_FILE) and len(linked.get(n, [])) == 1:
            if linked[n][0] != an.iso[s[5]] + s[1]:
                raise Excluded(f"{n}: the computed isolated layout (0x{an.iso[s[5]] + s[1]:08x}) disagrees with the "
                               f"matcher's link (0x{linked[n][0]:08x})")


# --------------------------------------------------------------------------------------------------------------
# 2. one owner per byte for data; then the reduced object

def compared_sha(a: Analysis, c: Claim) -> str:
    key = "." + c.key if c.key != "linkonce" else f"linkonce:{a.obj.secs[c.secs[0]].name}"
    return (a.proof["compared"].get(key) or {}).get("sha256", "")


def choose_data(analyses: list[Analysis], fits=None) -> tuple[dict[str, set[tuple[str, int]]], list[dict]]:
    """{path: {(kind, index)} of its data/bss claims that are linked}, [left-out claim rows]. A claim is linked when it
    lies inside a section of the module (`fits(addr, size, kind)`) and overlaps no claim linked before it (ledger
    order: one owner per byte); a copy left out keeps its references, which resolve to the address the kept one fills."""
    kept: dict[str, set[tuple[str, int]]] = {a.path: set() for a in analyses}
    dropped = []
    for kind in ("data", "bss"):
        taken: list[tuple[int, int, str, str]] = []      # sorted (start, end, path, sha) of linked claims
        for a in analyses:
            for n, c in enumerate(a.data if kind == "data" else a.bss):
                row = {"path": a.path, "kind": kind, "key": c.key, "addr": f"0x{c.addr:08x}", "size": c.size}
                if fits is not None and not fits(c.addr, c.size, kind):
                    dropped.append(dict(row, reason="outside the module's sections"))
                    continue
                k = bisect.bisect_left(taken, (c.addr + c.size,))
                hit = taken[k - 1] if k and taken[k - 1][1] > c.addr else None
                sha = compared_sha(a, c) if kind == "data" else ""
                if hit is None:
                    bisect.insort(taken, (c.addr, c.addr + c.size, a.path, sha))
                    kept[a.path].add((kind, n))
                    continue
                same = hit[0] == c.addr and hit[1] == c.addr + c.size and sha == hit[3]
                dropped.append(dict(row, reason="overlaps a claim placed before it", kept_by=hit[2],
                                    identical_copy=same))
    return kept, dropped


@dataclass
class Prepared:
    path: str
    uid: str
    start: int
    end: int
    pieces: list[tuple[str, int, int, str]]       # (section name in the object, address, size, kind code/data/bss)
    defined: dict[str, int]                        # global names the kept parts define -> address
    referenced: set[str]                           # undefined names that kept relocations use
    absolutes: int = 0                             # symbols of removed parts turned absolute
    code_referenced: set[str] = field(default_factory=set)   # the part of `referenced` kept code uses


def reduce_object(an: Analysis, uid: str, keep: set[tuple[str, int]]) -> tuple[bytes, Prepared]:
    """The object reduced to its claimed code and its linked data claims, renamed .lbp.*; every symbol of a removed
    part becomes absolute at its isolated address (a global under a unique name). Raises Excluded when a kept
    relocation refers to a part whose isolated address is unknown."""
    obj = an.obj
    symidx, syms, names = obj_symbols(obj)
    strtab = bytearray(obj.secs[obj.secs[symidx].link].data)
    rename: dict[int, str] = {}
    sliced: dict[int, tuple[int, int]] = {}
    pieces: list[tuple[str, int, int, str]] = []
    for n, c in enumerate(an.code):
        i = c.secs[0]
        rename[i] = f".lbp.text.{n}"
        if (c.lo, c.hi) != (0, obj.secs[i].size):
            sliced[i] = (c.lo, c.hi)
        pieces.append((rename[i], c.addr, c.size, "code"))
    for n, c in enumerate(an.data):
        if ("data", n) in keep:
            name = f".lbp.{c.key}" if c.key != "linkonce" else f".lbp.lo.{n}"
            for i in c.secs:
                rename[i] = name
            pieces.append((name, c.addr, c.size, "data"))
    for n, c in enumerate(an.bss):
        if ("bss", n) in keep:
            name = f".lbp.{c.key}" if c.key != "linkonce" else f".lbp.lob.{n}"
            for i in c.secs:
                rename[i] = name
            pieces.append((name, c.addr, c.size, "bss"))
    kept = set(rename)
    rels = [i for i, s in enumerate(obj.secs) if s.type == SHT_REL and s.info in kept]
    order = [0] + sorted(kept) + rels + [symidx, obj.secs[symidx].link, obj.shstrndx]
    order = list(dict.fromkeys(order))
    new_of = {old: new for new, old in enumerate(order)}
    secs: list[Sec] = []
    for old in order:
        s = obj.secs[old]
        c = Sec(s.name, s.type, s.flags, 0, s.size, s.link, s.info, s.align, s.entsize, s.data)
        if old in rename:
            c.name = rename[old]
            if old in sliced:
                lo, hi = sliced[old]
                c.data, c.size, c.align = s.data[lo:hi], hi - lo, 1
        elif s.type == SHT_REL:
            c.link, c.info = new_of[s.link], new_of[s.info]
            if s.info in sliced:
                lo, hi = sliced[s.info]
                c.data = b"".join(struct.pack("<II", off - lo, info) for off, info in rel_rows(s) if lo <= off < hi)
                c.size = len(c.data)
        elif old == symidx:
            c.link = new_of[s.link]
        secs.append(c)
    # symbols
    unknown: set[int] = set()
    defined: dict[str, int] = {}
    absolutes = 0
    out = []
    for k, sy in enumerate(syms):
        sy = list(sy)
        shndx, bind, typ = sy[5], sy[3] >> 4, sy[3] & 15
        inside = shndx in kept and (shndx not in sliced or (typ != STT_SECTION and sliced[shndx][0] <= sy[1] < sliced[shndx][1]))
        if k == 0 or shndx == SHN_UNDEF or shndx == SHN_ABS:
            pass
        elif inside:
            if shndx in sliced:
                sy[1] -= sliced[shndx][0]
            base = next(p[1] for p in pieces if p[0] == rename[shndx]) if shndx in sliced else None
            sy[5] = new_of[shndx]
            if bind != STB_LOCAL and names[k] and typ != STT_SECTION:
                if base is not None:
                    defined[names[k]] = base + sy[1]
                else:
                    defined[names[k]] = an.iso[shndx] + sy[1]
        else:
            # a removed part (or the section symbol of a sliced section): absolute at its isolated address
            if shndx == SHN_COMMON:
                addr = an.common.get(k)
            elif shndx in an.iso:
                addr = an.iso[shndx] + (0 if typ == STT_SECTION else sy[1])
            else:
                addr = None
            if addr is None:
                unknown.add(k)
                addr = 0
            if bind != STB_LOCAL:
                sy[0] = len(strtab)
                strtab += f"__lbp_x_{uid}_{k}".encode() + b"\0"
            sy[1], sy[2], sy[5] = addr, 0, SHN_ABS
            sy[3] = (bind << 4) | (STT_NOTYPE if typ in (STT_SECTION, STT_FILE) else typ)
            absolutes += 1
        out.append(sy)
    referenced: set[str] = set()
    code_referenced: set[str] = set()
    code_new = {new_of[c.secs[0]] for c in an.code}
    for s in secs:
        if s.type != SHT_REL:
            continue
        for off, info in rel_rows(s):
            k, rtype = info >> 8, info & 0xFF
            if rtype not in P.RELOC_FIELD:
                raise Excluded(f"relocation type {rtype} that this build does not check")
            if k in unknown:
                raise Excluded(f"a kept relocation refers to {names[k] or 'a section'} whose isolated address is unknown")
            if syms[k][5] == SHN_UNDEF and names[k]:
                referenced.add(names[k])
                if s.info in code_new:
                    code_referenced.add(names[k])
    secs[new_of[symidx]].data = b"".join(SYM.pack(*sy) for sy in out)
    strsec = secs[new_of[obj.secs[symidx].link]]
    strsec.data, strsec.size = bytes(strtab), len(strtab)
    ehdr = list(obj.ehdr)
    ehdr[13] = new_of[obj.shstrndx]
    return write_obj(Obj(ehdr, secs)), Prepared(an.path, uid, P.unhx(an.proof["start"]), P.unhx(an.proof["end"]),
                                                 pieces, defined, referenced, absolutes, code_referenced)


# --------------------------------------------------------------------------------------------------------------
# 3. the retail module, the tiles and the scaffolding

@dataclass
class RetailSec:
    name: str
    type: int
    flags: int
    addr: int
    off: int
    size: int


@dataclass
class Retail:
    data: bytes
    entry: int
    loaded: list[RetailSec]         # SHF_ALLOC PROGBITS sections with contents, in address order
    nobits: list[RetailSec]         # SHF_ALLOC NOBITS sections with a size


def retail_layout(data: bytes) -> Retail:
    e = P.Elf(data, "retail module")
    secs = [RetailSec(s.name, s.type, s.flags, s.addr, s.offset, s.size) for s in e.sections if s.flags & SHF_ALLOC and s.size]
    loaded = sorted((s for s in secs if s.type == SHT_PROGBITS), key=lambda s: s.addr)
    nobits = sorted((s for s in secs if s.type == SHT_NOBITS), key=lambda s: s.addr)
    if len(loaded) + len(nobits) != len(secs) or not loaded:
        raise SystemExit("the module has loaded sections that are neither PROGBITS nor NOBITS (not a static ELF this build knows)")
    entry, = struct.unpack_from("<I", data, 0x18)
    return Retail(data, entry, loaded, nobits)


@dataclass
class Tile:
    section: str
    start: int
    size: int
    kind: str                       # one of KINDS (bss pieces: "bss")
    uid: str                        # object file stem ("scaffold" for scaffolding)
    input: str                      # section name in that object
    source: str | None = None


def plan_tiles(retail: Retail, prepared: list[Prepared], func_starts: list[int], report: dict) -> list[Tile]:
    """Every byte of every loaded section in exactly one tile: a compiled piece, or scaffolding (code sections split at
    the boundary map's function starts). A source with a piece outside the loaded sections is left out."""
    def home(addr: int, size: int, kind: str) -> RetailSec | None:
        pool = retail.nobits if kind == "bss" else retail.loaded
        return next((s for s in pool if s.addr <= addr and addr + size <= s.addr + s.size), None)
    claims: list[tuple[int, int, str, Prepared, str]] = []
    for q in list(prepared):
        bad = next((p for p in q.pieces if home(p[1], p[2], p[3]) is None), None)
        if bad is not None:
            report["excluded"].append({"path": q.path, "reason": f"{bad[3]} piece 0x{bad[1]:08x}+{bad[2]} is outside "
                                                                 "the module's sections"})
            prepared.remove(q)
            continue
        claims += [(p[1], p[1] + p[2], p[3], q, p[0]) for p in q.pieces]
    claims.sort(key=lambda c: (c[2] == "bss", c[0]))
    tiles: list[Tile] = []
    for kind_bss in (False, True):
        mine = [c for c in claims if (c[2] == "bss") == kind_bss]
        for a, b in zip(mine, mine[1:]):
            if b[0] < a[1]:
                raise SystemExit(f"internal: pieces overlap: {a[3].path} 0x{a[0]:08x} / {b[3].path} 0x{b[0]:08x}")
    starts = sorted(set(func_starts))
    for s in retail.loaded:
        lo, hi = s.addr, s.addr + s.size
        inside = [c for c in claims if c[2] != "bss" and lo <= c[0] < hi]
        pos = lo
        for c in inside + [(hi, hi, "end", None, "")]:
            if c[0] > pos:      # scaffolding for [pos, c[0])
                cuts = [pos] + ([f for f in starts[bisect.bisect_right(starts, pos):bisect.bisect_left(starts, c[0])]]
                                if s.flags & SHF_EXECINSTR else []) + [c[0]]
                kind = "scaffold-code" if s.flags & SHF_EXECINSTR else "scaffold-data"
                tiles += [Tile(s.name, x, y - x, kind, "scaffold", f".lbp.s.{x:08x}") for x, y in zip(cuts, cuts[1:])]
            if c[3] is not None:
                tiles.append(Tile(s.name, c[0], c[1] - c[0], "source-code" if c[2] == "code" else "source-data",
                                  c[3].uid, c[4], c[3].path))
                pos = c[1]
    for s in retail.nobits:
        tiles += [Tile(s.name, c[0], c[1] - c[0], "bss", c[3].uid, c[4], c[3].path)
                  for c in claims if c[2] == "bss" and s.addr <= c[0] < s.addr + s.size]
    return tiles


def scaffold_object(retail: Retail, tiles: list[Tile], template_ehdr: list) -> bytes:
    """scaffold.o: one PROGBITS section per scaffolding tile (alignment 1) holding the retail bytes there, cut from the
    user's module at build time. No symbols, no relocations (the module is static)."""
    by_name = {s.name: s for s in retail.loaded}
    secs = [Sec("", SHT_NULL, 0, 0, 0, 0, 0, 0, 0, b"")]
    for t in tiles:
        if t.uid != "scaffold":
            continue
        s = by_name[t.section]
        o = s.off + t.start - s.addr
        secs.append(Sec(t.input, SHT_PROGBITS, s.flags & (SHF_WRITE | SHF_ALLOC | SHF_EXECINSTR), 0, t.size, 0, 0, 1, 0,
                        retail.data[o:o + t.size]))
    n = len(secs)
    secs.append(Sec(".symtab", SHT_SYMTAB, 0, 0, SYM.size, n + 1, 1, 4, SYM.size, SYM.pack(0, 0, 0, 0, 0, 0)))
    secs.append(Sec(".strtab", SHT_STRTAB, 0, 0, 1, 0, 0, 1, 0, b"\0"))
    secs.append(Sec(".shstrtab", SHT_STRTAB, 0, 0, 0, 0, 0, 1, 0, b""))
    ehdr = list(template_ehdr)
    ehdr[13] = n + 2
    return write_obj(Obj(ehdr, secs))


def link_script(retail: Retail, tiles: list[Tile], syms_path: str = "syms.ld") -> str:
    """link.ld: the retail output sections at their addresses in retail order; in each, every tile at its offset."""
    ld = ['OUTPUT_FORMAT("elf32-littlemips")', f'INCLUDE "{syms_path}"', "SECTIONS", "{"]
    by_sec: dict[str, list[Tile]] = {}
    for t in tiles:
        by_sec.setdefault(t.section, []).append(t)
    for s in sorted(retail.loaded + retail.nobits, key=lambda s: s.addr):
        ld.append(f"  {s.name} 0x{s.addr:08x}{' (NOLOAD)' if s.type == SHT_NOBITS else ''} :")
        ld.append("  {")
        for t in sorted(by_sec.get(s.name, []), key=lambda t: t.start):
            ld.append(f"    . = 0x{t.start - s.addr:x}; __lbp_at_{t.start:08x} = .; {t.uid}.o({t.input}) "
                      f"__lbp_end_{t.start:08x} = .;")
        ld.append(f"    . = 0x{s.size:x};")
        ld.append("  }")
    ld += ["  /DISCARD/ : { *(*) *(COMMON) }", "}"]
    return "\n".join(ld) + "\n"


def syms_script(prepared: list[Prepared], symmap: dict[str, int], report: dict) -> tuple[str, list[str]]:
    """syms.ld: every undefined name a kept relocation uses that no kept object defines, at its symbol-map address
    (or the address its name carries), as tools/lbpmatch.py defines it; a name with no address that only kept DATA
    uses gets the matcher's placeholder 0 (the proof compared that data with it). Returns (text, names that kept code
    uses and that have no address)."""
    code_used = set().union(*[q.code_referenced for q in prepared]) if prepared else set()
    placeholders = []
    defined: dict[str, tuple[int, str]] = {}
    for q in prepared:
        for n, a in q.defined.items():
            defined.setdefault(n, (a, q.path))
    lines, missing, differ = [], [], []
    for name in sorted(set().union(*[q.referenced for q in prepared]) if prepared else set()):
        addr = P.resolve(name, symmap)
        if name in defined:
            if addr is not None and addr != defined[name][0]:
                differ.append({"name": name, "map": f"0x{addr:08x}", "defined_at": f"0x{defined[name][0]:08x}",
                               "by": defined[name][1]})
            continue
        if addr is None and name not in code_used:
            placeholders.append(name)
            lines.append(f"{name} = 0x00000000;   /* not referenced by compared code: the matcher's placeholder */")
            continue
        if addr is None:
            missing.append(name)
            continue
        lines.append(f"{name} = 0x{addr:08x};")
    report["names_defined_by_objects_differing_from_the_map"] = differ
    report["placeholder_names"] = placeholders
    return "\n".join(lines) + "\n", missing


def duplicate_globals(prepared: list[Prepared], report: dict) -> list[Prepared]:
    """The prepared objects minus each one that defines a global name a kept object before it already defines (the
    whole link cannot hold both; the later source is left out and named)."""
    seen: dict[str, str] = {}
    out = []
    for q in prepared:
        dup = next((n for n in q.defined if n in seen), None)
        if dup is not None:
            report["excluded"].append({"path": q.path, "reason": f"defines {dup}, which {seen[dup]} defines too"})
            continue
        for n in q.defined:
            seen[n] = q.path
        out.append(q)
    return out


# --------------------------------------------------------------------------------------------------------------
# 4. link (WSL), 5. compare, assemble, provenance

def run_link(out: Path, entry: int) -> Path | None:
    pspdev = M.pspdev_bin()
    w = M.to_wsl(out)
    (out / "linked.elf").unlink(missing_ok=True)
    M.run_wsl([f"cd {w}/obj && {pspdev}/psp-ld -EL -nostdlib --no-warn-mismatch -e 0x{entry:08x} -T {w}/link.ld -Map {w}/linked.map "
               f"-o {w}/linked.elf @{w}/objs.rsp > {w}/link.log 2>&1"], "lbpbuild")
    return out / "linked.elf" if (out / "linked.elf").exists() else None


def container_parts(retail: Retail) -> list[tuple[int, int]]:
    """File ranges no loaded section occupies: the ELF header, program header, padding, .shstrtab, section headers."""
    taken = sorted((s.off, s.off + s.size) for s in retail.loaded)
    out, pos = [], 0
    for a, b in taken + [(len(retail.data), len(retail.data))]:
        if a > pos:
            out.append((pos, a))
        pos = max(pos, b)
    return out


def assemble(retail: Retail, linked: dict[str, tuple[int, bytes]]) -> bytes:
    """The module file from the parts: each loaded section's linked bytes at its retail file offset, the container
    (scaffolding) everywhere else. A section missing from the link or of another size leaves its range zero."""
    image = bytearray(len(retail.data))
    for a, b in container_parts(retail):
        image[a:b] = retail.data[a:b]
    for s in retail.loaded:
        got = linked.get(s.name)
        if got is not None and got[0] == s.addr and len(got[1]) == s.size:
            image[s.off:s.off + s.size] = got[1]
    return bytes(image)


def provenance(retail: Retail, tiles: list[Tile]) -> list[list]:
    """[file offset, length, kind, source] runs covering the whole file exactly once (adjacent equal runs merged)."""
    by_name = {s.name: s for s in retail.loaded}
    runs = [[a, b - a, "container", None] for a, b in container_parts(retail)]
    for t in tiles:
        if t.kind == "bss":
            continue
        s = by_name[t.section]
        runs.append([s.off + t.start - s.addr, t.size, t.kind, t.source])
    runs.sort()
    merged: list[list] = []
    for r in runs:
        if merged and merged[-1][0] + merged[-1][1] == r[0] and merged[-1][2:] == r[2:]:
            merged[-1][1] += r[1]
        else:
            merged.append(r)
    pos = 0
    for r in merged:
        if r[0] != pos:
            raise SystemExit(f"internal: provenance {'overlap' if r[0] < pos else 'gap'} at file offset 0x{pos:x}")
        pos += r[1]
    if pos != len(retail.data):
        raise SystemExit("internal: provenance does not end at the end of the file")
    return merged


def check_markers(tiles: list[Tile], linked_syms: dict[str, list[int]]) -> list[str]:
    bad = []
    for t in tiles:
        at, end = linked_syms.get(f"__lbp_at_{t.start:08x}"), linked_syms.get(f"__lbp_end_{t.start:08x}")
        if at != [t.start] or end != [t.start + t.size]:
            bad.append(f"0x{t.start:08x} ({t.source or t.kind}): linked at {at} .. {end}")
    return bad


def symbol_table(elf: P.Elf) -> dict[str, list[int]]:
    out: dict[str, list[int]] = {}
    for s in elf.symbols():
        if s.shndx != SHN_UNDEF and s.name:
            out.setdefault(s.name, []).append(s.value)
    return out


def figures_of(retail: Retail, runs: list[list], identical: bool, sections_equal: bool, markers_ok: bool) -> dict:
    by_kind = {k: 0 for k in KINDS}
    per_source: dict[str, int] = {}
    for _o, n, kind, src in runs:
        by_kind[kind] += n
        if src is not None:
            per_source[src] = per_source.get(src, 0) + n
    total = len(retail.data)
    src_bytes = by_kind["source-code"] + by_kind["source-data"]
    t2: dict | str
    if identical and sections_equal and markers_ok:
        t2 = {"bytes": src_bytes, "code_bytes": by_kind["source-code"], "data_bytes": by_kind["source-data"],
              "image_bytes": total, "percent_of_image": round(100.0 * src_bytes / total, 3)}
    else:
        t2 = "refused: the whole image is not byte-identical to the retail module" if not identical else \
             "refused: a section or a tile is not where the plan put it"
    return {"bytes_by_kind": by_kind, "t2": t2, "t2_source_bytes": dict(sorted(per_source.items())) if isinstance(t2, dict) else {}}


# --------------------------------------------------------------------------------------------------------------
# orchestration

def chunks(files: list[str], budget: int = CMDLINE_BUDGET) -> list[list[str]]:
    out: list[list[str]] = [[]]
    size = 0
    for f in files:
        if out[-1] and size + len(f) + 1 > budget:
            out.append([])
            size = 0
        out[-1].append(f)
        size += len(f) + 1
    return [c for c in out if c]


def run_match(paths: list[str], build_root: Path, parallel: int) -> dict[str, dict]:
    """tools/lbpmatch.py on `paths` with LBPMATCH_BUILD_ROOT=build_root; {source: row}. A call without a result is
    an error (its rows would otherwise be read from an earlier run's file)."""
    build_root.mkdir(parents=True, exist_ok=True)
    env = dict(os.environ, LBPMATCH_BUILD_ROOT=str(build_root))
    rows: list[dict] = []
    parts = chunks(paths)
    for k, part in enumerate(parts):
        out = build_root / f"isolation-{k}.json"
        out.unlink(missing_ok=True)
        done = subprocess.run([sys.executable, str(Path(M.__file__)), "--quiet", "--parallel", str(parallel), "--json",
                               str(out), *part], cwd=ROOT, env=env, stdout=subprocess.DEVNULL, stderr=subprocess.PIPE,
                              text=True)
        if not out.exists():
            raise SystemExit(f"lbpmatch wrote no result (exit {done.returncode}): {done.stderr.strip()[-2000:]}")
        rows += json.loads(out.read_text(encoding="utf-8"))
        print(f"  lbpmatch {k + 1}/{len(parts)}: {len(rows)} sources", flush=True)
    by = {Path(r["source"]).as_posix(): r for r in rows}     # lbpmatch names a relative path in the OS's form
    old = build_root / "isolation.json"
    merged = json.loads(old.read_text(encoding="utf-8")) if old.exists() else {}
    if isinstance(merged, list):
        merged = {Path(r["source"]).as_posix(): r for r in merged}
    merged.update(by)
    old.write_text(json.dumps(merged, indent=1) + "\n", encoding="utf-8")
    return by


def match_dir(build_root: Path, module: str, path: str) -> Path:
    p = ROOT / path
    return build_root / module / M.build_key(p)


@contextlib.contextmanager
def build_lock(path: Path, poll: float = 5.0):
    """One lbpbuild run per output directory at a time (the directory is rewritten by a run)."""
    path.parent.mkdir(parents=True, exist_ok=True)
    waited = False
    while True:
        try:
            path.mkdir()
            break
        except FileExistsError:
            if not waited:
                print(f"waiting for {path} (another lbpbuild run holds it)", flush=True)
                waited = True
            time.sleep(poll)
    try:
        (path / "owner.txt").write_text(f"pid {os.getpid()} since {time.strftime('%Y-%m-%d %H:%M:%S')}\n", encoding="utf-8")
        yield
    finally:
        for f in path.glob("*"):
            f.unlink(missing_ok=True)
        path.rmdir()


def unproved_sources(module: str, proofs: list[dict]) -> dict:
    """Sources under src/ for `module` that no accepted proof names: they are not built. Those whose range overlaps a
    proof's range (a second copy of a function, e.g. a library source and its FUN_ twin) are listed with the owner."""
    owned = sorted((P.unhx(p["start"]), P.unhx(p["end"]), p["source"]) for p in proofs)
    names = {p["source"] for p in proofs}
    starts = [o[0] for o in owned]
    count, shadowed = 0, []
    for f in sorted((ROOT / "src").rglob("*")):
        rel = f.relative_to(ROOT).as_posix()
        if f.suffix not in (".c", ".cpp") or rel in names:
            continue
        try:
            h = M.parse_header(f)
        except ValueError:
            continue
        if h["module"] != module:
            continue
        count += 1
        k = bisect.bisect_right(starts, h["start"]) - 1
        for o in owned[max(k, 0):k + 2]:
            if o[0] < h["end"] and h["start"] < o[1]:
                shadowed.append({"path": rel, "range": f"0x{h['start']:08x}-0x{h['end']:08x}", "owner": o[2]})
    return {"count": count, "sharing_a_proved_range": shadowed}


def public_classes() -> dict[str, str]:
    import lbporigin
    return lbporigin.classify(ROOT)[0]


def module_entry(module: str) -> dict:
    doc = json.loads((ROOT / "data" / "modules.json").read_text(encoding="utf-8"))
    return next(m for m in doc["modules"] if m["name"] == module)


def build(args: argparse.Namespace) -> int:
    t0 = time.time()
    module = args.module
    base = Path(args.out_dir) if args.out_dir else ROOT / "build" / "whole" / module
    led = P.load_ledger()
    proofs = P.accepted_proofs(module, led)
    if not proofs:
        raise SystemExit(f"no accepted proofs for {module}")
    entry = module_entry(module)
    data, _seg = M.module_bytes({}, module)
    retail_sha = hashlib.sha256(data).hexdigest()
    if retail_sha != entry["sha256"] or len(data) != entry["size"]:
        raise SystemExit(f"the campaign's {module} is not the module data/modules.json records")
    retail = retail_layout(data)
    func_starts = [s for s, _e in P.read_functions_file(ROOT / entry["functions_file"])]
    print(f"{module}: {len(proofs)} accepted proofs; ledger {led.header['body_sha256'][:16]} (journal "
          f"{led.header['journal_seq']}); retail sha256 {retail_sha[:16]}", flush=True)
    # 1. the tree must still hold the proved sources; the matcher compiles and matches every one
    stale, current = [], []
    for p in proofs:
        f = ROOT / p["source"]
        if not f.is_file() or P.file_sha256(f) != p["source_sha256"]:
            stale.append({"path": p["source"], "reason": "the source differs from its proof (or is missing)"})
        else:
            current.append(p)
    match_root = base / "match"
    rows = {}
    if args.reuse_match and (match_root / "isolation.json").exists():
        rows = json.loads((match_root / "isolation.json").read_text(encoding="utf-8"))
        if isinstance(rows, list):
            rows = {Path(r["source"]).as_posix(): r for r in rows}
    todo = [p["source"] for p in current if p["source"] not in rows
            or not (match_dir(match_root, module, p["source"]) / "obj.o").exists()]
    if todo:
        print(f"  compiling and matching {len(todo)} sources with tools/lbpmatch.py (--parallel {args.parallel})", flush=True)
        rows.update(run_match(todo, match_root, args.parallel))
    analyses: list[Analysis] = []
    excluded = list(stale)
    template = None
    for p in current:
        row = rows.get(p["source"])
        d = match_dir(match_root, module, p["source"])
        if row is None or row["status"] != "EXACT":
            excluded.append({"path": p["source"], "reason": f"not EXACT in the matcher ({row['status'] if row else 'no result'})"})
            continue
        try:
            obj = (d / "obj.o").read_bytes()
            if P.sha256(P.normalized_object(obj)) != p["object_sha256"]:
                raise Excluded("the compiled object is not the one its proof records")
            linked = symbol_table(P.Elf((d / "linked.elf").read_bytes(), "isolated link"))
            an = analyse(p, M.parse_header(ROOT / p["source"]), obj, linked)
        except (Excluded, P.ProofError, OSError) as exc:
            excluded.append({"path": p["source"], "reason": str(exc)})
            continue
        if template is None:
            template = list(an.obj.ehdr)
        analyses.append(an)
    print(f"  {len(analyses)} objects analysed, {len(excluded)} sources left out", flush=True)
    unproved = unproved_sources(module, proofs)
    symmap = P.symbol_map(module)
    modes = ("private", "public") if args.mode == "both" else (args.mode,)
    classes = public_classes() if "public" in modes else {}
    import lbppublish
    status = 0
    for mode in modes:
        chosen = analyses if mode == "private" else \
            [a for a in analyses if classes.get(a.path) not in lbppublish.EXCLUDED_CLASSES and a.path in classes]
        held = [a.path for a in analyses if a not in chosen]
        rep = link_mode(mode, module, base / mode, retail, chosen, excluded, held, template, func_starts, symmap, led,
                        retail_sha, rows)
        rep["unproved_sources"] = unproved
        rep["seconds"] = round(time.time() - t0, 1)
        (base / mode / "report.json").write_text(json.dumps(rep, indent=1) + "\n", encoding="utf-8")
        t2 = rep["t2"]
        print(f"  [{mode}] image {'IDENTICAL' if rep['identical'] else 'DIFFERS'} (sha256 {rep['image_sha256'][:16]} vs "
              f"retail {retail_sha[:16]}); T2 " + (f"{t2['bytes']:,} B = {t2['percent_of_image']}% of the image "
                                                   f"({t2['code_bytes']:,} code, {t2['data_bytes']:,} data)"
                                                   if isinstance(t2, dict) else t2), flush=True)
        print(f"  [{mode}] report: {(base / mode / 'report.json').as_posix()}", flush=True)
        status |= 0 if rep["identical"] else 1
    return status


def link_mode(mode: str, module: str, out: Path, retail: Retail, analyses: list[Analysis], excluded: list[dict],
              held: list[str], template: list, func_starts: list[int], symmap: dict, led, retail_sha: str,
              rows: dict) -> dict:
    with build_lock(out.parent / f"{mode}.lock"):
        return link_mode_locked(mode, module, out, retail, analyses, excluded, held, template, func_starts, symmap, led,
                                retail_sha, rows)


def link_mode_locked(mode: str, module: str, out: Path, retail: Retail, analyses: list[Analysis], excluded: list[dict],
                     held: list[str], template: list, func_starts: list[int], symmap: dict, led, retail_sha: str,
                     rows: dict) -> dict:
    if out.exists():
        for f in sorted(out.rglob("*"), reverse=True):
            f.unlink() if f.is_file() else f.rmdir()
    (out / "obj").mkdir(parents=True)
    report: dict = {"schema": SCHEMA, "module": module, "mode": mode,
                    "ledger": {"body_sha256": led.header["body_sha256"], "journal_seq": led.header["journal_seq"],
                               "count": led.header["count"], "toolchain": led.header["toolchain"],
                               "target": led.header["target"]},
                    "retail_sha256": retail_sha, "excluded": list(excluded), "held_back_for_public": len(held)}
    def fits(addr: int, size: int, kind: str) -> bool:
        pool = retail.nobits if kind == "bss" else retail.loaded
        return any(s.addr <= addr and addr + size <= s.addr + s.size for s in pool)
    keep, dropped = choose_data(analyses, fits)
    report["data_claims_left_out"] = dropped
    prepared: list[Prepared] = []
    for n, an in enumerate(analyses):
        uid = f"o{n:05d}"
        try:
            blob, q = reduce_object(an, uid, keep[an.path])
        except Excluded as exc:
            report["excluded"].append({"path": an.path, "reason": str(exc)})
            continue
        (out / "obj" / f"{uid}.o").write_bytes(blob)
        prepared.append(q)
    prepared = duplicate_globals(prepared, report)
    tiles = plan_tiles(retail, prepared, func_starts, report)
    (out / "obj" / "scaffold.o").write_bytes(scaffold_object(retail, tiles, template))
    syms, missing = syms_script(prepared, symmap, report)
    if missing:
        raise SystemExit(f"names with no address (the matcher would have refused them): {missing[:10]}")
    (out / "syms.ld").write_text(syms, encoding="utf-8", newline="\n")
    (out / "link.ld").write_text(link_script(retail, tiles, f"{M.to_wsl(out)}/syms.ld"), encoding="utf-8",
                                 newline="\n")
    (out / "objs.rsp").write_text("\n".join(["scaffold.o"] + [f"{q.uid}.o" for q in prepared]) + "\n", encoding="utf-8",
                                  newline="\n")
    print(f"  [{mode}] {len(prepared)} objects, {sum(t.uid == 'scaffold' for t in tiles):,} scaffolding tiles; linking",
          flush=True)
    elf_path = run_link(out, retail.entry)
    if elf_path is None:
        log = (out / "link.log").read_text(errors="replace")[-3000:] if (out / "link.log").exists() else ""
        raise SystemExit(f"the link failed:\n{log}")
    elf = P.Elf(elf_path.read_bytes(), "whole link")
    linked = {s.name: (s.addr, elf.contents(s)) for s in elf.sections if s.flags & SHF_ALLOC and s.type == SHT_PROGBITS}
    rows_out, equal_all = [], True
    for s in retail.loaded:
        got = linked.get(s.name)
        want = retail.data[s.off:s.off + s.size]
        eq = got is not None and got[0] == s.addr and got[1] == want
        equal_all &= eq
        row = {"name": s.name, "address": f"0x{s.addr:08x}", "size": s.size, "equal": eq}
        if not eq and got is not None:
            diff = next((i for i in range(min(len(got[1]), s.size)) if got[1][i] != want[i]), None)
            row.update(linked_address=f"0x{got[0]:08x}", linked_size=len(got[1]),
                       first_mismatch=None if diff is None else f"0x{s.addr + diff:08x}")
        rows_out.append(row)
    nob = {s.name: s for s in elf.sections if s.type == SHT_NOBITS and s.flags & SHF_ALLOC}
    for s in retail.nobits:
        got = nob.get(s.name)
        rows_out.append({"name": s.name, "address": f"0x{s.addr:08x}", "size": s.size, "nobits": True,
                         "equal": got is not None and (got.addr, got.size) == (s.addr, s.size)})
    bad_markers = check_markers(tiles, symbol_table(elf))
    image = assemble(retail, linked)
    (out / "image.bin").write_bytes(image)
    sha = hashlib.sha256(image).hexdigest()
    runs = provenance(retail, tiles)
    figs = figures_of(retail, runs, sha == retail_sha, equal_all, not bad_markers)
    by_path = {q.path: q for q in prepared}
    ranges: dict[str, list] = {}
    for t in tiles:
        if t.source is not None and t.kind != "bss":
            ranges.setdefault(t.source, []).append([f"0x{t.start:08x}", f"0x{t.start + t.size:08x}", t.kind])
    bss = {q.path: sum(p[2] for p in q.pieces if p[3] == "bss") for q in prepared if any(p[3] == "bss" for p in q.pieces)}
    log = (out / "link.log").read_text(errors="replace") if (out / "link.log").exists() else ""
    report.update(image_sha256=sha, identical=sha == retail_sha, image_bytes=len(image), sections=rows_out,
                  link_log=log.replace(M.pspdev_bin() + "/", "").strip().splitlines()[:20],
                  misplaced_tiles=bad_markers[:50], container_parts=[[a, b - a] for a, b in container_parts(retail)],
                  sources={"accepted": led.header["count"], "linked": len(prepared), "excluded": len(report["excluded"]),
                           "held_back_for_public": len(held)},
                  scaffolding={"tiles": sum(t.uid == "scaffold" for t in tiles),
                               "code_bytes": figs["bytes_by_kind"]["scaffold-code"],
                               "data_bytes": figs["bytes_by_kind"]["scaffold-data"],
                               "container_bytes": figs["bytes_by_kind"]["container"],
                               "note": "retail bytes cut from the user's module at build time: tier 0, never counted"},
                  absolute_symbols=sum(q.absolutes for q in prepared),
                  bss_placed_bytes=sum(bss.values()),
                  bytes_by_kind=figs["bytes_by_kind"], t2=figs["t2"], t2_source_bytes=figs["t2_source_bytes"],
                  t2_source_ranges=dict(sorted(ranges.items())) if isinstance(figs["t2"], dict) else {})
    (out / "provenance.json").write_text(json.dumps({"schema": "lbp-decomp.provenance.v1", "module": module, "mode": mode,
                                                     "image_sha256": sha, "kinds": list(KINDS), "runs": runs}) + "\n",
                                         encoding="utf-8")
    if bad_markers:
        print(f"  [{mode}] {len(bad_markers)} tiles not where planned, first: {bad_markers[:3]}")
    for r in rows_out:
        if not r["equal"]:
            print(f"  [{mode}] section differs: {r}")
    return report


def load_report(module: str, mode: str = "public", root: Path = ROOT) -> dict | str:
    """The build report of `module` in `mode` if it counts (the image identical, T2 reported, built from the current
    accepted ledger); otherwise the reason it does not."""
    path = root / "build" / "whole" / module / mode / "report.json"
    try:
        rep = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return "not measured (no whole-module build report: python tools/lbpbuild.py)"
    try:
        led = P.load_ledger(root / "data" / "accepted-ledger.jsonl", root / "data" / "accepted-journal.jsonl")
    except P.ProofError as exc:
        return f"not measured (the accepted ledger does not load: {exc})"
    if rep.get("schema") != SCHEMA or rep.get("mode") != mode or rep.get("module") != module:
        return "not measured (the build report is not a whole-module report of this module and mode)"
    if rep.get("ledger", {}).get("body_sha256") != led.header["body_sha256"]:
        return "not measured (the build report is stale: the accepted ledger changed since the build)"
    if not rep.get("identical") or not isinstance(rep.get("t2"), dict):
        return "not measured (the last whole-module build was not byte-identical)"
    return rep


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--module", default="EBOOT.BIN")
    ap.add_argument("--mode", choices=("both", "private", "public"), default="both")
    ap.add_argument("--parallel", type=int, default=4, help="concurrent compiles (at most 4 while other sessions compile)")
    ap.add_argument("--reuse-match", action="store_true",
                    help="reuse the matcher results and objects of an earlier run under build/whole/<module>/match "
                         "(each object is still checked against its proof); compile only what is missing")
    ap.add_argument("--out-dir", help="instead of build/whole/<module>")
    args = ap.parse_args()
    if args.parallel > 4:
        print("note: --parallel above 4 while other sessions compile breaks the shared-PC rule", file=sys.stderr)
    return build(args)


if __name__ == "__main__":
    raise SystemExit(main())
