# Plan: LittleBigPlanet (PSP) to byte-identical 100%

The target is hst-decomp's strict definition ([COMPLETION.md](COMPLETION.md)): every byte of every module in
`data/modules.json` rebuilt from source with the original toolchain, in place, data as source, relocatable,
reproducible from a clean checkout plus the owner's disc, and human-reviewed. The headline figure is the strict tier;
function-at-a-time matches are tier 1 only. The phases below are ordered so that each one multiplies the next, which
is what made hst-decomp's progress possible (clone families, library sources, then agent lanes at scale).

## Phase 0: intake (done 2026-10-26: UCUS98744 v2.00, the owner's own copy)

- `python tools/lbpintake.py --iso <your own disc image>`: PARAM.SFO identity, decrypt (the `decryptor` setting,
  read-only), describe every module. Check each output is a 32-bit LE MIPS ELF/PRX.
- Write `data/modules.json` (one `python tools/lbpmodinfo.py <module> --modules-entry NAME:SRC_DIR:KIND:ORIGIN` per
  module) and bootstrap the campaign: `python tools/lbpbootstrap.py --out campaign --module NAME=PATH ...`.

## Phase 1: every byte classified (function boundaries)

- `python tools/lbpfuncs.py --elf <module> --out data/functions-<module>.txt` (99.7% of starts on hst-decomp's
  reviewed lists; the misses are switch-heavy regions and small functions after them).
- Second opinion: Ghidra headless with the Allegrex extension (the HST campaign's Ghidra 12.1.4 + `ghidra-allegrex`
  install; copy the extension into `ghidra/settings/` for this project), export a function CSV, then
  `python tools/lbpbounds.py --elf ... --toml ... --ghidra ...` marks `agreed`/`disputed`. Review every disputed span
  by hand (disassembly with `lbpdis.py`), then set the status to `reviewed`.
- Data regions: classify `.rodata`, `.data`, `.bss` objects by relocation targets (needed for phase 6).

## Phase 2: toolchain

- Identify the compiler(s) from `.comment`, the fingerprints of `python tools/lbptoolchain.py profile`, and compiled
  probes; record the evidence in [TOOLCHAIN.md](TOOLCHAIN.md).
- If the game code is mwccpsp (as HST): the HST profile and every HST codegen fact apply (`docs/reference/`); find the
  build (210/219 or an older decomp.me build) by compiling matched library functions with each.
- If it is psp-gcc (Sony SDK GCC): profiles `gcc131-*`/`gcc171-*` exist; a later Sony GCC (the `ins $zero` idiom HST
  could not match) needs a kit that is not available yet: record and block, never fake.
- If it is SN Systems SNC (`pspsnc`): add an `snc*` compiler profile to `lbpmatch.py` (Windows binary, run natively or
  under wibo like mwccpsp) with its own flags search; prove it on library/runtime functions first.
- Pin the toolchain in a manifest (hashes of compilers, flags, include/, the matcher) as hst-decomp's
  `data/toolchain-manifest.json`; a change re-verifies every accepted source.

## Phase 3: libraries first (the cheapest exact bytes)

- `python tools/lbpxclone.py --tag x1 --cc gcc` (and `--cc mwcc` if the game code is mwccpsp): every function that is
  byte-identical to an hst-decomp exact source up to addresses (Sony SDK runtime, newlib, Metrowerks runtime,
  container templates) becomes an exact source here, verified by the matcher.
- newlib: `python tools/lbplib.py index` (HST's built newlib 1.13-1.15 objects for both GCC kits) then
  `python tools/lbpnewlib.py --tag n1`; build further newlib/GCC configurations if the SDK release differs.
- Sony SDK libraries (libc wrappers, libgu/libgum-like graphics helpers, sound, network, utility): match once, then
  clone; record SDK version evidence (import library versions, module SDK version words).
- C++ runtime (operator new/delete, RTTI, exception tables, static init/fini): from the identified compiler's runtime.

## Phase 4: names

- Import stubs: names from NIDs (Nakagawa Recomp's NID corpus; `lbpmodinfo.py --nids` lists them).
- Exports, module_start/stop, strings (`lbpstrings.py`), assert/log format strings, RTTI type names and vtables
  (C++), file names in debug strings: name only what evidence proves; everything else keeps `FUN_`/`DAT_`.

## Phase 5: game code at scale

- `lbpfamilies.py` ranks clone families (one match unlocks all members, `lbpclone.py`).
- Ghidra pseudocode export (`ghidra/run_commit_decompile.ps1`, needs a project imported with the Allegrex
  extension) then `lbpgen.py` (mechanical translation, exact only), `lbpcat.py` (why candidates miss),
  `lbpperm.py` (permuter for near misses).
- Agent lanes as hst-decomp ran them (Sonnet lanes ~15 verified matches per lane-hour on near-miss queues; Opus for
  families and large functions); every harvested source is re-verified by the matcher. Port `hstqueue.py`,
  `hstattempts.py`, `hstnearmiss.py` and the lane brief when lanes start.

## Phase 6: whole-module build (tiers T2, T3)

- Port hst-decomp's `hstbuild.py` + `hstreloc.py` (+ tests): link every exact object in retail order, scaffold the
  rest from the owner's module (tier 0), generate relocation tables and the container, compare by SHA-256; then the
  shifted build (`--shift`) for gate 5.
- Translation units: group functions into objects by address runs and per-object settings (strength reduction, inline
  depth in MWCC; optimisation level in GCC), as hst-decomp learned.

## Phase 7: data, review, strict

- Data as source (initialised and read-only data, string pools, jump tables from switch statements), relocation
  tables from objects, module info and import/export tables from source.
- Human review of every source (names, types; no conflicting declarations), then the strict figure.

## Never

- Lower a figure, shrink the scope, or count anything but `EXACT` from the pinned toolchain.
- Push, publish, or send game-derived material anywhere.
