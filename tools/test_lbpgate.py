#!/usr/bin/env python3
"""Tests for the fake-match gate (lbpgate.py) and for the places that must use it."""
from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpgate as G


def kinds(text: str, header: dict | None = None, tree: str = "src") -> set[str]:
    return {f.kind for f in G.check_text(text, header, tree)}


def refused(text: str, header: dict | None = None, tree: str = "src") -> set[str]:
    return {f.kind for f in G.refusals(G.check_text(text, header, tree))}


class RefusalTests(unittest.TestCase):
    def test_plain_c_has_no_findings(self) -> None:
        self.assertEqual(kinds('#include <string.h>\n#pragma inline_depth(8)\nint f(int a) { return a + 1; }\n'), set())

    def test_asm_statements_are_refused_whatever_the_dialect(self) -> None:
        self.assertEqual(refused('void f(void) { __asm__ volatile ("addiu $2,$2,1"); }'), {"asm-emit"})
        self.assertEqual(refused('void f(void) { asm("nop"); }'), {"asm-emit"})
        self.assertEqual(refused('asm void f(void) {\n  addiu r3, r3, 1\n  blr\n}\n'), {"asm-emit"})
        self.assertEqual(refused('void f(void) { __asm { nop } }'), {"asm-emit"})
        self.assertEqual(refused('void f(void) { _asm { nop } }'), {"asm-emit"})

    def test_a_register_binding_and_an_empty_barrier_are_tagged_but_allowed(self) -> None:
        text = 'void f(const unsigned char *src) {\n    register unsigned char c asm("$2") = *src;\n}\n'
        self.assertEqual(kinds(text), {"register-asm-binding"})
        self.assertEqual(refused(text), set())
        self.assertEqual(kinds('void f(void) { __asm__ __volatile__("" ::: "memory"); }'), {"empty-asm-barrier"})
        self.assertEqual(refused('void f(void) { asm volatile("" : : : "memory"); }'), set())
        # a binding does not excuse real code in the same function
        self.assertEqual(refused('void f(void) { register int c asm("$2") = 1; asm("nop"); }'), {"asm-emit"})

    def test_data_directives_are_refused_but_member_access_and_designators_are_not(self) -> None:
        self.assertEqual(refused('void f(void) { __asm__(".word 0x27bdffe0"); }'), {"asm-emit", "data-directive"})
        self.assertEqual(refused('const char *s = ".byte 1, 2";'), {"data-directive"})
        self.assertEqual(refused('__asm__(".incbin \\"retail.bin\\"");'), {"asm-emit", "data-directive"})
        self.assertEqual(kinds('struct S { int word; } s = { .word = 1 };\nint g(struct S *p) { return p->word + s.word; }\n'), set())

    def test_pragmas(self) -> None:
        self.assertEqual(refused("#pragma asm\n"), {"pragma-code"})
        self.assertEqual(refused("#pragma push_asm\n"), {"pragma-code"})
        self.assertEqual(kinds("#pragma opt_strength_reduction off\n#pragma inline_depth(8)\n#pragma exceptions on\n"), set())
        findings = G.check_text("#pragma mystery on\n", None, "src")
        self.assertEqual([(f.kind, f.severity) for f in findings], [("pragma-unknown", G.WARN)])

    def test_text_section_tricks_and_binary_includes_are_refused(self) -> None:
        self.assertEqual(refused('__attribute__((section(".text"))) const unsigned code[] = { 0x27bdffe0 };'), {"text-section"})
        self.assertEqual(refused('#pragma section ".text"\n'), {"text-section"})
        self.assertEqual(refused('const unsigned char blob[] = {\n#include "retail.bin"\n};\n'), {"binary-include"})
        self.assertEqual(refused('#include "table.inc"\n'), {"binary-include"})
        self.assertEqual(refused('#include <stdio.h>\n#include "local.h"\n'), set())

    def test_extra_is_refused_only_in_src(self) -> None:
        self.assertEqual(refused("int x;", {"extra": "-opt nopeephole"}, "src"), {"extra-header"})
        self.assertEqual(refused("int x;", {"extra": "-opt nopeephole"}, "wip"), set())
        self.assertEqual(refused("int x;", {"module": "EBOOT.BIN"}, "src"), set())

    def test_comments_are_not_scanned_but_strings_are(self) -> None:
        self.assertEqual(kinds("/* asm(\".word 1\") */\n// __asm__ volatile (\"nop\");\nint x;\n"), set())
        self.assertEqual(refused('const char *s = "/* not a comment */ .word 7";'), {"data-directive"})

    def test_findings_carry_line_numbers(self) -> None:
        found = G.check_text("int a;\nint b;\nvoid f(void) { asm(\"nop\"); }\n")
        self.assertEqual([f.line for f in found], [3])


