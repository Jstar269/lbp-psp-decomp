#!/usr/bin/env python3
"""Classify every reconstructed source by where its code came from, and write the origin manifest.

    python tools/lbporigin.py [--out ORIGINS.json] [--check] [--list CLASS]

LittleBigPlanet's game code and most of its libraries were built by the same Sony psp-gcc, so (unlike hst-decomp,
where MWCC meant game and GCC meant Sony SDK) the compiler says nothing about origin. The class comes from evidence:

  newlib        the note says `Library source: newlib ...` / `Identified as newlib ...` (third-party terms: newlib's)
  zlib          the note says the source is zlib 1.2.3 (`zlib 1.2.3 (zlib.net ...`), zlib licence
  libgcc        the note says `Library source: libgcc ...` (GCC runtime library)
  libstdc++     in the GNU libstdc++/libsupc++ region of data/origin-regions.json (GPL + GCC runtime exception)
  game          in the game-objects region of data/origin-regions.json
  startup       in the crt0/crtbegin region (Sony crt0 is SDK code)
  sony-sdk      in the libraries region and not proven open-source by its note: Sony FIOS, SCREAM, snd_stream,
                SceRT, the SNC library, and library code not attributed yet; or a cross-project clone of an
                hst-decomp Sony SDK source
  sony-prx      a source of a Sony system module (module kind `sony-prx` in data/modules.json)
  unattributed  in a region of data/origin-regions.json marked unattributed, or outside every region

Order: a note that proves newlib/zlib/libgcc first; then a cross-project clone (`Clone of hst-decomp src/...`) takes
its exemplar's evidence from hst-decomp's ORIGINS.json: newlib there -> newlib, Sony SDK there (sony-prx,
gcc-unattributed) -> sony-sdk, wherever the LBP copy sits (owner decision 2026-10-28: the 8-60 byte game-region
copies of hst-decomp SDK functions are held back); then the module kind; then the address region of the header's
start (the innermost region wins). A clone inside this project (`Clone of src/... (lbpclone.py ...)`) inherits its
exemplar's class when that class came from such evidence (a note or a cross-project exemplar); otherwise its own
region decides (a clone of a game function inside a library is library code).

The result is written to ORIGINS.json (path relative to the repository root -> class, sorted) and a table of counts,
source bytes and retail code bytes per class is printed. tools/lbppublish.py decides from the classes what may leave
the private repository.

    --check       compare ORIGINS.json with a fresh classification instead of writing it (exit 1 when stale)
    --list CLASS  print the paths of one class
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lbpconfig as CFG
import lbpmatch as M

ROOT = M.ROOT
CLASSES = ("game", "newlib", "zlib", "libgcc", "libstdc++", "startup", "sony-sdk", "sony-prx", "unattributed")
SOURCE_TREES = ("src", "wip")
SOURCE_SUFFIXES = (".c", ".cpp")
REGIONS = ROOT / "data" / "origin-regions.json"
NOTE_CLASSES = (("newlib", re.compile(r"Library source: newlib|Identified as newlib")),
                ("zlib", re.compile(r"zlib 1\.2\.3 \(zlib\.net")),
                ("libgcc", re.compile(r"Library source: libgcc")))
CLONE_NOTE = re.compile(r"^/\* Clone of (src/\S+) \(lbpclone\.py tag \w+\)")
XCLONE_NOTE = re.compile(r"^/\* Clone of hst-decomp (src/\S+) \(lbpxclone\.py tag [\w./-]+\)")
HST_SDK = {"sony-prx", "gcc-unattributed"}   # hst-decomp's Sony SDK classes


def sources(root: Path = ROOT) -> list[Path]:
    return sorted(p for tree in SOURCE_TREES if (root / tree).is_dir()
                  for p in (root / tree).rglob("*") if p.suffix in SOURCE_SUFFIXES)


def rel(path: Path, root: Path = ROOT) -> str:
    return path.relative_to(root).as_posix()


def load_regions(path: Path = REGIONS) -> dict[str, list[tuple[int, int, str]]]:
    doc = json.loads(path.read_text(encoding="utf-8"))
    regions = [(int(r["start"], 16), int(r["end"], 16), r["class"]) for r in doc["regions"]]
    for _s, _e, c in regions:
        if c not in CLASSES:
            raise SystemExit(f"{path}: unknown class {c!r}")
    return {doc["module"]: regions}


def region_class(regions: dict, module: str, start: int) -> str:
    """The class of the innermost region holding `start` (the smallest one), else unattributed."""
    hits = [(e - s, c) for s, e, c in regions.get(module, []) if s <= start < e]
    return min(hits)[1] if hits else "unattributed"


def module_kinds(root: Path = ROOT) -> dict[str, str]:
    p = root / "data" / "modules.json"
    if not p.exists():
        return {}
    doc = json.loads(p.read_text(encoding="utf-8"))
    mods = doc["modules"] if isinstance(doc, dict) else doc
    return {m["name"]: m.get("kind", "") for m in mods}


def hst_origins() -> dict[str, str]:
    """hst-decomp's ORIGINS.json (read-only), for cross-project clones; empty when hst_root is not configured."""
    try:
        root = CFG.get("hst_root")
    except SystemExit:
        return {}
    p = Path(root) / "ORIGINS.json" if root else None
    return json.loads(p.read_text(encoding="utf-8")) if p and p.exists() else {}


def own_manifest(root: Path) -> dict[str, str]:
    """This tree's ORIGINS.json: the public tree ships it, and its cross-project clones are classified from it where
    hst-decomp itself is not at hand (their exemplar's class is the evidence, recorded when the tree was built)."""
    p = root / "ORIGINS.json"
    try:
        return json.loads(p.read_text(encoding="utf-8")) if p.exists() else {}
    except ValueError:
        return {}


