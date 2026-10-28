#!/usr/bin/env python3
"""Synthetic tests for the accepted ledger and proof verifier (lbpproof.py; ported from hst-decomp's test_hstproof.py).
No WSL, no toolchain, no retail bytes."""
from __future__ import annotations

import json
import struct
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import sys
sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpproof as P


class PrimitiveTests(unittest.TestCase):
    def test_canon_and_digest(self) -> None:
        obj = {"b": 2, "a": 1}
        self.assertEqual(P.canon(obj), b'{"a":1,"b":2}')
        self.assertEqual(P.digest(obj), P.sha256(b'{"a":1,"b":2}'))

    def test_hx_and_unhx(self) -> None:
        self.assertEqual(P.hx(0x1234abcd), "0x1234abcd")
        self.assertEqual(P.unhx("0x1234abcd"), 0x1234abcd)
        with self.assertRaises(P.ProofError) as cm:
            P.unhx("1234abcd")
        self.assertEqual(cm.exception.code, "ledger")
        with self.assertRaises(P.ProofError):
            P.unhx("0x123")

    def test_to_wsl(self) -> None:
        p = Path("C:/Users/test/file.c")
        with patch.object(Path, "resolve", return_value=p):
            self.assertEqual(P.to_wsl(p), "/mnt/c/Users/test/file.c")

        p_invalid = Path("/relative/path")
        with patch.object(Path, "resolve", return_value=p_invalid):
            with self.assertRaises(P.ProofError) as cm:
                P.to_wsl(p_invalid)
            self.assertEqual(cm.exception.code, "path")


class RangeTests(unittest.TestCase):
    def test_merge(self) -> None:
        self.assertEqual(P.merge([(8, 12), (0, 4), (4, 8)]), [(0, 12)])
        self.assertEqual(P.merge([(0, 5), (10, 15), (5, 10)]), [(0, 15)])
        self.assertEqual(P.merge([(0, 5), (10, 15)]), [(0, 5), (10, 15)])

    def test_subtract(self) -> None:
        self.assertEqual(P.subtract([(0, 100)], [(10, 20), (30, 40)]), [(0, 10), (20, 30), (40, 100)])
        self.assertEqual(P.subtract([(0, 100)], [(0, 100)]), [])
        self.assertEqual(P.subtract([(0, 50)], [(60, 100)]), [(0, 50)])

    def test_length_and_intersect(self) -> None:
        self.assertEqual(P.length([(0, 10), (5, 15)]), 15)
        self.assertEqual(P.intersect_length([(0, 10)], [(5, 20)]), 5)
        self.assertEqual(P.intersect_length([(0, 10)], [(10, 20)]), 0)


