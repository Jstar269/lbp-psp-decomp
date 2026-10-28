#!/usr/bin/env python3
"""Readability score of a source: how much of the decompiler's raw form is left in it (lower is better).

    python tools/lbpreadable.py [--top 30] [--all] [files ...]   score the publishable sources (or the files given)

Counted, each occurrence weighing 1 (the typedef block 5): Ghidra's generated names (`param_1`, `local_10`, `iVar1`,
`puVar3`, `auStack_20`, `unaff_s0`, `in_v0`, `extraout_v0`), its `undefined`/`undefined4` types and `code` function
pointer type, a pointer cast over an offset (`*(int *)(p + 0x14)`: a struct member not declared), and the typedef
block lbpgen pastes in front of a translation. Address names (`FUN_`, `DAT_`) are not counted: a name needs evidence
(AGENTS.md), and an address name is the honest one until there is some.

tools/lbpqueue.py --kind readability ranks by this score; docs/READABILITY-BRIEF.md says what a pass may change.
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbporigin

GHIDRA_NAME = re.compile(r"\b(?:param_\d+|local_[0-9a-f]+|[a-z]{1,3}Var\d+|a?[a-z]{1,2}Stack_[0-9a-f]+|"
                         r"unaff_\w+|in_[a-z]\w*|extraout_\w+)\b")
GHIDRA_TYPE = re.compile(r"\bundefined[1248]?\b|\bcode\s*\*")
OFFSET_CAST = re.compile(r"\*\s*\(\s*[\w ]+\*+\s*\)\s*\(\s*[\w.>-]+\s*[+-]\s*(?:0x[0-9a-fA-F]+|\d+)\s*\)")
TYPEDEF_BLOCK = re.compile(r"typedef unsigned char undefined;")


def strip_comments(text: str) -> str:
    return re.sub(r"/\*.*?\*/|//[^\n]*", "", text, flags=re.S)


def score(text: str) -> dict:
    code = strip_comments(text)
    parts = {"names": len(GHIDRA_NAME.findall(code)), "types": len(GHIDRA_TYPE.findall(code)),
             "offset_casts": len(OFFSET_CAST.findall(code)), "typedef_block": 5 * len(TYPEDEF_BLOCK.findall(code))}
    parts["score"] = sum(parts.values())
    return parts


def publishable(root: Path = lbporigin.ROOT) -> list[str]:
    """Sources under src/ the public tree would carry (tools/lbppublish.py policy)."""
    import lbppublish
    classes, _w = lbporigin.classify(root)
    return sorted(p for p, c in classes.items() if p.startswith("src/") and c not in lbppublish.EXCLUDED_CLASSES)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("files", nargs="*", type=Path)
    ap.add_argument("--top", type=int, default=30)
    ap.add_argument("--all", action="store_true", help="print every row")
    args = ap.parse_args()
    root = lbporigin.ROOT
    paths = [p.resolve().relative_to(root).as_posix() for p in args.files] if args.files else publishable(root)
    rows = sorted(((score((root / p).read_text(encoding="utf-8", errors="replace")), p) for p in paths),
                  key=lambda r: (-r[0]["score"], r[1]))
    total = sum(r[0]["score"] for r in rows)
    clean = sum(1 for r in rows if r[0]["score"] == 0)
    print(f"{len(rows)} sources, total score {total}, {clean} with score 0")
    for s, p in rows if args.all else rows[:args.top]:
        print(f"{s['score']:5d}  names {s['names']:4d} types {s['types']:4d} casts {s['offset_casts']:3d}  {p}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
