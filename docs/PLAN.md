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
- T2 for `EBOOT.BIN` is built by `tools/lbpbuild.py`; its design is the next section. `EBOOT.BIN` is a static
  executable (ET_EXEC at 0x08804000, no relocation sections), so hst-decomp's `hstreloc.py` (relocation tables of a
  relocatable PRX) has nothing to generate here; the shifted build (T3) needs the address references of the
  scaffolding reconstructed first (below).

## Whole-module build (T2) design (`tools/lbpbuild.py`, written 2026-10-28 before the code)

Goal (owner, 2026-10-28): rebuild the whole decrypted `EBOOT.BIN` from the accepted sources plus retail-derived
scaffolding, prove the produced file is byte-identical to the retail module, and count T2 the strict way: only bytes
of that identical image that the compiled objects of accepted sources produce. The rules are hst-decomp's
(`docs/COMPLETION.md` there: scaffolding is tier 0 and never counts), adapted to a static executable.

**Inputs.** The accepted ledger only (`data/accepted-ledger.jsonl`, read and validated through `tools/lbpproof.py`:
journal chain, digests, one owner per byte). A source whose file no longer has the proof's SHA-256 is left out (its
range becomes scaffolding). Every proved source is compiled by `tools/lbpmatch.py` itself (`LBPMATCH_BUILD_ROOT` =
`build/whole/<module>/match`, `--parallel 4` at most, in chunks that fit the Windows command line), so the compilers,
profiles, flags and include path are exactly the matcher's; a source must come back `EXACT` and its object, with
GCC's random-seed digits normalized (`lbpproof.normalized_object`), must have the SHA-256 its proof records, so the
build links the proven object and nothing else. The retail module is read only through the campaign
(`lbp-config.json` `campaign_root`); every retail-derived file the build writes stays under the gitignored `build/`.

**Where each byte comes from.** The image is tiled; every tile is one of:

1. *Compiled code* (counted): the claimed range `[start, end)` of a proof, cut from the source's object. An object
   can hold more code than the claim (a library file compiled whole, an inline function GCC emitted after the
   target): the code inputs (`.text`, `.text.*`, `.gnu.linkonce.t.*`) are laid out as the isolated link laid them
   out (file order, each aligned, from the address that puts the target at `start`; `lbpproof.Elf.layout`), and only
   the part inside the claim is kept. A partly kept section is sliced with its relocations; every symbol of a removed
   part (and the section symbol of a sliced section) becomes a unique undefined symbol that the link script defines
   at the address it had in the isolated link, so each relocation the kept code carries resolves to the same value
   the proof saw. A `helpers=` source keeps only its target (each helper's bytes belong to the helper's own proof).
2. *Compiled data* (counted): the sections a proof compared besides code (`rodata=`, `data=`, `sdata=`, the
   `.gnu.linkonce` data objects at their symbol-map addresses), laid out in file order from the header address as
   the isolated link did. One owner per byte here too: GCC's merged constants (retail was built with constant
   merging; the profiles use `-fno-merge-constants`, so several sources place the same 4-byte pool word at one
   address) and data a library file shares between functions are placed once, by the first proof in ledger order
   whose data range does not overlap an already placed one; every other copy is checked equal to retail, left out of
   the link like the linker's constant merging would, and its references resolve (as above) to the address the
   kept copy occupies. Placed `.bss`/`.sbss` objects are linked at their header addresses in the zero-initialised
   area (same overlap rule); they have no file bytes, so they place symbols but add nothing to the image or to T2.
3. *Scaffolding code* (never counted): each retail function no accepted source covers, one tile per function of the
   boundary map (`data/functions-EBOOT.BIN.txt`, from the campaign ledger), so the link order of the code is the
   retail function order, with compiled tiles in between.
4. *Scaffolding data* (never counted): every other byte of every loaded section (the rest of `.init`, `.fini`, the
   import stubs `.sceStub.text`, the `.lib.ent*`/`.lib.stub*` tables, module info, `.rodata.sceResident`,
   `.rodata.sceNid`, unplaced `.rodata`/`.data`, `.eh_frame`, `.gcc_except_table`, `.ctors`, `.dtors`, `.jcr`), one
   tile per maximal uncovered run.
