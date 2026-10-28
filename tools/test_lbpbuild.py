#!/usr/bin/env python3
"""Tests for the whole-module build (lbpbuild.py): synthetic objects and a synthetic module. No WSL, no toolchain, no
retail bytes."""
from __future__ import annotations

import json
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpbuild as B  # noqa: E402

GLOBAL, LOCAL = 1, 0
FUNC, OBJECT, SECTION, NOTYPE = 2, 1, 3, 0
R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_32 = 4, 5, 6, 2


def make_obj(sections: list[tuple], symbols: list[tuple], rels: dict[int, list[tuple[int, int, int]]]) -> bytes:
    """sections: (name, type, flags, align, data or NOBITS size), indices from 1; symbols: (name, value, size, bind,
    type, shndx), locals first; rels: {section index: [(offset, type, symbol index)]}."""
    secs = [B.Sec("", B.SHT_NULL, 0, 0, 0, 0, 0, 0, 0, b"")]
    for name, typ, flags, align, data in sections:
        nobits = typ == B.SHT_NOBITS
        secs.append(B.Sec(name, typ, flags, 0, data if nobits else len(data), 0, 0, align, 0, None if nobits else data))
    symtab = len(secs) + len(rels)
    for target, rows in rels.items():
        blob = b"".join(struct.pack("<II", off, (sym << 8) | t) for off, t, sym in rows)
        secs.append(B.Sec(".rel" + secs[target].name, B.SHT_REL, 0, 0, len(blob), symtab, target, 4, 8, blob))
    strtab = bytearray(b"\0")
    blob = b""
    for name, value, size, bind, typ, shndx in [("", 0, 0, 0, 0, 0)] + symbols:
        off = 0
        if name:
            off = len(strtab)
            strtab += name.encode() + b"\0"
        blob += B.SYM.pack(off, value, size, (bind << 4) | typ, 0, shndx)
    first_global = 1 + sum(1 for s in symbols if s[3] == LOCAL)
    secs.append(B.Sec(".symtab", B.SHT_SYMTAB, 0, 0, len(blob), symtab + 1, first_global, 4, 16, blob))
    secs.append(B.Sec(".strtab", B.SHT_STRTAB, 0, 0, len(strtab), 0, 0, 1, 0, bytes(strtab)))
    secs.append(B.Sec(".shstrtab", B.SHT_STRTAB, 0, 0, 0, 0, 0, 1, 0, b""))
    ehdr = [b"\x7fELF\x01\x01\x01" + bytes(9), 1, 8, 1, 0, 0, 0, 0x10A23001, 52, 0, 0, 40, len(secs), len(secs) - 1]
    return B.write_obj(B.Obj(ehdr, secs))


def words(*ws: int) -> bytes:
    return b"".join(struct.pack("<I", w) for w in ws)


AX, A, WA = B.SHF_ALLOC | B.SHF_EXECINSTR, B.SHF_ALLOC, B.SHF_ALLOC | B.SHF_WRITE
# .text: f_other (0x00..0x10) then the target FUN_00001010 (0x10..0x20); .rodata 8 bytes; .bss 4 bytes
TEXT = words(0x0C000000, 0, 0x03E00008, 0, 0x0C000000, 0x3C040000, 0x24840000, 0x03E00008)
OBJ = make_obj(
    [(".text", B.SHT_PROGBITS, AX, 4, TEXT), (".rodata", B.SHT_PROGBITS, A, 4, b"\x01\x02\x03\x04\x05\x06\x07\x08"),
     (".bss", B.SHT_NOBITS, WA, 4, 4)],
    [("", 0, 0, LOCAL, SECTION, 1), ("", 0, 0, LOCAL, SECTION, 2), ("", 0, 0, LOCAL, SECTION, 3),
     ("f_other", 0, 0x10, GLOBAL, FUNC, 1), ("FUN_00001010", 0x10, 0x10, GLOBAL, FUNC, 1),
     ("DAT_00002000", 0, 0, GLOBAL, NOTYPE, 0), ("ext_only_other", 0, 0, GLOBAL, NOTYPE, 0),
     ("g_counter", 0, 4, GLOBAL, OBJECT, 3)],
    {1: [(0x0, R_MIPS_26, 7), (0x10, R_MIPS_26, 1), (0x14, R_MIPS_HI16, 6), (0x18, R_MIPS_LO16, 6)]})
