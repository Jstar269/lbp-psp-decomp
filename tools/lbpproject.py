#!/usr/bin/env python3
"""Project description shared by the LBP decomp tools: the modules this repository reconstructs.

Everything module-specific comes from `data/modules.json` (written once the disc's modules are identified), so the
tools carry no hard-coded module names. Each module entry has:

    name            module name used in source headers (`module=...`), e.g. EBOOT.BIN
    src_dir         directory under src/ (and wip/) that holds the module's sources
    kind            "game" (the game's own executable code) or "sony-prx" (a Sony system-library module the game ships)
    origin          where the module comes from on the disc
    sha256, size    digest and size of the decrypted module
    load_segments   the loadable segment(s): flags, start, file_offset, file_end, memory_end
    functions_file  data/functions-<module>.txt (reviewed function boundaries, `start end` in hex per line)
    function_count  number of lines in functions_file

    python tools/lbpproject.py            list the modules
"""
from __future__ import annotations

import json
import sys
from functools import lru_cache
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MODULES_FILE = ROOT / "data" / "modules.json"
TITLE = "LittleBigPlanet (PSP)"
HEADER_TAG = "LBPMATCH"
# Function-boundary statuses (data/functions-<module>.txt third column): "reviewed" (a person checked it), "agreed"
# (two independent boundary tools agree: Nakagawa analyze.py and Ghidra), "auto" (one tool only). The matching tools
# work on all three; "disputed" spans (the tools disagree) are left out of work queues until resolved, and "stub" spans
# (import stubs in .sceStub.text, generated from the import table by the build) are never matched by a C source.
USABLE_BOUNDARY = frozenset({"reviewed", "agreed", "auto"})


@lru_cache(maxsize=1)
def spec() -> dict:
    if not MODULES_FILE.exists():
        return {"modules": []}
    return json.loads(MODULES_FILE.read_text(encoding="utf-8"))


def modules() -> list[dict]:
    return list(spec().get("modules", []))


def src_dirs() -> dict[str, str]:
    """{module name: src/ subdirectory}."""
    return {m["name"]: m["src_dir"] for m in modules()}


def game_modules() -> tuple[str, ...]:
    """Modules holding the game's own code (library identification and clone searches run over these)."""
    return tuple(m["name"] for m in modules() if m.get("kind", "game") == "game")


def default_module() -> str:
    names = game_modules()
    return names[0] if names else "EBOOT.BIN"


def main() -> int:
    for m in modules():
        print(f"{m['name']:32} src/{m['src_dir']:16} {m.get('kind', 'game'):9} {m['size']:>9} B  "
              f"{m.get('function_count', 0):>6} functions  ({m['origin']})")
    if not modules():
        print(f"no modules described yet ({MODULES_FILE} missing)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
