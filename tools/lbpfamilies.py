#!/usr/bin/env python3
"""Rank unmatched clone families (same masked code as lbpclone.py) by total bytes: one exact exemplar
unlocks the whole family. python tools/lbpfamilies.py [--module EBOOT.BIN] [--top 30] [--min-start 0x88000]"""
from __future__ import annotations

import argparse
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpclone as C
import lbpmatch as M
import lbpproject as P


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", default=P.default_module())
    ap.add_argument("--top", type=int, default=30)
    ap.add_argument("--min-start", type=lambda s: int(s, 0), default=0x88000)
    args = ap.parse_args()
    ledger = json.loads((M.CAMPAIGN / "ledger" / "campaign.json").read_text(encoding="utf-8-sig"))
    module = next(m for m in ledger["modules"] if m["name"] == args.module)
    data, seg = M.module_bytes({}, args.module)
    have = {M.parse_header(p)["start"] for p in (M.ROOT / "src").rglob("*")
            if p.suffix in (".c", ".cpp") and M.parse_header(p)["module"] == args.module}
    families = defaultdict(list)
    for f in module["functions"]:
        if f.get("boundary_status") not in P.USABLE_BOUNDARY or f["start"] < args.min_start:
            continue
        off = seg["file_offset"] + f["start"] - seg["start"]
        sig, _refs = C.analyse(C.words(data[off:off + f["end"] - f["start"]]))
        families[sig].append(f["start"])
    rows = []
    for sig, starts in families.items():
        if len(starts) < 2 or any(s in have for s in starts):
            continue
        rows.append((4 * len(sig) * len(starts), len(starts), 4 * len(sig), sorted(starts)))
    rows.sort(reverse=True)
    total = sum(r[0] for r in rows)
    print(f"unmatched families (>=2 members): {len(rows)}, {sum(r[1] for r in rows)} functions, {total} bytes")
    for total_bytes, n, size, starts in rows[:args.top]:
        print(f"{total_bytes:7d} B  {n:4d} x {size:5d} B  e.g. " + " ".join(f"0x{s:x}" for s in starts[:4]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