HEADER = {"module": "EBOOT.BIN", "start": 0x1010, "end": 0x1020, "symbol": "FUN_00001010", "rodata": "0x00003000",
          "bss": "0x00005000"}
PROOF = {"source": "src/eboot/x.c", "module": "EBOOT.BIN", "start": "0x00001010", "end": "0x00001020",
         "symbol": "FUN_00001010", "deps": {},
         "compared": {".text": {"addr": "0x00001010", "size": 16, "sha256": "t"},
                      ".rodata": {"addr": "0x00003000", "size": 8, "sha256": "r"}}}


def sym_rows(blob: bytes) -> tuple[B.Obj, list[list], list[str]]:
    obj = B.read_obj(blob)
    _i, syms, names = B.obj_symbols(obj)
    return obj, syms, names


class ObjectTests(unittest.TestCase):
    def test_round_trip(self) -> None:
        obj = B.read_obj(OBJ)
        self.assertEqual([s.name for s in obj.secs][:4], ["", ".text", ".rodata", ".bss"])
        self.assertEqual(obj.secs[1].data, TEXT)
        self.assertEqual(B.write_obj(B.read_obj(OBJ)), B.write_obj(obj))

    def test_analyse_lays_out_like_the_isolated_link(self) -> None:
        an = B.analyse(PROOF, HEADER, OBJ, {"f_other": [0x1000], "FUN_00001010": [0x1010]})
        self.assertEqual(an.iso[1], 0x1000)                 # -Ttext = start - offset of the target
        self.assertEqual([(c.addr, c.size, c.lo, c.hi) for c in an.code], [(0x1010, 0x10, 0x10, 0x20)])
        self.assertEqual([(c.addr, c.size, c.key) for c in an.data], [(0x3000, 8, "rodata")])
        self.assertEqual([(c.addr, c.size, c.key) for c in an.bss], [(0x5000, 4, "bss")])

    def test_analyse_refuses_what_the_proof_did_not_compare(self) -> None:
        with self.assertRaises(B.Excluded):                  # the matcher's link put f_other elsewhere
            B.analyse(PROOF, HEADER, OBJ, {"f_other": [0x2000]})
        bad = dict(PROOF, compared={".text": PROOF["compared"][".text"],
                                    ".rodata": {"addr": "0x00003000", "size": 12, "sha256": "r"}})
        with self.assertRaises(B.Excluded):
            B.analyse(bad, HEADER, OBJ)
        with self.assertRaises(B.Excluded):                  # a claim outside the object's code
            B.analyse(dict(PROOF, end="0x00001030"), dict(HEADER, end=0x1030), OBJ)
        more = dict(PROOF, compared=dict(PROOF["compared"], **{".data": {"addr": "0x00004000", "size": 4}}))
        with self.assertRaises(B.Excluded):
            B.analyse(more, HEADER, OBJ)

    def test_reduce_keeps_the_claim_and_makes_removed_parts_absolute(self) -> None:
        an = B.analyse(PROOF, HEADER, OBJ)
        blob, q = B.reduce_object(an, "o00007", {("data", 0), ("bss", 0)})
        obj, syms, names = sym_rows(blob)
        by = {s.name: (i, s) for i, s in enumerate(obj.secs)}
        self.assertEqual(by[".lbp.text.0"][1].data, TEXT[0x10:0x20])
        self.assertEqual(by[".lbp.text.0"][1].align, 1)      # a slice
        self.assertIn(".lbp.rodata", by)
        self.assertIn(".lbp.bss", by)
        rel = next(s for s in obj.secs if s.type == B.SHT_REL)
        self.assertEqual(rel.info, by[".lbp.text.0"][0])
        self.assertEqual([off for off, _i in B.rel_rows(rel)], [0x0, 0x4, 0x8])   # rebased, f_other's row gone
        sym = {n: s for s, n in zip(syms, names) if n}
        self.assertEqual(sym["FUN_00001010"][1], 0)          # rebased into the slice
        self.assertEqual(sym["FUN_00001010"][5], by[".lbp.text.0"][0])
        self.assertEqual((sym["__lbp_x_o00007_4"][1], sym["__lbp_x_o00007_4"][5]), (0x1000, B.SHN_ABS))  # f_other
        self.assertEqual((syms[1][1], syms[1][5], syms[1][3]), (0x1000, B.SHN_ABS, 0))  # .text section symbol, local
        self.assertEqual(q.defined, {"FUN_00001010": 0x1010, "g_counter": 0x5000})
        self.assertEqual(q.referenced, {"DAT_00002000"})
        self.assertEqual(q.code_referenced, {"DAT_00002000"})
        self.assertEqual([(p[1], p[2], p[3]) for p in q.pieces], [(0x1010, 16, "code"), (0x3000, 8, "data"),
                                                                 (0x5000, 4, "bss")])

    def test_reduce_without_data_points_the_references_at_the_isolated_address(self) -> None:
        blob, q = B.reduce_object(B.analyse(PROOF, HEADER, OBJ), "o00001", set())
        obj, syms, names = sym_rows(blob)
        self.assertNotIn(".lbp.rodata", [s.name for s in obj.secs])
        self.assertEqual((syms[2][1], syms[2][5]), (0x3000, B.SHN_ABS))   # .rodata section symbol
        self.assertEqual((syms[3][1], syms[3][5]), (0x5000, B.SHN_ABS))   # .bss section symbol
        self.assertEqual(q.defined, {"FUN_00001010": 0x1010})
        self.assertEqual(len(q.pieces), 1)

    def test_reduce_refuses_a_kept_reference_to_an_unknown_place(self) -> None:
        obj = make_obj([(".text", B.SHT_PROGBITS, AX, 4, TEXT[:16]), (".data", B.SHT_PROGBITS, WA, 4, bytes(4))],
                       [("", 0, 0, LOCAL, SECTION, 2), ("FUN_00001000", 0, 16, GLOBAL, FUNC, 1)],
                       {1: [(0x4, R_MIPS_HI16, 1), (0x8, R_MIPS_LO16, 1)]})
        h = {"module": "EBOOT.BIN", "start": 0x1000, "end": 0x1010, "symbol": "FUN_00001000"}
        p = dict(PROOF, start="0x00001000", end="0x00001010", symbol="FUN_00001000",
                 compared={".text": {"addr": "0x00001000", "size": 16}})
        with self.assertRaises(B.Excluded):                  # .data is not placed: its address is unknown
            B.reduce_object(B.analyse(p, h, obj), "o00002", set())


