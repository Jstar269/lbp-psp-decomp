#!/usr/bin/env python3
"""Classify why generated candidates mismatched (after lbpgen.py), to choose the next translation fix.

    python tools/lbpcat.py try/gen-<tag> [--variant v0] [--examples 3]

Reads each MISMATCH candidate's linked bytes (build/<module>/<lbpmatch.build_key>/text.bin) and the retail
bytes (target.bin, written by lbpmatch.py on a mismatch), and assigns the first matching class:

  frame        the stack adjustment (first instruction) differs
  length       different instruction counts (ours shorter/longer)
  load_sign    only lb<->lbu / lh<->lhu differ
  regalloc     same opcodes everywhere, only register fields differ
  likely       only branch vs branch-likely (and the delay slots they change)
  reorder      the same multiset of words in a different order
  other        anything else
"""
from __future__ import annotations

import argparse
import collections
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpmatch as M  # noqa: E402
import lbpproject as P  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
LOAD_SIGN = {(0x20, 0x24), (0x24, 0x20), (0x21, 0x25), (0x25, 0x21)}  # lb/lbu, lh/lhu
LIKELY = {0x04: 0x14, 0x05: 0x15, 0x06: 0x16, 0x07: 0x17}  # beq/bne/blez/bgtz -> likely forms


def words(data: bytes) -> list[int]:
    return [int.from_bytes(data[i:i + 4], "little") for i in range(0, len(data) - len(data) % 4, 4)]


def opcode_key(word: int) -> tuple[int, int]:
    op = word >> 26
    if op == 0:
        return (0, word & 0x3F)          # SPECIAL: function field
    if op == 1:
        return (1, (word >> 16) & 0x1F)  # REGIMM: rt selects the branch
    return (op, 0)


def classify(ours: list[int], theirs: list[int]) -> str:
    if ours and theirs and ours[0] != theirs[0] and ours[0] >> 16 == 0x27BD and theirs[0] >> 16 == 0x27BD:
        return "frame"
    if len(ours) != len(theirs):
        return "length"
    pairs = [(a, b) for a, b in zip(ours, theirs) if a != b]
    if all(((a >> 26), (b >> 26)) in LOAD_SIGN and (a & 0x03FFFFFF) == (b & 0x03FFFFFF) for a, b in pairs):
        return "load_sign"
    if all(opcode_key(a) == opcode_key(b) for a, b in pairs):
        return "regalloc"
    likely_pairs = [(a, b) for a, b in pairs if LIKELY.get(a >> 26) == b >> 26 or LIKELY.get(b >> 26) == a >> 26]
    if likely_pairs and len(likely_pairs) * 3 >= len(pairs):
        return "likely"
    if sorted(ours) == sorted(theirs):
        return "reorder"
    return "other"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("gen", type=Path)
    ap.add_argument("--variant", default="v0")
    ap.add_argument("--module", default=P.default_module())
    ap.add_argument("--examples", type=int, default=3)
    args = ap.parse_args()
    gen = args.gen.resolve()
    rows = []
    for summary in sorted(gen.glob("summary-*.json")):
        rows += json.loads(summary.read_text(encoding="utf-8"))
    exact = {row["start"] for row in rows if row["status"] == "EXACT"}
    counts: collections.Counter = collections.Counter()
    sizes: collections.Counter = collections.Counter()
    examples: dict[str, list[str]] = collections.defaultdict(list)
    for row in rows:
        source = ROOT / row["source"]
        if row["status"] != "MISMATCH" or source.parent.name != args.variant or row["start"] in exact:
            continue
        out = ROOT / "build" / args.module / M.build_key(source)
        if not (out / "text.bin").exists() or not (out / "target.bin").exists():
            continue
        theirs = words((out / "target.bin").read_bytes())
        ours = words((out / "text.bin").read_bytes())[:max(len(theirs), 1) + 64]
        # text.bin may run past the function; compare only our function's words when lengths agree
        ours_fn = ours[:len(theirs)] if len(ours) >= len(theirs) and ours[len(theirs) - 1:len(theirs)] else ours
        kind = classify(ours_fn, theirs)
        counts[kind] += 1
        sizes[kind] += 4 * len(theirs)
        if len(examples[kind]) < args.examples:
            examples[kind].append(row["source"])
    total = sum(counts.values())
    print(f"{args.variant} mismatches classified: {total}")
    for kind, n in counts.most_common():
        print(f"  {kind:10s} {n:5d}  {sizes[kind]:7d} bytes   e.g. {', '.join(examples[kind])}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
