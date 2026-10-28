#!/usr/bin/env python3
"""Write the reference-function sample manifest from a fresh lbpmatch.py run.

Runs the matcher over every source under src/, then records, for each EXACT source, the module
range, symbol, source digest and target-byte digest, together with digests of the compiler,
wibo and the PSPDEV binutils used. Fails (exit 1) if any source is not EXACT under the profile.

Usage: lbpsample.py --out <manifest.json>
"""
from __future__ import annotations

import argparse
import hashlib
import json
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpconfig as CFG
import lbpmatch as M


def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def wsl_sha256(path: str) -> str:
    out = subprocess.run(["wsl.exe", "-e", "sh", "-c", f"sha256sum {path}"], capture_output=True, text=True).stdout
    return out.split()[0] if out.strip() else ""


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", type=Path, required=True)
    args = ap.parse_args()
    compilers = CFG.host_path("mwcc_builds_dir")
    wibo = CFG.host_path("wibo_exe")
    native_dir = M.native_dir()
    summary_path = M.ROOT / "build" / "sample-summary.json"
    rc = subprocess.run([sys.executable, str(Path(M.__file__)), "--all", "--quiet", "--json", str(summary_path)]).returncode
    summary = json.loads(summary_path.read_text(encoding="utf-8"))
    cache: dict = {}
    functions = []
    for row in summary:
        src = M.ROOT / row["source"]
        h = M.parse_header(src)
        data, seg = M.module_bytes(cache, h["module"])
        off = seg["file_offset"] + h["start"] - seg["start"]
        target = data[off:off + h["end"] - h["start"]]
        functions.append({
            "module": h["module"], "start": f"0x{h['start']:08x}", "end": f"0x{h['end']:08x}",
            "words": (h["end"] - h["start"]) // 4, "symbol": h["symbol"], "lang": h["lang"],
            "source": row["source"], "source_sha256": sha256(src), "target_sha256": hashlib.sha256(target).hexdigest(),
            "status": row["status"],
        })
    compiler = compilers / M.PROFILE["build"] / "mwccpsp.exe"
    native_compiler = wsl_sha256(f"{native_dir}/builds/{M.PROFILE['build']}/mwccpsp.exe")
    native_wibo = wsl_sha256(f"{native_dir}/wibo")
    manifest = {
        "schema": "hst-decomp.reference-function-sample.v1",
        "status": "exploratory evidence for the toolchain in `profile`; not a ledger record",
        "profile": {
            "compiler": "Metrowerks mwccpsp 3.0.1 build " + M.PROFILE["build"] + " (github.com/decompme/compilers)",
            "compiler_sha256": sha256(compiler),
            "native_copy_sha256_matches": native_compiler == sha256(compiler),
            "wibo": "wibo 1.2.0 (github.com/decompals/wibo), licence status owner-accepted",
            "wibo_sha256": sha256(wibo),
            "native_wibo_sha256_matches": native_wibo == sha256(wibo),
            "flags": M.PROFILE["flags"],
            "per_source_settings": "a source may carry `#pragma opt_strength_reduction off` (per-object setting in the retail build)",
            "linker": "PSPDEV psp-ld -EL -Ttext=<start>, symbols from symbols/<module>.txt or FUN_/DAT_ address names",
            "symbol_map_sha256": {p.name: sha256(p) for p in sorted((M.ROOT / "symbols").glob("*.txt"))},
            "comparison": "linked .text bytes of the function equal the retail bytes [start, end) exactly; no masking",
        },
        "exact": sum(1 for f in functions if f["status"] == "EXACT"),
        "total": len(functions),
        "words_exact": sum(f["words"] for f in functions if f["status"] == "EXACT"),
        "functions": functions,
    }
    args.out.write_text(json.dumps(manifest, indent=1) + "\n", encoding="utf-8")
    print(f"exact {manifest['exact']}/{manifest['total']} ({manifest['words_exact']} words) -> {args.out}")
    return 0 if rc == 0 and manifest["exact"] == manifest["total"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