def make_synthetic_elf(
    sections: list[tuple[str, int, int, int, bytes]] = None,
    symbols: list[tuple[str, int, int, int, int]] = None,
    relocs: list[tuple[int, int, int]] = None,
) -> bytes:
    """Build a minimal valid ELF32 LE bytes buffer with custom sections, symbol table, and relocations."""
    sections = sections or []
    symbols = symbols or []
    relocs = relocs or []

    # Prepare string tables
    shstrtab = b"\0"
    shstr_map = {}
    for name, _, _, _, _ in sections:
        if name not in shstr_map:
            shstr_map[name] = len(shstrtab)
            shstrtab += name.encode("latin-1") + b"\0"
    shstr_map[".shstrtab"] = len(shstrtab)
    shstrtab += b".shstrtab\0"

    strtab = b"\0"
    str_map = {}
    if symbols:
        for name, _, _, _, _ in symbols:
            if name not in str_map:
                str_map[name] = len(strtab)
                strtab += name.encode("latin-1") + b"\0"
        shstr_map[".strtab"] = len(shstrtab)
        shstrtab += b".strtab\0"
        shstr_map[".symtab"] = len(shstrtab)
        shstrtab += b".symtab\0"

    if relocs:
        shstr_map[".rel.text"] = len(shstrtab)
        shstrtab += b".rel.text\0"

    # Layout offsets
    header_size = 52
    data_offset = header_size

    section_data_blocks = []

    # User sections
    user_sec_headers = []
    for name, stype, flags, addr, sdata in sections:
        offset = data_offset
        size = len(sdata)
        section_data_blocks.append(sdata)
        data_offset += size
        user_sec_headers.append((shstr_map[name], stype, flags, addr, offset, size, 0, 0, 4, 0))

    # .shstrtab section
    shstrtab_offset = data_offset
    section_data_blocks.append(shstrtab)
    data_offset += len(shstrtab)

    # .strtab & .symtab section
    strtab_idx, symtab_idx, rel_idx = 0, 0, 0
    symtab_offset, strtab_offset, rel_offset = 0, 0, 0
    symtab_size, strtab_size, rel_size = 0, 0, 0

    if symbols:
        strtab_offset = data_offset
        section_data_blocks.append(strtab)
        data_offset += len(strtab)
        strtab_size = len(strtab)

        symtab_data = bytearray()
        for name, val, sz, info, shndx in symbols:
            st_name = str_map[name]
            symtab_data += struct.pack("<IIIBBH", st_name, val, sz, info, 0, shndx)
        symtab_offset = data_offset
        section_data_blocks.append(bytes(symtab_data))
        data_offset += len(symtab_data)
        symtab_size = len(symtab_data)

    if relocs:
        rel_data = bytearray()
        for off, rtype, rsym in relocs:
            info = (rsym << 8) | (rtype & 0xFF)
            rel_data += struct.pack("<II", off, info)
        rel_offset = data_offset
        section_data_blocks.append(bytes(rel_data))
        data_offset += len(rel_data)
        rel_size = len(rel_data)

    shoff = data_offset
    num_sections = 1 + len(sections) + 1  # NULL + user sections + .shstrtab
    shstrndx = len(sections) + 1

    if symbols:
        strtab_idx = num_sections
        symtab_idx = num_sections + 1
        num_sections += 2
    if relocs:
        rel_idx = num_sections
        num_sections += 1

    # Build section header table
    all_shdrs = [struct.pack("<10I", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)]  # Section 0
    for sh in user_sec_headers:
        all_shdrs.append(struct.pack("<10I", *sh))
    # .shstrtab header
    all_shdrs.append(struct.pack("<10I", shstr_map[".shstrtab"], P.SHT_STRTAB, 0, 0, shstrtab_offset, len(shstrtab), 0, 0, 1, 0))

    if symbols:
        all_shdrs.append(struct.pack("<10I", shstr_map[".strtab"], P.SHT_STRTAB, 0, 0, strtab_offset, strtab_size, 0, 0, 1, 0))
        # link field points to strtab_idx
        all_shdrs.append(struct.pack("<10I", shstr_map[".symtab"], P.SHT_SYMTAB, 0, 0, symtab_offset, symtab_size, strtab_idx, 0, 4, 16))

    if relocs:
        # info field points to target section index (assuming section 1 ".text")
        all_shdrs.append(struct.pack("<10I", shstr_map[".rel.text"], P.SHT_REL, 0, 0, rel_offset, rel_size, symtab_idx if symbols else 0, 1, 4, 8))

    # Build ELF header (e_shnum = num_sections, e_shstrndx = shstrndx)
    elf_header = struct.pack(
        "<16sHHIIIIIHHHHHH",
        b"\x7fELF\x01\x01\x01\x00" + b"\x00" * 8,  # e_ident (32-bit LE)
        2,  # e_type (ET_EXEC)
        8,  # e_machine (MIPS)
        1,  # e_version
        0x00010000,  # e_entry
        0,  # e_phoff
        shoff,  # e_shoff
        0,  # e_flags
        52,  # e_ehsize
        0, 0,  # e_phentsize, e_phnum
        40,  # e_shentsize
        num_sections,  # e_shnum
        shstrndx,  # e_shstrndx
    )

    return elf_header + b"".join(section_data_blocks) + b"".join(all_shdrs)