def claim_an(path: str, data: list[tuple[int, int, str]]) -> B.Analysis:
    proof = {"compared": {f".k{n}": {"sha256": sha} for n, (_a, _s, sha) in enumerate(data)}}
    return B.Analysis(path, proof, None, {}, [], [B.Claim("data", a, s, [], f"k{n}") for n, (a, s, _h) in enumerate(data)], [])


class OwnershipTests(unittest.TestCase):
    def test_one_owner_per_data_byte(self) -> None:
        ans = [claim_an("a.c", [(0x3000, 4, "s1")]), claim_an("b.c", [(0x3000, 4, "s1")]),
               claim_an("c.c", [(0x3002, 4, "s2")]), claim_an("d.c", [(0x3004, 4, "s3"), (0x9000, 4, "s4")])]
        kept, dropped = B.choose_data(ans, lambda a, n, k: a < 0x8000)
        self.assertEqual(kept, {"a.c": {("data", 0)}, "b.c": set(), "c.c": set(), "d.c": {("data", 0)}})
        rows = {(r["path"], r["addr"]): r for r in dropped}
        self.assertTrue(rows[("b.c", "0x00003000")]["identical_copy"])
        self.assertEqual(rows[("b.c", "0x00003000")]["kept_by"], "a.c")
        self.assertFalse(rows[("c.c", "0x00003002")]["identical_copy"])
        self.assertEqual(rows[("d.c", "0x00009000")]["reason"], "outside the module's sections")

    def test_duplicate_globals_leave_the_later_source_out(self) -> None:
        q1 = B.Prepared("a.c", "o1", 0, 4, [], {"x": 1}, set())
        q2 = B.Prepared("b.c", "o2", 4, 8, [], {"x": 1, "y": 2}, set())
        rep = {"excluded": []}
        self.assertEqual([q.path for q in B.duplicate_globals([q1, q2], rep)], ["a.c"])
        self.assertIn("x", rep["excluded"][0]["reason"])

    def test_syms_script(self) -> None:
        q1 = B.Prepared("a.c", "o1", 0, 4, [], {"FUN_00001000": 0x1000}, {"DAT_00002000", "FUN_00001000", "only_data"},
                        code_referenced={"DAT_00002000", "FUN_00001000"})
        q2 = B.Prepared("b.c", "o2", 0, 4, [], {"named": 0x1100}, {"named"}, code_referenced={"named"})
        rep: dict = {}
        text, missing = B.syms_script([q1, q2], {"named": 0x1200}, rep)
        self.assertIn("DAT_00002000 = 0x00002000;", text)
        self.assertNotIn("FUN_00001000 =", text)              # a kept object defines it: the link resolves it
        self.assertIn("only_data = 0x00000000;", text)        # the matcher's placeholder (data only)
        self.assertEqual(missing, [])
        self.assertEqual(rep["names_defined_by_objects_differing_from_the_map"][0]["name"], "named")
        q3 = B.Prepared("c.c", "o3", 0, 4, [], {}, {"nowhere"}, code_referenced={"nowhere"})
        self.assertEqual(B.syms_script([q3], {}, {})[1], ["nowhere"])


