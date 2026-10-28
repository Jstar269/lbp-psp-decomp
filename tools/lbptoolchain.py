#!/usr/bin/env python3
"""Compiler fingerprints of PSP MIPS code: which compiler family built a function, a module, or an address range.

    python tools/lbptoolchain.py profile --elf FILE --functions data/functions-NAME.txt [--by-range 0x10000] [--json out]
    python tools/lbptoolchain.py object FILE.o [...]        the same counts for compiled objects (reference samples)

Counts encodings that differ between the PSP compilers even when the instruction is the "same":

  move_or / move_addu     `move rd, rs` as `or rd,rs,zero` or as `addu rd,rs,zero`
  li0_ori / li0_addiu / li0_move   loading 0 as `ori rt,zero,0`, `addiu rt,zero,0` or a move from $zero
  likely                  branch-likely forms (beql/bnel/... ) per branch
  ra_top                  `sw ra` at the top of the frame (frame-4) versus below the saved s-registers
  ra_first                `sw ra` is the first register store of the prologue
  movz_movn, ext_ins, seb_seh, min_max   Allegrex/MIPS32 idioms
  fp_frame                `move s8, sp` frame pointer (unoptimized code)

Known families (measured on hst-decomp's matched code and on compiled probes):
  mwccpsp 3.0.1 (Metrowerks)   move as `or`... see docs/TOOLCHAIN.md for the measured table
  psp-gcc 3.3.3 (Sony SDK)     move as `addu`, ra saved at the frame top, movz/movn
  pspsnc 1.2 (SN Systems SNC)  move as `or`, `li 0` as `ori`, ra stored after the s-registers
"""
from __future__ import annotations

import argparse
import json
import struct
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpmodinfo as MI  # noqa: E402

KEYS = ("functions", "words", "move_or", "move_addu", "li0_ori", "li0_addiu", "li0_move", "branches", "likely",
        "frames", "ra_top", "ra_first", "movz_movn", "ext_ins", "seb_seh", "min_max", "fp_frame", "jal", "j",
        "jr_ra", "nop", "bal")


def count(ws: list[int], c: Counter) -> None:
    c["functions"] += 1
    c["words"] += len(ws)
    frame = 0
    if ws and ws[0] >> 16 == 0x27BD and ws[0] & 0x8000:
        frame = 0x10000 - (ws[0] & 0xFFFF)
        c["frames"] += 1
    stores = [w for w in ws[:32] if w >> 26 == 0x2B and (w >> 21) & 31 == 29]
    ra = next((w for w in stores if (w >> 16) & 31 == 31), None)
    if ra is not None and frame:
        c["ra_top"] += (ra & 0xFFFF) == frame - 4
        c["ra_first"] += stores[0] == ra
    for w in ws:
        op, rs, rt, rd, sh, fn = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, (w >> 6) & 31, w & 63
        if w == 0:
            c["nop"] += 1
            continue
        if op == 0:
            if fn == 0x25 and (rt == 0 or rs == 0) and rd:
                if rs == 0 and rt == 0:
                    c["li0_move"] += 1
                else:
                    c["move_or"] += 1
            elif fn == 0x21 and (rt == 0 or rs == 0) and rd:
                if rs == 0 and rt == 0:
                    c["li0_move"] += 1
                else:
                    c["move_addu"] += 1
            elif fn in (0x0A, 0x0B):
                c["movz_movn"] += 1
            elif fn in (0x2C, 0x2D):
                c["min_max"] += 1
            elif fn == 8 and rs == 31:
                c["jr_ra"] += 1
            if fn == 0x25 and rs == 29 and rt == 0 and rd == 30:
                c["fp_frame"] += 1
            if fn == 0x21 and rs == 29 and rt == 0 and rd == 30:
                c["fp_frame"] += 1
        elif op == 0x0D and rs == 0 and (w & 0xFFFF) == 0:
            c["li0_ori"] += 1
        elif op == 0x09 and rs == 0 and (w & 0xFFFF) == 0:
            c["li0_addiu"] += 1
        elif op == 0x1F and fn in (0x00, 0x04):
            c["ext_ins"] += 1
        elif op == 0x1F and fn == 0x20 and sh in (0x10, 0x18):
            c["seb_seh"] += 1
        elif op == 3:
            c["jal"] += 1
        elif op == 2:
            c["j"] += 1
        if op in (4, 5, 6, 7) or (op == 1 and rt in (0, 1)):
            c["branches"] += 1
        if op in (0x14, 0x15, 0x16, 0x17) or (op == 1 and rt in (2, 3)):
            c["branches"] += 1
            c["likely"] += 1
        if op == 1 and rt == 0x11 and rs == 0:
            c["bal"] += 1