class ElfTests(unittest.TestCase):
    def test_non_elf_raises_proof_error(self) -> None:
        with self.assertRaises(P.ProofError) as cm:
            P.Elf(b"not an elf file header", "test_file")
        self.assertEqual(cm.exception.code, "elf")

    def test_synthetic_elf_parsing(self) -> None:
        text_data = b"\x00\x00\x00\x00\x08\x00\xe0\x03"
        raw = make_synthetic_elf(
            sections=[(".text", P.SHT_PROGBITS, P.SHF_ALLOC, 0x1000, text_data)],
            symbols=[("my_func", 0x1000, 8, 2, 1)],
            relocs=[(0, 4, 0)],
        )
        elf = P.Elf(raw, "synthetic_elf")
        sec = elf.section(".text")
        self.assertIsNotNone(sec)
        self.assertEqual(sec.name, ".text")
        self.assertEqual(sec.addr, 0x1000)
        self.assertEqual(elf.contents(sec), text_data)

        named_secs = elf.named(".text")
        self.assertEqual(len(named_secs), 1)

        placements = elf.placements(".text", 0x1000)
        self.assertEqual(len(placements), 1)
        self.assertEqual(placements[0][1], 0x1000)

        syms = elf.symbols()
        self.assertEqual(len(syms), 1)
        self.assertEqual(syms[0].name, "my_func")
        self.assertEqual(syms[0].value, 0x1000)

        rels = elf.relocations(sec)
        self.assertEqual(len(rels), 1)
        self.assertEqual((rels[0].offset, rels[0].type, rels[0].sym), (0, 4, 0))

    def test_rela_relocation_raises_error(self) -> None:
        # Manually change relocation section type to SHT_RELA (4)
        raw = make_synthetic_elf(
            sections=[(".text", P.SHT_PROGBITS, P.SHF_ALLOC, 0x1000, b"\x00" * 8)],
            relocs=[(0, 4, 0)],
        )
        # Find SHT_REL and mutate to SHT_RELA
        rela_raw = raw.replace(struct.pack("<I", P.SHT_REL), struct.pack("<I", P.SHT_RELA))
        elf = P.Elf(rela_raw, "rela_elf")
        sec = elf.section(".text")
        with self.assertRaises(P.ProofError) as cm:
            elf.relocations(sec)
        self.assertEqual(cm.exception.code, "relocation")


class MaskedDifferenceTests(unittest.TestCase):
    def test_masked_difference_exact_match(self) -> None:
        obj = bytes.fromhex("0000000c" "00000000")  # jal 0 ; nop
        linked = bytes.fromhex("74b0000c" "00000000")  # jal with target
        self.assertIsNone(P.masked_difference(obj, linked, [P.Reloc(0, 4, 1)]))

    def test_masked_difference_mismatch(self) -> None:
        obj = bytes.fromhex("0000000c" "00000000")
        bad = bytes.fromhex("74b00008" "00000000")
        self.assertEqual(P.masked_difference(obj, bad, [P.Reloc(0, 4, 1)]), 3)

    def test_masked_difference_unknown_reloc_type(self) -> None:
        obj = bytes.fromhex("0000000c" "00000000")
        linked = bytes.fromhex("74b0000c" "00000000")
        with self.assertRaises(P.ProofError) as cm:
            P.masked_difference(obj, linked, [P.Reloc(0, 99, 1)])
        self.assertEqual(cm.exception.code, "relocation")

    def test_masked_difference_misaligned_or_oob_reloc(self) -> None:
        obj = bytes.fromhex("0000000c" "00000000")
        linked = bytes.fromhex("74b0000c" "00000000")
        with self.assertRaises(P.ProofError):
            P.masked_difference(obj, linked, [P.Reloc(1, 4, 1)])  # unaligned
        with self.assertRaises(P.ProofError):
            P.masked_difference(obj, linked, [P.Reloc(8, 4, 1)])  # out of bounds