class WiringTests(unittest.TestCase):
    """The gate must be called from the matcher, the harvester and the linter."""

    def source(self, name: str) -> str:
        return (Path(__file__).resolve().parent / name).read_text(encoding="utf-8")

    def test_lbpmatch_reports_a_distinct_status(self) -> None:
        text = self.source("lbpmatch.py")
        self.assertIn("import lbpgate", text)
        self.assertIn('status, detail = "EXACT_FAILS_GATE"', text)

    def test_lbplint_reports(self) -> None:
        self.assertIn('flags["gate"]', self.source("lbplint.py"))

    def test_check_file_uses_the_tree_of_the_path(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "src").mkdir()
            (root / "wip").mkdir()
            text = '/* LBPMATCH module=EBOOT.BIN start=0x0 end=0x4 symbol=f lang=c99 extra="-opt x" */\nint f;\n'
            (root / "src" / "a.c").write_text(text, encoding="utf-8")
            (root / "wip" / "a.c").write_text(text, encoding="utf-8")
            self.assertEqual({f.kind for f in G.refusals(G.check_file(root / "src" / "a.c", root))}, {"extra-header"})
            self.assertEqual(G.refusals(G.check_file(root / "wip" / "a.c", root)), [])

    def test_the_tree_has_no_refused_source_and_only_the_known_idioms(self) -> None:
        root = G.ROOT
        refused_files, idioms = [], []
        for p in sorted((root / "src").rglob("*")):
            if p.suffix in (".c", ".cpp"):
                found = G.check_file(p, root)
                if G.refusals(found):
                    refused_files.append(p.name)
                if found:
                    idioms.append(p.name)
        self.assertEqual(refused_files, [])
        self.assertEqual(sorted(idioms), [])


    def test_vfpu_inline_asm_rule(self) -> None:
        """LBP rule (owner 2026-10-27): VFPU-only inline asm with header asm=vfpu and a stated reason is an idiom;
        a non-VFPU instruction, a missing key or a missing reason keeps it a refusal."""
        b = chr(92)
        ok = ('/* LBPMATCH module=EBOOT.BIN start=0x0 end=0x4 symbol=f lang=c99 asm=vfpu */' + chr(10) +
              '/* Original inline VFPU asm: the vector math header used lv.q/vdot. */' + chr(10) +
              'void f(float *v){ __asm__ volatile("lv.q C000, 0(%0)' + b + 'n" "vdot.q S010, C000, C000' + b + 'n" '
              '"sv.s S010, 0(%0)" : : "r"(v) : "memory"); }' + chr(10))
        kinds = lambda t, h: {(f.kind, f.severity) for f in G.check_text(t, h, "src")}  # noqa: E731
        self.assertEqual(kinds(ok, {"asm": "vfpu"}), {("vfpu-inline-asm", G.IDIOM)})
        self.assertEqual(kinds(ok.replace("vdot.q S010, C000, C000", "addiu $t0, $t0, 1"), {"asm": "vfpu"}),
                         {("asm-emit", G.REFUSE)})
        self.assertEqual(kinds(ok, {}), {("asm-emit", G.REFUSE)})
        self.assertEqual(kinds(ok.replace("Original inline VFPU asm:", "VFPU:"), {"asm": "vfpu"}),
                         {("asm-emit", G.REFUSE)})


if __name__ == "__main__":
    unittest.main()
