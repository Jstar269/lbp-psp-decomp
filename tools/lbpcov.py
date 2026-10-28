#!/usr/bin/env python3
"""Exact-match coverage per module, measured against the campaign ledger's function list.

    python tools/lbpcov.py [--json out.json]            PRESENCE-based: the sources present in src/ (fast, no proof)
    python tools/lbpcov.py --proofs [--json out.json]   PROOF-based: only the accepted ledger's ranges (tools/lbpproof.py)

Denominator: every function the ledger lists for the module (any boundary status), in code bytes.
Numerator: functions whose start has an exact source in src/ (sources are only installed after lbpmatch
reported EXACT; run a full `lbpmatch.py --all` regression to re-prove them). A source whose header span
covers several ledger functions (multi-function span compare) counts each function it covers.
"""
from __future__ import annotations

import argparse
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpmatch as M


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--json", type=Path)
    ap.add_argument("--proofs", action="store_true",
                    help="count only accepted-ledger ranges (tools/lbpproof.py) instead of the sources present in src/")
    args = ap.parse_args()
    ledger = json.loads((M.CAMPAIGN / "ledger" / "campaign.json").read_text(encoding="utf-8-sig"))
    spans = defaultdict(list)
    kinds = defaultdict(lambda: defaultdict(int))
    if args.proofs:
        import lbpproof
        for p in lbpproof.accepted_proofs():
            spans[p["module"]].append((int(p["start"], 16), int(p["end"], 16)))
            kinds[p["module"]][p["cc"].split("-")[0][:6]] += 1
    else:
        for p in (M.ROOT / "src").rglob("*"):
            if p.suffix in (".c", ".cpp"):
                h = M.parse_header(p)
                spans[h["module"]].append((h["start"], h["end"]))
                kinds[h["module"]][h.get("cc", M.PRIMARY_PROFILE).split("-")[0][:6]] += 1
    print("mode: " + ("accepted ledger (proofs from verification runs)" if args.proofs else
                      "presence-based (sources present in src/; fast, not proofs: --proofs counts the accepted ledger)"))
    rows = []
    tot = defaultdict(int)
    for m in ledger["modules"]:
        fns = m.get("functions", [])
        if not fns:
            continue
        cov = sorted(spans.get(m["name"], []))
        starts = {s for s, _ in cov}
        n_all = len(fns)
        b_all = sum(f["end"] - f["start"] for f in fns)
        n_rev = sum(1 for f in fns if f.get("boundary_status") == "reviewed")
        hit = [f for f in fns if f["start"] in starts or any(s <= f["start"] and f["end"] <= e for s, e in cov)]
        n_ex = len(hit)
        b_ex = sum(f["end"] - f["start"] for f in hit)
        rows.append({"module": m["name"], "functions": n_all, "reviewed": n_rev, "exact": n_ex,
                     "code_bytes": b_all, "exact_bytes": b_ex,
                     "pct_bytes": round(100 * b_ex / b_all, 3) if b_all else 0.0,
                     "sources_by_cc": dict(kinds.get(m["name"], {}))})
        for k in ("functions", "reviewed", "exact", "code_bytes", "exact_bytes"):
            tot[k] += rows[-1][k]
    tot = dict(tot, module="ALL", pct_bytes=round(100 * tot["exact_bytes"] / tot["code_bytes"], 3))
    rows.append(tot)
    for r in rows:
        print(f"{r['module']:28} {r['exact']:6}/{r['functions']:<6} fns  {r['exact_bytes']:9}/{r['code_bytes']:<9} B"
              f"  {r['pct_bytes']:7.3f}%  (boundary-reviewed {r['reviewed']})")
    if args.json:
        args.json.write_text(json.dumps(rows, indent=1), encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