def toy_retail() -> B.Retail:
    data = bytes(range(256))
    loaded = [B.RetailSec(".text", B.SHT_PROGBITS, AX, 0x1000, 0x10, 0x40),
              B.RetailSec(".rodata", B.SHT_PROGBITS, A, 0x1040, 0x50, 0x20)]
    return B.Retail(data, 0x1000, loaded, [B.RetailSec(".bss", B.SHT_NOBITS, WA, 0x1060, 0, 0x20)])


class LayoutTests(unittest.TestCase):
    def setUp(self) -> None:
        self.retail = toy_retail()
        self.q1 = B.Prepared("src/a.c", "o00000", 0x1010, 0x1020, [(".lbp.text.0", 0x1010, 0x10, "code")], {}, set())
        self.q2 = B.Prepared("src/b.c", "o00001", 0x1030, 0x1034, [(".lbp.rodata", 0x1048, 8, "data"),
                                                                   (".lbp.bss", 0x1064, 4, "bss")], {}, set())
        self.tiles = B.plan_tiles(self.retail, [self.q1, self.q2], [0x1000, 0x1010, 0x1020, 0x1030], {"excluded": []})

    def test_tiles_cover_every_byte_once(self) -> None:
        got = [(t.section, t.start, t.size, t.kind) for t in self.tiles]
        self.assertEqual(got, [(".text", 0x1000, 0x10, "scaffold-code"), (".text", 0x1010, 0x10, "source-code"),
                               (".text", 0x1020, 0x10, "scaffold-code"), (".text", 0x1030, 0x10, "scaffold-code"),
                               (".rodata", 0x1040, 8, "scaffold-data"), (".rodata", 0x1048, 8, "source-data"),
                               (".rodata", 0x1050, 0x10, "scaffold-data"), (".bss", 0x1064, 4, "bss")])

    def test_a_piece_outside_the_sections_leaves_its_source_out(self) -> None:
        q3 = B.Prepared("src/c.c", "o00002", 0x5000, 0x5004, [(".lbp.text.0", 0x5000, 4, "code")], {}, set())
        rep = {"excluded": []}
        prepared = [self.q1, q3]
        B.plan_tiles(self.retail, prepared, [], rep)
        self.assertEqual([q.path for q in prepared], ["src/a.c"])
        self.assertEqual(rep["excluded"][0]["path"], "src/c.c")

    def test_provenance_and_figures(self) -> None:
        runs = B.provenance(self.retail, self.tiles)
        self.assertEqual(runs[0], [0, 0x10, "container", None])
        self.assertEqual(runs[-1], [0x70, 0x90, "container", None])
        self.assertEqual(sum(r[1] for r in runs), 256)
        self.assertIn([0x20, 0x10, "source-code", "src/a.c"], runs)
        self.assertIn([0x30, 0x20, "scaffold-code", None], runs)     # two scaffolding tiles merged into one run
        f = B.figures_of(self.retail, runs, True, True, True)
        self.assertEqual((f["t2"]["bytes"], f["t2"]["code_bytes"], f["t2"]["data_bytes"]), (24, 16, 8))
        self.assertEqual(f["t2_source_bytes"], {"src/a.c": 16, "src/b.c": 8})
        self.assertEqual(f["bytes_by_kind"]["container"], 0x10 + 0x90)
        for args in ((False, True, True), (True, False, True), (True, True, False)):
            refused = B.figures_of(self.retail, runs, *args)
            self.assertIsInstance(refused["t2"], str)
            self.assertEqual(refused["t2_source_bytes"], {})

    def test_assemble_from_linked_sections_and_container(self) -> None:
        r = self.retail
        linked = {s.name: (s.addr, r.data[s.off:s.off + s.size]) for s in r.loaded}
        self.assertEqual(B.assemble(r, linked), r.data)
        linked[".rodata"] = (0x1044, linked[".rodata"][1])          # linked at another address: not used
        image = B.assemble(r, linked)
        self.assertNotEqual(image, r.data)
        self.assertEqual(image[0x50:0x70], bytes(0x20))

    def test_link_script_places_every_tile(self) -> None:
        ld = B.link_script(self.retail, self.tiles, "/x/syms.ld")
        self.assertIn('INCLUDE "/x/syms.ld"', ld)
        self.assertIn("  .text 0x00001000 :", ld)
        self.assertIn(". = 0x10; __lbp_at_00001010 = .; o00000.o(.lbp.text.0) __lbp_end_00001010 = .;", ld)
        self.assertIn(". = 0x0; __lbp_at_00001000 = .; scaffold.o(.lbp.s.00001000) __lbp_end_00001000 = .;", ld)
        self.assertIn("  .bss 0x00001060 (NOLOAD) :", ld)
        self.assertIn("o00001.o(.lbp.bss)", ld)
        self.assertLess(ld.index(".text 0x"), ld.index(".rodata 0x"))
        self.assertIn("/DISCARD/", ld)

    def test_markers(self) -> None:
        syms = {f"__lbp_at_{t.start:08x}": [t.start] for t in self.tiles}
        syms.update({f"__lbp_end_{t.start:08x}": [t.start + t.size] for t in self.tiles})
        self.assertEqual(B.check_markers(self.tiles, syms), [])
        syms["__lbp_end_00001010"] = [0x1024]
        self.assertEqual(len(B.check_markers(self.tiles, syms)), 1)

    def test_scaffold_object_holds_the_retail_bytes(self) -> None:
        obj = B.read_obj(B.scaffold_object(self.retail, self.tiles, B.read_obj(OBJ).ehdr))
        secs = {s.name: s for s in obj.secs}
        s = secs[".lbp.s.00001020"]
        self.assertEqual((s.data, s.align, s.flags), (self.retail.data[0x30:0x40], 1, AX))
        self.assertEqual(secs[".lbp.s.00001050"].flags, A)
        self.assertNotIn(".lbp.s.00001010", secs)                   # compiled tiles are not scaffolding
        self.assertEqual(sum(1 for n in secs if n.startswith(".lbp.s.")), 5)