5. *Container* (never counted, until reconstructed): the ELF header, the program header, the file padding before the
   first section and between sections, `.shstrtab` and the section header table.

Scaffolding is cut from the user's own decrypted module at build time into one generated relocatable object
(`build/whole/<module>/<mode>/scaffold.o`, written by the tool: one section per tile, alignment 1, no assembler).
Because the executable is static, scaffolding needs no relocations; it cannot move (that is the T3 work below).

**Layout and link order.** `link.ld` is generated from the retail section headers: one output section per loaded
retail section, at its retail address and in retail order, and inside each one the tiles in address order, each
placed with `. = <offset>;` and bracketed by `__lbp_at_<addr>` / `__lbp_end_<addr>` symbols; the zero-initialised
area is a NOLOAD `.bss` of the retail size. Everything else is discarded. Alignment and padding are therefore
reproduced explicitly: a gap between two tiles of a section can only be a tile of its own (there is none left
untiled), the linker never chooses a position (a tile that does not start where planned is an error, read back
from the marker symbols), and an overlap is an error (ld cannot move the location counter backwards). Names the
objects leave undefined are defined by `syms.ld` from `symbols/EBOOT.BIN.txt` and address names, exactly as the
matcher defines them, except where a compiled object defines the name itself (then the linker resolves it). One
psp-ld run links everything (`-nostdlib -T link.ld`, entry from the retail header).

**Image and comparison.** The output file is assembled from the parts: each loaded section's bytes are the linked
section's contents at the retail file offset; the container parts are scaffolding. The build compares every linked
section with the retail section (address, size, bytes) and the SHA-256 of the whole file with the retail module's
(`data/modules.json`). It writes `build/whole/<module>/<mode>/image.bin`, `report.json` (sections, sources,
special cases, figures) and `provenance.json`: the whole file as runs `[file offset, length, kind, source]` with
kind `source-code`, `source-data`, `scaffold-code`, `scaffold-data` or `container`; every byte is in exactly one run.

**T2, strict.** T2 bytes = bytes of the identical image in `source-code` and `source-data` runs, i.e. produced by
the compiled object of an accepted source in the whole link (gates 1-4 and 6 of `docs/COMPLETION.md`). The tool
refuses to report a T2 figure (writes `t2: refused`) unless the whole image is byte-identical to retail, every
section compares equal and every tile sits where it was planned; scaffolding and the container never count; a
source that could not be placed in the whole link counts nothing. The denominator is every byte of the module file
(4,085,872 for `EBOOT.BIN`; the strict scope adds the other modules of `data/modules.json`). Two builds are made:
`private` (every accepted source) and `public` (the sources the public tree publishes: origin classes outside
`tools/lbppublish.py` `EXCLUDED_CLASSES`; held-back Sony code is scaffolding, supplied from the user's executable).
`tools/lbppublish.py` `figures()` reads the public report and counts, over its public scope, the T2 bytes of
published sources, only when that report is identical and was built from the current ledger.

**Not T2 yet (later tiers).** T3 (gate 5) needs a shifted build: with no relocation sections in a static
executable, the address references inside scaffolding must first be reconstructed (from the compiled objects'
relocations and analysis of the unmatched code), which is a project of its own. The container could be generated
from the layout (as `hstreloc.py write_module` does for HST) and `.ctors`/`.dtors`/`.eh_frame` entries placed from
the objects that emit them; both stay scaffolding until a proof covers them.

## Phase 7: data, review, strict

- Data as source (initialised and read-only data, string pools, jump tables from switch statements), relocation
  tables from objects, module info and import/export tables from source.
- Human review of every source (names, types; no conflicting declarations), then the strict figure.

## Never

- Lower a figure, shrink the scope, or count anything but `EXACT` from the pinned toolchain.
- Push, publish, or send game-derived material anywhere.