def evidence_class(path: Path, hst: dict, fallback: dict | None = None, root: Path = ROOT) -> str | None:
    """The class the file's own note or cross-project exemplar proves, or None. `fallback` is this tree's own
    ORIGINS.json, used for a cross-project clone when hst-decomp's manifest does not know its exemplar."""
    text = path.read_text(encoding="utf-8", errors="replace")
    head = text[:3000]
    for cls, rx in NOTE_CLASSES:
        if rx.search(head):
            return cls
    lines = text.split("\n", 2)
    m = XCLONE_NOTE.match(lines[1]) if len(lines) > 1 else None
    if m:
        theirs = hst.get(m.group(1))
        if theirs is None and fallback:
            mine = fallback.get(rel(path, root))
            return mine if mine in ("newlib", "sony-sdk") else None
        if theirs == "newlib":
            return "newlib"
        if theirs in HST_SDK:
            return "sony-sdk"
    return None


def own_class(path: Path, regions: dict, kinds: dict, hst: dict, fallback: dict | None = None,
              root: Path = ROOT) -> str:
    """Class from the file's own header and note (clones within this project are resolved by the caller)."""
    cls = evidence_class(path, hst, fallback, root)
    if cls:
        return cls
    h = M.parse_header(path)
    if kinds.get(h["module"]) == "sony-prx":
        return "sony-prx"
    return region_class(regions, h["module"], h["start"])


def classify(root: Path = ROOT, regions: dict | None = None, hst: dict | None = None) -> tuple[dict[str, str], list[str]]:
    """({path: class}, warnings) for every source under src/ and wip/."""
    regions = load_regions(root / "data" / "origin-regions.json") if regions is None else regions
    hst = hst_origins() if hst is None else hst
    fallback = own_manifest(root)
    kinds = module_kinds(root)
    files = sources(root)
    exemplar_of: dict[str, str] = {}
    result: dict[str, str] = {}
    warnings: list[str] = []
    for path in files:
        key = rel(path, root)
        first = path.read_text(encoding="utf-8", errors="replace").split("\n", 2)
        m = CLONE_NOTE.match(first[1]) if len(first) > 1 else None
        if m:
            exemplar_of[key] = m.group(1)
        else:
            result[key] = own_class(path, regions, kinds, hst, fallback, root)
    for path in files:
        key = rel(path, root)
        if key in result:
            continue
        seen, cur = [key], exemplar_of[key]
        while cur in exemplar_of and cur not in seen:   # clone of a clone
            seen.append(cur)
            cur = exemplar_of[cur]
        if cur in result:
            # the exemplar's evidence (note, cross-project exemplar) carries over; otherwise the clone's address
            # region decides (a clone of a game function inside a library is library code)
            proven = evidence_class(root / cur, hst, fallback, root)
            result[key] = proven or own_class(path, regions, kinds, hst, fallback, root)
        else:
            warnings.append(f"{key}: exemplar {cur} is not a source here; classified from the clone's own header")
            result[key] = own_class(path, regions, kinds, hst, fallback, root)
    return dict(sorted(result.items())), warnings


def summarize(classes: dict[str, str], root: Path = ROOT) -> dict[str, dict[str, int]]:
    out = {c: {"sources": 0, "source_bytes": 0, "code_bytes": 0} for c in CLASSES}
    for key, cls in classes.items():
        path = root / key
        header = M.parse_header(path)
        row = out[cls]
        row["sources"] += 1
        row["source_bytes"] += path.stat().st_size
        row["code_bytes"] += header["end"] - header["start"]
    return out


def load_manifest(path: Path) -> dict[str, str]:
    return json.loads(path.read_text(encoding="utf-8"))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", type=Path, default=ROOT / "ORIGINS.json", help="manifest path (default ORIGINS.json)")
    ap.add_argument("--check", action="store_true", help="compare the manifest with a fresh classification")
    ap.add_argument("--list", choices=CLASSES, metavar="CLASS", help="print the paths of one class")
    args = ap.parse_args()
    classes, warnings = classify()
    for w in warnings:
        print(f"warning: {w}", file=sys.stderr)
    status = 0
    if args.check:
        old = load_manifest(args.out) if args.out.exists() else {}
        if old != classes:
            changed = sorted(k for k in set(old) | set(classes) if old.get(k) != classes.get(k))
            print(f"{args.out.name} is stale: {len(changed)} paths differ (first: {', '.join(changed[:3])})")
            status = 1
        else:
            print(f"{args.out.name} is current")
    else:
        args.out.write_text(json.dumps(classes, indent=0, sort_keys=True) + "\n", encoding="utf-8", newline="\n")
        print(f"wrote {args.out} ({len(classes)} paths)")
    if args.list:
        for key, cls in classes.items():
            if cls == args.list:
                print(key)
        return status
    table = summarize(classes)
    print(f"{'class':14s} {'sources':>8s} {'source bytes':>13s} {'retail code bytes':>18s}")
    for cls in CLASSES:
        row = table[cls]
        print(f"{cls:14s} {row['sources']:8d} {row['source_bytes']:13d} {row['code_bytes']:18d}")
    total = {k: sum(table[c][k] for c in CLASSES) for k in ("sources", "source_bytes", "code_bytes")}
    print(f"{'total':14s} {total['sources']:8d} {total['source_bytes']:13d} {total['code_bytes']:18d}")
    for tree in SOURCE_TREES:
        n = sum(1 for k in classes if k.startswith(tree + "/"))
        print(f"  {tree}/: {n} sources")
    return status


if __name__ == "__main__":
    raise SystemExit(main())