def summary(c: Counter) -> dict:
    def ratio(a: str, b: str) -> float | None:
        t = c[a] + c[b]
        return round(c[a] / t, 3) if t else None
    li0 = c["li0_ori"] + c["li0_addiu"] + c["li0_move"]
    return {"functions": c["functions"], "words": c["words"],
            "move_or_share": ratio("move_or", "move_addu"),
            "li0_ori_share": round(c["li0_ori"] / li0, 3) if li0 else None,
            "li0_addiu_share": round(c["li0_addiu"] / li0, 3) if li0 else None,
            "likely_per_branch": round(c["likely"] / c["branches"], 3) if c["branches"] else None,
            "ra_top_per_frame": round(c["ra_top"] / c["frames"], 3) if c["frames"] else None,
            "ra_first_per_frame": round(c["ra_first"] / c["frames"], 3) if c["frames"] else None,
            "movz_movn_per_kword": round(1000 * c["movz_movn"] / c["words"], 2) if c["words"] else None,
            "ext_ins_per_kword": round(1000 * c["ext_ins"] / c["words"], 2) if c["words"] else None,
            "min_max_per_kword": round(1000 * c["min_max"] / c["words"], 2) if c["words"] else None,
            "fp_frames": c["fp_frame"], "raw": {k: c[k] for k in KEYS}}


def functions_of(path: Path) -> list[tuple[int, int]]:
    out = []
    for line in path.read_text(encoding="utf-8").splitlines():
        if line.strip() and not line.startswith("#"):
            a, b = line.split()[:2]
            out.append((int(a, 16), int(b, 16)))
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("profile")
    p.add_argument("--elf", required=True, type=Path)
    p.add_argument("--functions", required=True, type=Path)
    p.add_argument("--by-range", type=lambda s: int(s, 0), default=0, help="also summarise per address bucket")
    p.add_argument("--only", type=Path, help="only the functions whose starts are listed (one hex start per line)")
    p.add_argument("--json", type=Path)
    o = sub.add_parser("object")
    o.add_argument("objects", nargs="+", type=Path)
    args = ap.parse_args()
    if args.cmd == "object":
        c: Counter = Counter()
        for path in args.objects:
            obj = path.read_bytes()
            import lbpmatch as M
            secs = M.elf_sections(obj)
            for i, (name, s) in enumerate(secs):
                if name.startswith(".text") and s[5]:
                    data = obj[s[4]:s[4] + s[5]]
                    syms = sorted((v, sz) for n, v, sz, info, sh in M.elf_symbols(obj) if sh == i and info & 15 == 2)
                    for v, sz in syms or [(0, len(data))]:
                        count(list(struct.unpack_from(f"<{sz // 4}I", data, v)), c)
        print(json.dumps(summary(c), indent=1))
        return 0
    elf = MI.Elf(args.elf.read_bytes())
    fns = functions_of(args.functions)
    if args.only:
        keep = {int(x.split()[0], 16) for x in args.only.read_text(encoding="utf-8").split("\n") if x.strip()}
        fns = [f for f in fns if f[0] in keep]
    total: Counter = Counter()
    buckets: dict[int, Counter] = {}
    for a, b in fns:
        o = elf.v2o(a)
        if o is None or b <= a:
            continue
        ws = list(struct.unpack_from(f"<{(b - a) // 4}I", elf.data, o))
        count(ws, total)
        if args.by_range:
            count(ws, buckets.setdefault(a // args.by_range, Counter()))
    rep = {"module": summary(total)}
    if args.by_range:
        rep["ranges"] = {f"0x{k * args.by_range:08x}": summary(v) for k, v in sorted(buckets.items())}
    out = json.dumps(rep, indent=1)
    if args.json:
        args.json.write_text(out + "\n", encoding="utf-8")
    print(json.dumps({k: v for k, v in rep["module"].items() if k != "raw"}, indent=1))
    if args.by_range:
        for k, v in rep["ranges"].items():
            print(f"{k} fns {v['functions']:5} move_or {v['move_or_share']} li0_ori {v['li0_ori_share']} "
                  f"likely {v['likely_per_branch']} ra_top {v['ra_top_per_frame']} ra_first {v['ra_first_per_frame']} "
                  f"movz {v['movz_movn_per_kword']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