class ReportTests(unittest.TestCase):
    def test_load_report_counts_only_an_identical_current_build(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            self.assertIn("no whole-module build", B.load_report("EBOOT.BIN", "public", root))
            path = root / "build" / "whole" / "EBOOT.BIN" / "public" / "report.json"
            path.parent.mkdir(parents=True)
            rep = {"schema": B.SCHEMA, "module": "EBOOT.BIN", "mode": "public", "ledger": {"body_sha256": "abc"},
                   "identical": True, "t2": {"bytes": 1}}
            path.write_text(json.dumps(rep), encoding="utf-8")
            with patch.object(B.P, "load_ledger", return_value=SimpleNamespace(header={"body_sha256": "abc"})):
                self.assertEqual(B.load_report("EBOOT.BIN", "public", root)["t2"], {"bytes": 1})
                self.assertIn("no whole-module build", B.load_report("EBOOT.BIN", "private", root))
                other = root / "build" / "whole" / "EBOOT.BIN" / "private" / "report.json"
                other.parent.mkdir(parents=True)
                other.write_text(json.dumps(rep), encoding="utf-8")       # a public report in the private place
                self.assertIn("not a whole-module report", B.load_report("EBOOT.BIN", "private", root))
            with patch.object(B.P, "load_ledger", return_value=SimpleNamespace(header={"body_sha256": "new"})):
                self.assertIn("stale", B.load_report("EBOOT.BIN", "public", root))
            path.write_text(json.dumps(dict(rep, identical=False, t2="refused: ...")), encoding="utf-8")
            with patch.object(B.P, "load_ledger", return_value=SimpleNamespace(header={"body_sha256": "abc"})):
                self.assertIn("not byte-identical", B.load_report("EBOOT.BIN", "public", root))

    def test_chunks_fit_the_command_line(self) -> None:
        parts = B.chunks(["x" * 9] * 10, budget=30)
        self.assertEqual([len(p) for p in parts], [3, 3, 3, 1])


if __name__ == "__main__":
    unittest.main()
