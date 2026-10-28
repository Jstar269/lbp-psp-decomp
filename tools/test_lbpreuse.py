#!/usr/bin/env python3
"""Tests for the licensing bookkeeping (lbpreuse.py): glob semantics, notice families, the library block."""
from __future__ import annotations

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpreuse as R  # noqa: E402


class ReuseTests(unittest.TestCase):
    def test_globs_follow_reuse(self) -> None:
        self.assertTrue(R.glob_regex("src/**").match("src/eboot/a.c"))
        self.assertTrue(R.glob_regex("docs/*.md").match("docs/GUIDE.md"))
        self.assertFalse(R.glob_regex("docs/*.md").match("docs/public/README.md"))

    def test_licence_files_are_skipped_as_reuse_does(self) -> None:
        self.assertTrue(R.reuse_ignored("LICENSE"))
        self.assertTrue(R.reuse_ignored("LICENSES/Zlib.txt"))
        self.assertFalse(R.reuse_ignored("third_party/newlib/newlib-1.14.0-COPYING.NEWLIB"))

    def test_newlib_notice_families(self) -> None:
        text = "/* Copyright (c) 1993 Martin Birgmeier\n * All rights reserved. */\n/* by David M. Gay */\n"
        found = R.families(text)
        self.assertEqual(set(found), {"LicenseRef-Newlib-Birgmeier", "LicenseRef-Newlib-Gay-AT-T"})

    def test_library_block_names_each_class_once(self) -> None:
        block = R.render_libs({"zlib": ["src/eboot/zlib_b.c", "src/eboot/zlib_a.c"], "libstdc++": ["src/eboot/x.c"]})
        self.assertTrue(block.startswith(R.BEGIN_LIBS) and block.rstrip().endswith(R.END_LIBS))
        self.assertEqual(block.count("[[annotations]]"), 2)
        self.assertLess(block.index("zlib_a.c"), block.index("zlib_b.c"))
        self.assertIn('SPDX-License-Identifier = "Zlib"', block)

    def test_every_licence_named_in_the_library_classes_has_a_text(self) -> None:
        for expression, _statements in R.LIBRARY_CLASSES.values():
            for lid in R.license_ids(expression):
                self.assertTrue((R.LICENSES / f"{lid}.txt").is_file(), lid)


if __name__ == "__main__":
    unittest.main()
