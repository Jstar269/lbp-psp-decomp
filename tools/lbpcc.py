#!/usr/bin/env python3
"""Compile one scratch C/C++ file with the retail MWCC profile and print its disassembly (no header, no link).

    python tools/lbpcc.py probe.cpp [--lang c99|c++] [--build 219] [--extra "-opt nopeephole"]

For quick probes (does this spelling fold? which vtable offset does this virtual call use?) where lbpmatch.py
would need an LBPMATCH header and a retail address. The relocations are printed, so symbol references read as
`DAT_xxx` against each lui/lo pair instead of linked numbers. Builds other than 219 are for experiments only:
no source may depend on one. Adopted from the ds10 lane's asmdump.sh.
"""
from __future__ import annotations

import argparse
import shlex
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpmatch as M


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", type=Path)
    ap.add_argument("--lang", choices=("c99", "c++"), help="default: c++ for .cpp, c99 otherwise")
    ap.add_argument("--build", default=M.PROFILE["build"], help="mwccpsp build under the native kit (default 219)")
    ap.add_argument("--extra", default="", help="extra compiler flags")
    ap.add_argument("--cc", default=M.PRIMARY_PROFILE, help="compiler profile (default: the primary profile "
                    f"{M.PRIMARY_PROFILE}); any header cc= value of lbpmatch.py")
    args = ap.parse_args()
    src = args.source.resolve()
    lang = args.lang or ("c++" if src.suffix == ".cpp" else "c99")
    out = M.ROOT / "build" / "lbpcc"
    out.mkdir(parents=True, exist_ok=True)
    obj = shlex.quote(M.to_wsl(out / f"{src.stem}.o"))
    if args.cc in M.GCC_PROFILE_NAMES:
        g = M.gcc_profiles()[args.cc]
        bprefix = f"-B {g['B']} " if g["B"] else ""
        xlang = "-x c++" if lang == "c++" else "-x c"
        # the i386 compiler cannot stat files on /mnt/c: compile a copy in a native temporary directory
        M.run_wsl([f"t=$(mktemp -d /tmp/lbpcc.XXXXXX) && cp {shlex.quote(M.to_wsl(src))} $t/ && cd $t && "
                   f"{g['driver']} {bprefix}-c {g['flags']} {xlang} {args.extra} -o obj.o {shlex.quote(src.name)}; "
                   f"[ -f obj.o ] && cp obj.o {obj} && {M.pspdev_bin()}/psp-objdump -dr {obj} | tail -n +6; "
                   f"cd / && rm -rf $t"], "lbpcc")
        return 0
    M.run_wsl([f"cd {shlex.quote(M.to_wsl(src.parent))} && MWCIncludes={shlex.quote(M.to_wsl(M.ROOT / 'include'))} "
               f"$N/wibo $N/builds/{args.build}/mwccpsp.exe {M.PROFILE['flags']} -lang {lang} {args.extra} "
               f"-o {obj} {shlex.quote(src.name)} && {M.pspdev_bin()}/psp-objdump -dr {obj} | tail -n +6"],
              "lbpcc", M.native_dir())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
