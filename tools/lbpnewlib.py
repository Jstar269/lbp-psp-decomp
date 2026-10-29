#!/usr/bin/env python3
"""Turn library identifications (try/lib-hits.json from lbplib.py) into exact sources.

    python tools/lbpnewlib.py --tag n1 [--limit N] [--parallel 6]
    python tools/lbpnewlib.py --regenerate [--tag r1] [--parallel 6] [FILE ...]

For each identified retail function: the library file is preprocessed (comments, i.e. the licence
headers, kept) with the build script's include paths into a self-contained C source whose header names
the library function and the GCC profile it was identified with. The compiler is run with -nostdinc: the
newlib include directories are searched first, then the project-authored include/ directory, which stands
in for the compiler's own freestanding headers (stddef.h, stdarg.h, float.h, limits.h). No compiler vendor
header text, and so no GPL text, ends up in a source. lbpmatch.py links the whole object so
that the function sits at its retail address. Names the object leaves undefined (other library functions,
globals) and its data sections are then located from retail's relocation sites INSIDE the identified
function only (jal targets, %hi/%lo pairs): undefined names are appended to symbols/<module>.txt with
that provenance, sections get rodata=/data=/bss= header keys. Only sources that end EXACT are installed
in src/, with a note naming the library file; everything else is reported.

--regenerate rebuilds installed library sources from the release, file and function their note records
(`Library source: newlib 1.14.0 libc_stdlib/abort.c function abort`), keeping each source's header line
and note line unchanged. Clones of library sources (`Clone of src/... (lbpclone.py tag X)` over a
`Library source:` note) are re-derived from their regenerated exemplar with lbpclone.py's own address
substitution. Every regenerated file is staged under try/lib-regen-<tag>/ and written over its source only
when lbpmatch.py reports EXACT for it; the others are reported with the staged path for diagnosis.
Files that are not library sources (and the hand-adapted kernel_rem_pio2f sources) are skipped.
"""
from __future__ import annotations

import argparse
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpconfig
import lbpmatch as M
import lbpproject as P

SRC_DIRS = P.src_dirs()  # {module: src/ subdirectory}, from data/modules.json
CFG = re.compile(r"(?P<ver>\d+\.\d+\.\d+)-(?P<gcc>\d+[a-z]?)-(?P<opt>O\w)")
R_26, R_HI16, R_LO16 = 4, 5, 6
SECTION_KEYS = {".rodata": "rodata", ".data": "data", ".bss": "bss", ".sdata": "sdata", ".sbss": "sbss"}


def wsl(cmd: str) -> subprocess.CompletedProcess:
    return subprocess.run(["wsl.exe", "-e", "sh", "-c", cmd], capture_output=True, text=True,
                          env={"MSYS_NO_PATHCONV": "1", **__import__("os").environ})


def preprocess_file(ver: str, gcc: str, rel_dir: str, base: str, out: Path) -> bool:
    """Preprocess newlib <ver> libc/libm file <rel_dir>/<base>.c (rel_dir like libc/stdlib) into `out`.

    -nostdinc keeps the compiler's own headers out: newlib's include directories are searched, then the
    project-authored include/ (copied to a native temporary directory first, because the i386 compiler
    cannot stat files on /mnt/c). -C keeps newlib's own comments, i.e. its licence notices."""
    newlib, gcc_home = lbpconfig.wsl_path("newlib_home"), M.gcc_home()
    src = f"{newlib}/{ver}/newlib-{ver}/newlib"
    b = (f"-B {gcc_home}/psp-gcc-1.7.1/lib/gcc-lib/psp/3.3.3+allegrex-2.2.2-psp-1.7.1/" if gcc == "171" else "")
    inc = M.to_wsl(M.ROOT / "include")
    cmd = (f"t=$(mktemp -d /tmp/lbppp.XXXXXX) && mkdir $t/inc && cp {inc}/*.h $t/inc/ && "
           f"{gcc_home}/psp-gcc-1.3.1/bin/psp-gcc {b} -E -C -P -G0 -nostdinc "
           f"-I{newlib}/inc-{ver} -I{src}/libc/include -I{src}/{rel_dir} -I{src}/libm/common -I$t/inc "
           f"{src}/{rel_dir}/{base}.c -o $t/pp.c 2>$t/err && cp $t/pp.c {M.to_wsl(out)}; r=$?; rm -rf $t; exit $r")
    return wsl(cmd).returncode == 0 and out.exists()


