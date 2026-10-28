#!/usr/bin/env python3
"""Disassemble retail functions by address (reviewed ledger extents): python tools/lbpdis.py [--module M] 0xADDR..."""
from __future__ import annotations

import argparse
import json
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpdiff as D
import lbpmatch as M
import lbpproject as P


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("addresses", nargs="+")
    ap.add_argument("--module", default=P.default_module())
    args = ap.parse_args()
    ledger = json.loads((M.CAMPAIGN / "ledger" / "campaign.json").read_text(encoding="utf-8-sig"))
    module = next(m for m in ledger["modules"] if m["name"] == args.module)
    ends = {f["start"]: f["end"] for f in module["functions"]}
    cache: dict = {}
    data, seg = M.module_bytes(cache, args.module)
    with tempfile.TemporaryDirectory(dir=M.ROOT / "build") as tmp:
        for text in args.addresses:
            start = int(text, 16)
            end = ends.get(start)
            if end is None:
                print(f"== 0x{start:08x}: no ledger function starts here")
                continue
            off = seg["file_offset"] + start - seg["start"]
            path = Path(tmp) / f"{start:08x}.bin"
            path.write_bytes(data[off:off + end - start])
            print(f"== 0x{start:08x}..0x{end:08x} ({end - start} bytes)")
            for row in D.disasm(path, start):
                print("   " + row)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
