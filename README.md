# LittleBigPlanet (PSP) decompilation

A matching decompilation of LittleBigPlanet for PSP (UCUS98744, disc version 2.00): C and C++ sources that compile,
with the original compiler toolchain reconstructed as closely as measured, to the same bytes as the game's executable.
A function counts only when its compiled and linked bytes equal the original exactly.

This repository contains **no game data**: no executable, no decrypted module, no disassembly or byte dumps, no keys.
You build and verify it against **your own copy of the game**. It is not affiliated with or endorsed by Sony
Interactive Entertainment or Media Molecule.

## What is here and what is not

- `src/`: the reconstructed game code, and matched open-source library code the game links (newlib, zlib 1.2.3, GNU
  libstdc++/libsupc++), each under its own licence (see the notice in each library source).
- Not here: Sony SDK code the game links (FIOS, SCREAM audio, SceRT networking, the SNC-built library, Sony's crt0,
  and small SDK functions identical to ones in Hot Shots Tennis) and code not attributed yet. A build takes those
  functions from your own executable. `ORIGINS.json` gives the origin class of every source.
- `symbols/`: the names this project gives to addresses in the executable (no code or data from the game).
- `data/public-figures.json`: progress over the public scope (the game's code and the open-source libraries); the
  Sony code above stays in the strict 100% scope (`docs/COMPLETION.md`) but not in the public figure.
- Whole-module build (tier T2, `tools/lbpbuild.py`, measured by the maintainers 2026-10-28; it reads the accepted
  proofs, which stay private): the executable rebuilt from these sources plus scaffolding cut from the owner's own copy
  is byte-identical to the original (SHA-256 equal); the published sources produce 393,372 code bytes of it, 13.752%
  of the public scope (scaffolding never counts).

## Requirements

- A Windows host with WSL (Ubuntu, `libc6-i386`); Python 3.12 or newer, no third-party packages.
- The compilers: GCC 4.0.4 with the pspdev Allegrex patch and this project's measured Allegrex changes (built from
  the GNU and pspdev sources by `toolchain/gcc4/`; the evidence is in `docs/TOOLCHAIN.md`), and the decomp.me PSP
  compiler kits (their binutils 2.14 assembler, and the few objects built with other compilers). PSPDEV binutils (`psp-ld`, `psp-objcopy`, `psp-objdump`).
- Your own LittleBigPlanet disc image, and a way to decrypt its executable on your machine.

## Setup (bring your own disc)

1. Decrypt `PSP_GAME/SYSDIR/EBOOT.BIN` from your own disc locally into `inputs/` (gitignored).
2. `copy lbp-config.example.json lbp-config.json`, fill in your paths, `python tools/lbpconfig.py check`.
3. Describe and check your module (its SHA-256 must equal `data/modules.json`), make the function list from it, and
   create the campaign directory:

   ```
   python tools/lbpmodinfo.py inputs/<...>/EBOOT.elf
   python tools/lbpfuncs.py --elf inputs/<...>/EBOOT.elf --out data/functions-EBOOT.BIN.txt
   python tools/lbpbootstrap.py --out campaign --module EBOOT.BIN=inputs/<...>/EBOOT.elf
   ```

4. Verify every source: `python tools/lbpmatch.py --all --parallel 4`.

## Licensing

The project's own code, tools and documentation are GPL-3.0-or-later (`LICENSE`). Third-party code keeps its own terms:
newlib (the notices in each source; `third_party/newlib/`), zlib 1.2.3 (zlib licence), GNU libstdc++/libsupc++
(GPL-2.0-or-later with the runtime exception, distributed here under GPL-3.0-or-later). `REUSE.toml` maps every file
(`python tools/lbpreuse.py check`); `THIRD_PARTY.md` has the details. The GPL grant covers only this project's
contributions, not the original game.

## Contributing

See `CONTRIBUTING.md` (method, file format, the fake-match gate) and `docs/GUIDE.md`. Never post bytes,
disassembly or decompiler output of the game anywhere.