def preprocess(ver: str, gcc: str, obj_name: str, out: Path) -> bool:
    d, base = obj_name[:-2].split("__", 1)
    return preprocess_file(ver, gcc, d.replace("_", "/", 1), base, out)  # libc_stdio -> libc/stdio


def relocations(obj: bytes):
    """(.text index, [(offset, type, symbol name, symbol shndx, symbol value)]) for .text relocations."""
    sections = M.elf_sections(obj)
    names = [n for n, _ in sections]
    if ".text" not in names:
        return None, []
    ti = names.index(".text")
    symbols = list(M.elf_symbols(obj))
    rel = next((s for n, s in sections if s[1] == 9 and s[7] == ti), None)
    out = []
    if rel:
        for i in range(rel[5] // 8):
            off, info = struct.unpack_from("<II", obj, rel[4] + i * 8)
            name, value, size, sinfo, shndx = symbols[info >> 8]
            out.append((off, info & 0xFF, name, shndx, value))
    return ti, out


def infer(obj: bytes, symbol: str, start: int, end: int, data: bytes, seg: dict):
    """Addresses of undefined names and of the object's data sections, read from retail at relocation
    sites inside [start, end) of the identified function. None when retail disagrees with itself."""
    sections = M.elf_sections(obj)
    names = [n for n, _ in sections]
    ti, rels = relocations(obj)
    if ti is None:
        return None
    off_sym = next((v for n, v, s, i, sh in M.elf_symbols(obj) if n == symbol and sh == ti), None)
    if off_sym is None:
        return None
    text = sections[ti][1]
    base = start - off_sym  # retail address of the object's .text
    lo_bound, hi_bound = off_sym, off_sym + (end - start)

    def ours(o):
        return struct.unpack_from("<I", obj, text[4] + o)[0]

    def theirs(o):
        return struct.unpack_from("<I", data, seg["file_offset"] + base + o - seg["start"])[0]

    sext = lambda v: v - 0x10000 if v & 0x8000 else v  # noqa: E731
    found: dict[str, set] = {}
    pending = {}
    for off, rtype, name, shndx, value in rels:
        if not lo_bound <= off < hi_bound:
            continue
        key = name if shndx == 0 else (names[shndx] if 0 < shndx < len(names) else None)
        if key is None:
            continue
        if shndx != 0 and key in SECTION_KEYS:
            addend_base = value  # symbol value inside its section
        elif shndx == 0:
            addend_base = 0
        else:
            continue  # defined in .text: placed with the object
        if rtype == R_26:
            target = (theirs(off) & 0x3FFFFFF) << 2
            found.setdefault(key, set()).add(target - addend_base - ((ours(off) & 0x3FFFFFF) << 2))
        elif rtype == R_HI16:
            pending[key] = ((ours(off) & 0xFFFF) << 16, (theirs(off) & 0xFFFF) << 16)
        elif rtype == R_LO16 and key in pending:
            ohi, thi = pending.pop(key)
            addend = ohi + sext(ours(off) & 0xFFFF)
            found.setdefault(key, set()).add(thi + sext(theirs(off) & 0xFFFF) - addend - addend_base)
    if any(len(v) != 1 for v in found.values()):
        return None
    return {k: v.pop() for k, v in found.items()}


LIB_NOTE = re.compile(r"^/\* Library source: newlib (?P<ver>\d+\.\d+\.\d+) (?P<dir>\w+)/(?P<file>\w+)\.c "
                      r"function (?P<fn>\w+)")
CLONE_NOTE = re.compile(r"^/\* Clone of (?P<src>src/\S+) \(lbpclone\.py tag (?P<tag>\w+)\)")


def regenerate(paths: list[Path], tag: str, parallel: int) -> int:
    """Rebuild installed library sources (and their clones) from the upstream files their notes record."""
    import lbpclone as C
    work = M.ROOT / "try" / f"lib-regen-{tag}"
    if work.exists():
        raise SystemExit(f"{work} exists; use a new tag")
    (work / "pp").mkdir(parents=True)
    if not paths:
        paths = sorted(q for q in (M.ROOT / "src").rglob("*") if q.suffix == ".c")
    direct, clones = {}, {}
    for path in paths:
        lines = path.read_text(encoding="utf-8").split("\n", 3)
        if len(lines) < 4:
            continue
        if LIB_NOTE.match(lines[1]):
            direct[path.resolve()] = lines
        elif CLONE_NOTE.match(lines[1]) and LIB_NOTE.match(lines[2]):
            clones[path.resolve()] = lines
    print(f"library sources: {len(direct)} direct, {len(clones)} clones")
    staged: dict[Path, Path] = {}   # installed path -> staged path
    texts: dict[Path, str] = {}     # installed path -> regenerated text
    failed = []
    for path, lines in sorted(direct.items()):
        m, hdr = LIB_NOTE.match(lines[1]), M.parse_header(path)
        gcc = re.fullmatch(r"gcc(\d+)-\w+", hdr.get("cc", ""))
        if gcc is None:
            failed.append((path, "no gcc profile in the header"))
            continue
        pp = work / "pp" / path.name
        if not preprocess_file(m["ver"], gcc.group(1), m["dir"].replace("_", "/", 1), m["file"], pp):
            failed.append((path, "preprocessing failed"))
            continue
        texts[path] = lines[0] + "\n" + lines[1] + "\n" + pp.read_text(encoding="utf-8", errors="replace")
    cache: dict = {}

    def words_of(h: dict) -> list[int]:
        data, seg = M.module_bytes(cache, h["module"])
        off = seg["file_offset"] + h["start"] - seg["start"]
        return C.words(data[off:off + h["end"] - h["start"]])

    for path, lines in sorted(clones.items()):
        exemplar = (M.ROOT / CLONE_NOTE.match(lines[1])["src"]).resolve()
        if exemplar in direct and exemplar not in texts:
            failed.append((path, f"exemplar {exemplar.name} could not be regenerated"))
            continue
        if exemplar not in texts and exemplar in clones:
            failed.append((path, "exemplar is itself a clone"))
            continue
        etext = texts.get(exemplar) or exemplar.read_text(encoding="utf-8")
        eh, th = M.parse_header(exemplar), M.parse_header(path)
        if eh["module"] != th["module"]:
            etext = etext.replace(f"module={eh['module']}", f"module={th['module']}", 1)
        (esig, erefs), (tsig, trefs) = C.analyse(words_of(eh)), C.analyse(words_of(th))
        maps = C.mapping(erefs, trefs) if esig == tsig else None
        out = C.retarget(etext, eh["start"], th["start"], th["end"], *maps) if maps else None
        if out is None:
            failed.append((path, "address substitution failed"))
            continue
        head, rest = out.split("\n", 1)
        if head != lines[0]:
            failed.append((path, "substituted header differs from the installed header"))
            continue
        texts[path] = head + "\n" + lines[1] + "\n" + rest
    for path, text in texts.items():
        dest = work / f"regen_{path.parent.name}" / path.name
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_text(text, encoding="utf-8", newline="\n")
        staged[path] = dest
    rows: dict[str, dict] = {}
    if staged:
        part = work / "summary.json"
        subprocess.run([sys.executable, str(Path(M.__file__)), "--quiet", "--parallel", str(parallel),
                        "--json", str(part)] + [str(s) for s in staged.values()], stdout=subprocess.DEVNULL)
        if part.exists():
            rows = {str((M.ROOT / r["source"]).resolve()): r for r in json.loads(part.read_text(encoding="utf-8"))}
    installed = 0
    for path, dest in sorted(staged.items()):
        r = rows.get(str(dest.resolve()))
        if r and r["status"] == "EXACT":
            if path.read_text(encoding="utf-8") != texts[path]:
                path.write_text(texts[path], encoding="utf-8", newline="\n")
            installed += 1
        else:
            failed.append((path, f"{r['status'] if r else 'NOT_RUN'}: staged at {dest.relative_to(M.ROOT).as_posix()}"
                           + (f" ({r['detail']})" if r and r.get("detail") else "")))
    for path, why in failed:
        print(f"NOT REGENERATED {path.relative_to(M.ROOT).as_posix()}: {why}")
    print(json.dumps({"tag": tag, "direct": len(direct), "clones": len(clones), "exact": installed,
                      "failed": len(failed)}))
    return 0 if not failed else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--tag", help="name of this run's work directory (required unless --regenerate)")
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--parallel", type=int, default=6)
    ap.add_argument("--regenerate", action="store_true",
                    help="rebuild installed library sources and their clones from their notes (see above)")
    ap.add_argument("files", nargs="*", type=Path, help="with --regenerate: only these sources (default: all in src/)")
    args = ap.parse_args()
    if args.regenerate:
        return regenerate(args.files, args.tag or "regen", args.parallel)
    if not args.tag or args.files:
        ap.error("--tag is required (and files are only accepted with --regenerate)")
    work = M.ROOT / "try" / f"lib-{args.tag}"
    if work.exists():
        raise SystemExit(f"{work} exists; use a new tag")
    work.mkdir(parents=True)
    hits = json.loads((M.ROOT / "try" / "lib-hits.json").read_text(encoding="utf-8"))
    covered = {(M.parse_header(p)["module"], M.parse_header(p)["start"])
               for p in (M.ROOT / "src").rglob("*") if p.suffix in (".c", ".cpp")}
    jobs = []
    for h in hits:
        start, end = int(h["start"], 16), int(h["end"], 16)
        if (h["module"], start) in covered:
            continue
        cands = sorted(h["candidates"], key=lambda c: (c["config"][-2:] != "O2", c["function"]))
        names = sorted({c["function"] for c in cands})
        c = cands[0]
        m = CFG.fullmatch(c["config"])
        out = work / f"{c['function']}_{start:08x}.c"
        if not preprocess(m["ver"], m["gcc"], c["object"], out):
            print(f"PREPROCESS_FAILED {h['module']} {h['start']} {c['object']}")
            continue
        header = (f"/* LBPMATCH module={h['module']} start=0x{start:08x} end=0x{end:08x} symbol={c['function']} "
                  f"lang=c99 cc=gcc{m['gcc']}-{m['opt']} */\n")
        identity = (f"newlib {m['ver']} {c['object'][:-2].replace('__', '/')}.c function {c['function']}"
                    + (f" (identical code: {', '.join(names)})" if len(names) > 1 else ""))
        out.write_text(header + f"/* LIBRARY {identity} */\n" + out.read_text(encoding="utf-8", errors="replace"),
                       encoding="utf-8", newline="\n")
        jobs.append((h, c, out, identity))
        if args.limit and len(jobs) >= args.limit:
            break
    print(f"prepared {len(jobs)}")
    cmd = [sys.executable, str(Path(M.__file__)), "--quiet", "--parallel", str(args.parallel), "--json"]
    exact, added_syms = {}, []
    # inferred names stay in per-module pending maps (passed with --symbols-extra) until a source that
    # uses them is EXACT; a name inferred with two different addresses is dropped
    pending: dict[str, dict[str, int]] = {}
    origin: dict = {}
    conflicted: set = set()

    def pending_file(module: str) -> Path:
        path = work / f"pending-{module}.txt"
        path.write_text("".join(f"{n} = 0x{a:08x};\n" for n, a in sorted(pending.get(module, {}).items())),
                        encoding="utf-8", newline="\n")
        return path

    for rnd in range(4):
        todo = [j for j in jobs if str(j[2]) not in exact]
        if not todo:
            break
        rows = {}
        for module in sorted({j[0]["module"] for j in todo}):
            part = work / f"round{rnd}-{module}.json"
            files = [str(j[2]) for j in todo if j[0]["module"] == module]
            subprocess.run(cmd + [str(part), "--symbols-extra", str(pending_file(module))] + files,
                           stdout=subprocess.DEVNULL)
            if part.exists():
                rows.update({str((M.ROOT / r["source"]).resolve()): r
                             for r in json.loads(part.read_text(encoding="utf-8"))})
        changed = False
        for h, c, out, identity in todo:
            r = rows.get(str(out.resolve()))
            if r is None:
                continue
            if r["status"] == "EXACT":
                exact[str(out)] = (h, c, out, identity)
                continue
            if r["status"] not in ("MISSING_SYMBOLS", "UNPLACED_SECTION"):
                continue
            hdr = M.parse_header(out)
            build = M.ROOT / "build" / hdr["module"] / M.build_key(out)
            obj = (build / "obj.o").read_bytes() if (build / "obj.o").exists() else None
            if obj is None:
                continue
            data, seg = M.module_bytes({}, hdr["module"])
            got = infer(obj, hdr["symbol"], hdr["start"], hdr["end"], data, seg)
            if not got:
                continue
            text = out.read_text(encoding="utf-8")
            first, rest = text.split("\n", 1)
            syms = M.load_symbols(hdr["module"])
            mod_pending = pending.setdefault(hdr["module"], {})
            for key, addr in sorted(got.items()):
                if key in SECTION_KEYS:
                    if f"{SECTION_KEYS[key]}=" not in first:
                        first = first.replace(" */", f" {SECTION_KEYS[key]}=0x{addr:08x} */", 1)
                        changed = True
                elif key in syms or (hdr["module"], key) in conflicted:
                    continue
                elif key in mod_pending and mod_pending[key] != addr:
                    conflicted.add((hdr["module"], key))
                    del mod_pending[key]
                    changed = True
                elif key not in mod_pending:
                    mod_pending[key] = addr
                    origin.setdefault((hdr["module"], key), f"0x{hdr['start']:08x} ({hdr['symbol']})")
                    changed = True
            out.write_text(first + "\n" + rest, encoding="utf-8", newline="\n")
        if not changed:
            break
    # commit the pending names used by EXACT sources (their exact bytes prove the address)
    for h, c, out, identity in exact.values():
        hdr = M.parse_header(out)
        build = M.ROOT / "build" / hdr["module"] / M.build_key(out)
        obj = (build / "obj.o").read_bytes()
        used = {n for n, v, s, i, sh in M.elf_symbols(obj) if sh == 0 and n}
        syms = M.load_symbols(hdr["module"])
        new_lines = [f"{n} = 0x{pending[hdr['module']][n]:08x};   # newlib; address read from retail relocations "
                     f"in {origin[(hdr['module'], n)]}, confirmed by exact {hdr['symbol']} [{args.tag}]"
                     for n in sorted(used) if n in pending.get(hdr["module"], {}) and n not in syms]
        if new_lines:
            with (M.ROOT / "symbols" / f"{hdr['module']}.txt").open("a", encoding="utf-8", newline="\n") as fh:
                fh.write("\n".join(new_lines) + "\n")
            added_syms += new_lines
    written = 0
    for h, c, out, identity in exact.values():
        dest = M.ROOT / "src" / SRC_DIRS[h["module"]] / out.name
        if dest.exists() or (h["module"], int(h["start"], 16)) in covered:
            continue
        first, rest = out.read_text(encoding="utf-8").split("\n", 1)
        rest = re.sub(r"^/\* LIBRARY .*? \*/\n", "", rest, count=1)
        note = (f"/* Library source: {identity}, preprocessed (comments kept), identified by compiled-code "
                f"signature (lbplib.py) and built with the GCC profile in the header; exact match verified; "
                f"external names are newlib's, their addresses read from retail. */\n")
        dest.write_text(first + "\n" + note + rest, encoding="utf-8", newline="\n")
        written += 1
    print(json.dumps({"tag": args.tag, "prepared": len(jobs), "exact": len(exact), "written": written,
                      "symbols_added": len(added_syms)}))
    (work / "symbols-added.txt").write_text("\n".join(added_syms) + "\n", encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
