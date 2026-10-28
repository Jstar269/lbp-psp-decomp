#!/usr/bin/env python3
"""Identify library functions in the retail modules by compiling the library's own source.

    python tools/lbplib.py index [--obj-root <dir>]      (default: newlib_obj_root of lbp-config.json)
    python tools/lbplib.py report

`index` reads every object built by the library build script (one directory per configuration, e.g.
1.14.0-171-O2), takes each function's bytes from .text, masks them like lbpclone.py (call/jump targets and
lui-based address halves), and looks every unmatched reviewed retail function of the game modules
(data/modules.json) up by that masked signature. A hit means the retail function is that library function
compiled with that configuration, up to addresses; the source is then reconstructed from the library file
and still has to pass lbpmatch.py exactly. Writes try/lib-hits.json.
"""
from __future__ import annotations

import argparse
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpclone as C
import lbpconfig as CFG
import lbpmatch as M
import lbpproject as P

MODULES = P.game_modules()


def object_functions(path: Path):
    obj = path.read_bytes()
    sections = M.elf_sections(obj)
    names = [n for n, _ in sections]
    if ".text" not in names:
        return
    ti = names.index(".text")
    text = sections[ti][1]
    data = obj[text[4]:text[4] + text[5]]
    for name, value, size, info, shndx in M.elf_symbols(obj):
        if shndx == ti and info & 0xF == 2 and size >= 8 and value + size <= len(data):
            yield name, C.words(data[value:value + size])


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", choices=("index", "report"))
    ap.add_argument("--obj-root", type=Path, help="library object directories (default: newlib_obj_root in lbp-config.json)")
    args = ap.parse_args()
    out = M.ROOT / "try" / "lib-hits.json"
    if args.command == "index":
        index = defaultdict(list)
        obj_root = args.obj_root or CFG.host_path("newlib_obj_root")
        for cfg in sorted(obj_root.iterdir()):
            if not cfg.is_dir():
                continue
            n = 0
            for o in sorted(cfg.glob("*.o")):
                for fname, ws in object_functions(o):
                    index[C.analyse(ws)[0]].append({"config": cfg.name, "object": o.name, "function": fname,
                                                    "words": len(ws)})
                    n += 1
            print(f"{cfg.name}: {n} functions")
        ledger = json.loads((M.CAMPAIGN / "ledger" / "campaign.json").read_text(encoding="utf-8-sig"))
        covered = set()
        for p in (M.ROOT / "src").rglob("*"):
            if p.suffix in (".c", ".cpp"):
                h = M.parse_header(p)
                covered.add((h["module"], h["start"]))
        hits = []
        for mod_name in MODULES:
            mod = next(m for m in ledger["modules"] if m["name"] == mod_name)
            data, seg = M.module_bytes({}, mod_name)
            for f in mod["functions"]:
                # import stubs are not library code, and an 8-byte body (`jr ra` + one instruction) matches every empty
                # function of every library: a signature that short identifies nothing
                if ((mod_name, f["start"]) in covered or f["end"] - f["start"] < 12
                        or f.get("boundary_status", "reviewed") not in P.USABLE_BOUNDARY):
                    continue
                off = seg["file_offset"] + f["start"] - seg["start"]
                sig = C.analyse(C.words(data[off:off + f["end"] - f["start"]]))[0]
                if sig in index:
                    hits.append({"module": mod_name, "start": f"0x{f['start']:08x}", "end": f"0x{f['end']:08x}",
                                 "size": f["end"] - f["start"], "candidates": index[sig]})
        out.write_text(json.dumps(hits, indent=1) + "\n", encoding="utf-8")
    hits = json.loads(out.read_text(encoding="utf-8"))
    by_mod = defaultdict(lambda: [0, 0])
    by_cfg = defaultdict(int)
    for h in hits:
        by_mod[h["module"]][0] += 1
        by_mod[h["module"]][1] += h["size"]
        for cfg in {c["config"] for c in h["candidates"]}:
            by_cfg[cfg] += 1
    for m, (n, b) in by_mod.items():
        print(f"{m}: {n} functions, {b} bytes identified")
    for cfg, n in sorted(by_cfg.items()):
        print(f"  {cfg}: {n}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