class ProofValidationTests(unittest.TestCase):
    def make_valid_proof(self, source="src/a.c", start="0x00000000", end="0x00000008") -> dict:
        base = {
            "schema": P.PROOF_SCHEMA,
            "module": "EBOOT.BIN",
            "start": start,
            "end": end,
            "symbol": "f",
            "source": source,
            "source_sha256": "a" * 64,
            "cc": "gcc404xs-Os",
            "lang": "c99",
            "deps": {"source_sha256": "a" * 64, "headers": [], "unresolved_includes": [], "symbols": []},
            "toolchain": "b" * 64,
            "target": "c" * 64,
            "compared": {},
            "object_sha256": "d" * 64,
            "status": "EXACT",
            "gate": {"result": "pass", "idioms": []},
            "run": "run1",
            "verified_utc": "2025-01-01T00:00:00Z",
        }
        base["deps_sha256"] = P.digest(base["deps"])
        base["proof_sha256"] = P.proof_digest(base)
        return base

    def test_valid_proof_passes(self) -> None:
        p1 = self.make_valid_proof("src/a.c", "0x00000000", "0x00000008")
        p2 = self.make_valid_proof("src/b.c", "0x00000008", "0x00000010")
        P.validate_proofs([p1, p2])

    def test_missing_keys_raises_error(self) -> None:
        p = self.make_valid_proof()
        del p["cc"]
        with self.assertRaises(P.ProofError) as cm:
            P.validate_proofs([p])
        self.assertEqual(cm.exception.code, "ledger")

    def test_non_exact_or_failed_gate_raises_error(self) -> None:
        p = self.make_valid_proof()
        p["status"] = "MISMATCH"
        p["proof_sha256"] = P.proof_digest(p)
        with self.assertRaises(P.ProofError):
            P.validate_proofs([p])

    def test_tampered_proof_sha256_raises_error(self) -> None:
        p = self.make_valid_proof()
        p["proof_sha256"] = "0" * 64
        with self.assertRaises(P.ProofError):
            P.validate_proofs([p])

    def test_out_of_order_or_overlapping_proofs_raise_error(self) -> None:
        p1 = self.make_valid_proof("src/a.c", "0x00000000", "0x00000008")
        p2 = self.make_valid_proof("src/b.c", "0x00000004", "0x0000000c")
        with self.assertRaises(P.ProofError):
            P.validate_proofs([p1, p2])


class LedgerAndJournalTests(unittest.TestCase):
    def test_read_journal_and_parse_ledger(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            j_event = {
                "schema": P.JOURNAL_SCHEMA,
                "seq": 1,
                "prev_sha256": None,
                "utc": "2025-01-01T00:00:00Z",
                "event": "seed",
                "ledger_body_sha256": P.sha256(b""),
                "ledger_count": 0,
                "ranges_sha256": P.digest([]),
                "bytes": {},
                "toolchain": "b" * 64,
                "target": "c" * 64,
            }
            j_line = P.canon(j_event)
            j_data = j_line + b"\n"

            header = {
                "schema": P.LEDGER_SCHEMA,
                "toolchain": "b" * 64,
                "target": "c" * 64,
                "count": 0,
                "bytes": {},
                "ranges_sha256": P.digest([]),
                "body_sha256": P.sha256(b""),
                "journal_seq": 1,
                "journal_sha256": P.sha256(j_line),
                "symbols_sha256": {},
            }
            l_data = P.canon(header) + b"\n"

            ledger = P.parse_ledger(l_data, j_data)
            self.assertEqual(ledger.header["count"], 0)
            self.assertEqual(len(ledger.journal), 1)

            P.check_binding(ledger, "b" * 64, "c" * 64)
            with self.assertRaises(P.ProofError) as cm:
                P.check_binding(ledger, "x" * 64, "c" * 64)
            self.assertEqual(cm.exception.code, "binding")

    def test_broken_journal_chain_raises_error(self) -> None:
        bad_j_event = {
            "schema": P.JOURNAL_SCHEMA,
            "seq": 2,  # Should be 1
            "prev_sha256": None,
            "utc": "2025-01-01T00:00:00Z",
            "event": "seed",
        }
        j_data = P.canon(bad_j_event) + b"\n"
        with self.assertRaises(P.ProofError) as cm:
            P.read_journal(data=j_data)
        self.assertEqual(cm.exception.code, "journal")


class DiffDescriptionTests(unittest.TestCase):
    def test_describe_target_diff(self) -> None:
        old_target = {"game": {"title": "A"}, "modules": [{"name": "EBOOT.BIN", "size": 100}]}
        new_target = {"game": {"title": "B"}, "modules": [{"name": "EBOOT.BIN", "size": 200}]}
        desc = P.describe_target_diff(old_target, new_target)
        self.assertIn("game release fields differ", desc)
        self.assertIn("EBOOT.BIN size differs", desc)

    def test_describe_toolchain_diff(self) -> None:
        old_tc = {"profiles": {"gcc404xs-Os": "a"}, "include": {"h1.h": "sha1"}}
        new_tc = {"profiles": {"gcc404xs-Os": "b"}, "include": {"h1.h": "sha2"}}
        desc = P.describe_toolchain_diff(old_tc, new_tc)
        self.assertIn("profiles: gcc404xs-Os", desc)
        self.assertIn("h1.h changed", desc)


class SymbolAndClosureTests(unittest.TestCase):
    def test_symbol_parsing_and_resolution(self) -> None:
        symmap = {"my_sym": 0x00123456}
        self.assertEqual(P.resolve("my_sym", symmap), 0x00123456)
        self.assertEqual(P.resolve("FUN_00654321", symmap), 0x00654321)
        self.assertIsNone(P.resolve("unknown_sym", symmap))

    def test_include_closure(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "include").mkdir()
            (root / "include" / "helper.h").write_text("#define HELPER 1\n", encoding="utf-8")
            (root / "src").mkdir()
            src_file = root / "src" / "main.c"
            src_file.write_text('#include "helper.h"\n#include <missing.h>\nint x;\n', encoding="utf-8")

            res = P.include_closure(src_file, root)
            self.assertEqual(res["headers"], [["include/helper.h", P.file_sha256(root / "include" / "helper.h")]])
            self.assertEqual(res["unresolved_includes"], ["missing.h"])


class LbpSpecificTests(unittest.TestCase):
    """What the LBP port adds to hst-decomp's design."""

    def test_random_seed_names_are_the_only_allowed_object_difference(self) -> None:
        def obj(seed: str, code: bytes = b"\x08\x00\xe0\x03\x00\x00\x00\x00") -> bytes:
            return make_synthetic_elf(
                sections=[(".text", P.SHT_PROGBITS, P.SHF_ALLOC, 0, code)],
                symbols=[(f"_GLOBAL__I_static_init_088747dc.cpp_00000000_{seed}", 0, 8, 2, 1),
                         ("_ZN36_GLOBAL__N_a.cpp_00000000_" + seed + "3fooEv", 0, 8, 2, 1)])
        a, b = obj("F51DF497"), obj("52B630EB")
        self.assertNotEqual(a, b)
        self.assertEqual(P.normalized_object(a), P.normalized_object(b))
        self.assertEqual(len(P.normalized_object(a)), len(a))
        # a code change is not hidden by the normalisation
        self.assertNotEqual(P.normalized_object(obj("F51DF497", b"\x08\x00\xe0\x03\x01\x00\x00\x00")),
                            P.normalized_object(b))
        # nor a change of anything else in a name (here the file name)
        c = make_synthetic_elf(sections=[(".text", P.SHT_PROGBITS, P.SHF_ALLOC, 0, b"\x08\x00\xe0\x03\x00\x00\x00\x00")],
                               symbols=[("_GLOBAL__I_static_init_088747dd.cpp_00000000_F51DF497", 0, 8, 2, 1),
                                        ("_ZN36_GLOBAL__N_a.cpp_00000000_F51DF4973fooEv", 0, 8, 2, 1)])
        self.assertNotEqual(P.normalized_object(c), P.normalized_object(a))
        # an object without such names is unchanged
        plain = make_synthetic_elf(sections=[(".text", P.SHT_PROGBITS, P.SHF_ALLOC, 0, b"\0" * 8)],
                                   symbols=[("FUN_08804000", 0, 8, 2, 1)])
        self.assertEqual(P.normalized_object(plain), plain)

    def test_functions_file_with_a_status_column(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            f = Path(tmp) / "functions-EBOOT.BIN.txt"
            f.write_text("# start end status\n8804030 88040b4 auto\n8804000 8804024 stub\n", encoding="utf-8")
            self.assertEqual(P.read_functions_file(f), [(0x8804000, 0x8804024), (0x8804030, 0x88040b4)])

    def test_placed_symbol_change_makes_a_proof_stale(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "src" / "eboot").mkdir(parents=True)
            (root / "symbols").mkdir()
            (root / "symbols" / "EBOOT.BIN.txt").write_text("_ZZ3fooE1x = 0x08c00000;\n", encoding="utf-8")
            src = root / "src" / "eboot" / "foo_08804000.cpp"
            src.write_text("/* LBPMATCH module=EBOOT.BIN start=0x08804000 end=0x08804024 symbol=_Z3foov lang=c++ */\n"
                           "int foo() { static int x; return ++x; }\n", encoding="utf-8")
            sha = P.file_sha256(src)
            deps = P.deps_record(sha, P.include_closure(src, root), [], [["_ZZ3fooE1x", "0x08c00000"]])
            proof = {"module": "EBOOT.BIN", "start": "0x08804000", "end": "0x08804024", "symbol": "_Z3foov",
                     "source": "src/eboot/foo_08804000.cpp", "source_sha256": sha, "deps": deps, "cc": "gcc404xs-Os"}
            inv = {"EBOOT.BIN": [(0x08804000, 0x08804024)]}
            self.assertEqual(P.proof_problems(proof, root, {}, inv, "gcc404xs-Os"), [])
            # the header has no cc=: a different primary profile is a different compile
            self.assertIn("compiler profile differs", P.proof_problems(proof, root, {}, inv, "gcc402x-Os")[0])
            (root / "symbols" / "EBOOT.BIN.txt").write_text("_ZZ3fooE1x = 0x08c00010;\n", encoding="utf-8")
            self.assertEqual(P.proof_problems(proof, root, {}, inv, "gcc404xs-Os"),
                             ["symbol resolution changed: _ZZ3fooE1x"])

    def test_comparison_code_names_the_lbp_tools(self) -> None:
        self.assertEqual(set(P.COMPARISON_CODE), {"tools/lbpmatch.py", "tools/lbpgate.py", "tools/lbpconfig.py",
                                                  "tools/lbpproof.py", "tools/lbppromote.py"})

    def test_toolchain_diff_names_added_profiles_and_the_primary(self) -> None:
        old = {"profiles": {"gcc404xs-Os": {"flags": "-Os"}}, "primary": "gcc404xs-Os"}
        new = {"profiles": {"gcc404xs-Os": {"flags": "-Os"}, "gcc404y-Os": {"flags": "-Os"}}, "primary": "gcc404y-Os"}
        desc = P.describe_toolchain_diff(old, new)
        self.assertIn("profiles: gcc404y-Os (added)", desc)
        self.assertIn("primary profile: gcc404xs-Os -> gcc404y-Os", desc)


if __name__ == "__main__":
    unittest.main()
