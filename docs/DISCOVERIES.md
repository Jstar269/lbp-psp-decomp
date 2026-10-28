# Discoveries in the retail executable

What LittleBigPlanet (PSP, UCUS98744, disc version 2.00) still shows of its development, read from the retail
`EBOOT.BIN` and, for section 3, the archives of the same disc. No prototype build was used: where a public description of a prototype relates to a finding, it is
cited as a lead, never as a source of data. Addresses are the retail EBOOT's (static executable loaded at
0x08804000); `FUN_xxxxxxxx` names are the inventory names in `data/functions-EBOOT.BIN.txt`.

Method: string references and call targets of every function (the project's `lbpstrings.py` scan, extended to the
whole inventory with a call and pointer index), Ghidra pseudocode of the functions involved, and the import names
in `symbols/EBOOT.BIN.txt`. Confidence: **high** = read directly from the code or data; **medium** = an inference
from the code that a test on hardware could still overturn; **low** = a guess.

Prototype leads (public text only):

- Hidden Palace, "LittleBigPlanet (Jun 29, 2009 prototype)": a PSP alpha from an SCE Cambridge QA disc; debugging
  enabled by default, a debug menu opened with L+R at any time; Create Mode present but unpolished; its main
  archive `lbp_archive.psarc` is not encrypted, "unlike the final game".
- The October 30, 2009 BetaTrial (UCET01373): no public description was found.

## 1. Debug menu and other debug leftovers

| # | Finding | Evidence | Confidence | Prototype lead |
| --- | --- | --- | --- | --- |
| 1.1 | **No debug menu in retail.** No menu text, option names or console strings exist in the executable, and no code tests L and R held together on the pad. | All 2,263 strings of six or more characters in the read-only data read; every pseudocode test of the shoulder bits searched (see 1.2). The one `(x & 0xc00) == 0xc00` test, `FUN_089e0c5c`, is a GUI widget's state flags (it tints a child widget), not the pad. | high | Alpha: L+R debug menu. It was compiled out of the Master build, not merely hidden. |
| 1.2 | **Pad bits follow the PS2/PS3 layout.** The pad reader `FUN_08aa05d0` (virtual, `Gk::HIDPads`, reading `sceCtrlReadBufferPositive`) copies PSP L (0x100) to bit 0x400 and R (0x200) to bit 0x800, the L1/R1 positions of the PlayStation pad layout, so engine code written for L1/R1 works unchanged. It also drops all input while the HOLD switch is on and keeps the HOME bit separately. | `FUN_08aa05d0` / `FUN_08aa079c` pseudocode. Many Create Mode functions (0x08a09394-0x08a15c0c) test `& 0xc00`, i.e. "either shoulder". | high (mapping); medium (that it serves shared PS3 code) | - |
| 1.3 | **Dev-kit host file system fallback survives.** At start-up the game asks `sceUmdCheckMedium`; with a UMD it mounts `disc0:/PSP_GAME/USRDIR`, without one it mounts `host0:` (the PC of a development kit) through FIOS. The module loader does the same: `disc0:/PSP_GAME/USRDIR/modules/prx/` or `host0:modules/prx/`. | `FUN_08928a04` (system init, called from the boot function `FUN_089ec234`), `FUN_089f7c7c` (PRX loader), FIOS media constructors `FUN_08ab3a48` (UMD) and `FUN_08ab353c` (host/Memory Stick). | high | Consistent with an executable built to also run from a dev-kit PC; no switch needed. |
| 1.4 | **Debug print calls kept, formatting removed.** Two methods of an audio-system class (`FUN_089184b0`, `FUN_089184ec`, vtable at 0x08bb67b0) still print a 1 KB stack buffer with `printf("%s", ...)`, but the code that filled the buffer is gone. Two network loggers (`FUN_0889a8d0`, 56 format strings from 35 callers, among them the adhoc share and transfer state messages and `*******FINGERPRINT*********`; `FUN_088996bc`, the Unity exception reasons) are empty variadic functions. | Pseudocode of the four functions; call sites with the strings passed in. | high | Relates to the alpha's "debugging features enabled by default": in the Master build the logging expands to nothing (medium). |
| 1.5 | **One developer message still printed.** A virtual method `FUN_08a7ed9c` (vtable slot at 0x08bc860c, updates object states) begins with `printf("the debugger is full of lies")`. | Pseudocode; `FUN_08b9fb0c` is newlib `printf`. | high | - |
| 1.6 | **Fatal error screen.** `FUN_089f7f74` (12 callers: "Display List Buffer Overrun!", "Out of memory error", "Out of Volatile memory error", "Out of MovieHeap memory error") disables interrupts, fills the whole of video memory with one 32-bit value, prints `FatalError: %s` and, when asked, hangs. On retail hardware a fatal error therefore shows a solid-colour screen. | Pseudocode; imports `sceKernelCpuSuspendIntr`, `sceGeEdramGetAddr`, `sceGeEdramGetSize`. | high (code); medium (what the colour looks like) | - |
| 1.7 | **Build identity.** The read-only data holds the label `2_04_November-09_Master_16.00` (no code reference), SCREAM audio "built Nov 4 2009 11:01:11", the Unity network layer built the same day, snd_stream Oct 1 2009 and SCE-RT 3.04 of Jul 17 2009. The retail EBOOT is the 4 November 2009 Master build, 13 days before the US release. | String scan and the version-print functions of each library. | high | - |
| 1.8 | **A leftover format call in `main`.** `main` (`FUN_088048a8`) formats the address of a small accessor (`FUN_088a7e7c`) with `"0x%x\n"` into a stack buffer that is never used. | Pseudocode of `main`. | high (code); low (purpose: a load-address print for the debugger is likely) | - |

Not found: a debug or free camera (`simplecam` is the ordinary camera node of the pause and photo views), a frame
counter, memory or profiler overlay text, cheat flags, or a command-line/argument parser.

## 2. Create Mode internals

| # | Finding | Evidence | Confidence | Prototype lead |
| --- | --- | --- | --- | --- |
| 2.1 | **Pop-it menu catalogue.** Menu groups: tools bag (corner edit, capture object, lethal electric/flame/gas, unlethalise, material changer, flip, sticker eraser, costume reset/save, camera trigger radius/viewfinder), shapes (square, circle, right-angle triangle, pentagon, hexagon, octagon, arrow, 5- and 6-point star; positive and negative paint shapes), connectors (bolt, motor bolt, wobble bolt, sprung bolt, piston, string, rod, elastic, winch, spring), creature (mouth, eye, protected and unprotected brain, leg, wheel, navigator), special (emitter, rocket), switches (sensor, magnetic key, magnetic, sticker, 2-way, 3-way, grab, button), gameplay kit (score bubble, entrance, checkpoint, scoreboard, prize bubble, camera), character (jetpack), danger (spikes x1, spikes x3, impact bomb, trigger bomb), race (start, flipped start, end). | Menu id strings used by `FUN_08986704`, `FUN_08986c14`, `FUN_08984b70`, `FUN_0898617c`; icon table below. | high | Alpha: Create Mode present. |
| 2.2 | **Icons for tools the menu may not offer.** The global GUI texture table (203 entries at 0x08bdb900, used by `FUN_08973240` and others) loads icons for a photo booth (`gameplay_photo_booth`), a copy tool (`func_copy`), a painting tool (`popit_painting`), "my photos" (`popit_my_photos`) and `popit_hearted`; no Pop-it id string names them. That test is weak: retail items such as the creature eye and the four right-angle triangles have no id string either, so the menu also reaches items another way. The icon files are on the disc (section 3). | Table walk; id-string search. | low (that they are unused); a run of Create Mode settles it | PS3 LBP has these tools; their icons may have stayed in a shared table. |
| 2.3 | **Sound objects.** Boombox and speaker meshes (`meshes/gadgets/sound_objects/...`) are referenced by the gadget registry (`FUN_0880a740`) and two object functions, a `speaker` id is used by `FUN_089a9c3c`, and the tweak menu has sound trigger icons (on destruction, on switch, on impact, player proximity). | String references; the icon files are on the disc (section 3). | high (present in code); whether the menu offers them was not run | - |
| 2.4 | **Magic mouth traces.** `magic_mouth_sounds` (used by `FUN_0899338c`), a `fake_magic_mouth_metadata` table entry and a `magic_mouth_bubble` GUI texture exist. The name "fake" suggests a stand-in record for a PS3 feature. | String references. | high (strings); low (meaning) | - |
| 2.5 | **PS3 voice banks.** The gibberish voice table (`FUN_089813d8`) lists 37 PSP banks and 43 banks under `audio/sfx_banks/gibberish/PS3/...`. | String table. Whether the PS3 banks are on the disc: section 3. | high (table) | - |
| 2.6 | **Object type names** used by the gadget factory (`FUN_08805ac8`, `FUN_0880663c`): piston, elastic, spring, string, camzone, navigator, SensorSwitch, MagneticKey, MagneticKeySwitch, StickerSwitch, GrabSwitch, Emitter, motorbolt, sprungbolt, wobblebolt, scorebubble, jetpack, impactexplosive, triggerexplosive, checkpoint, entrance, prizebubble, brainU, brainP. Sackboy's state machine names: kStateNone, Biped, Jump, Suicide, SuicideAbort, JetPack, DeathGeneric, DeathElectric, StunnedFireRunning, Spawn, GrabIdle, Push, Pull, Emote, Death, SelfDestruct. | String references. | high | - |
| 2.7 | **Resource types** registered by `FUN_08934e10`: animation, skeleton, skin, mesh, sfx_crossfade, sfx_bank, level_biff, object_biff, material_biff, catalog_biff, background_biff, gui_biff, audio_biff, music_biff, frontend_biff, frontend_res, lams, popit_group, popit_metadata, costume_data, costume_material, binary_file, archive. | String references. | high | - |
| 2.8 | **Save data on the Memory Stick** (`memstick_profile/`): `myprofile/` (ps.bin, feconfig.bin, player.aut, story.sco/.dlv/.slv, category.plk, theme.plk, curcost/defcost .cst and .cbf, lbpkey.bin), `myobjects/myobj.ilb` + `mysha1.bin`, `communityobjects/cmobj.ilb` + `comsha1.bin`, `mycostumes/mycst.ilb`, `mylevels`, `mydownloads`, `mygriefs`; an install area `memstick_install/` (with `archives/gui.arc`) and `memstick_patch`. **Create Mode's undo/redo history is written to the Memory Stick** as `undoredo/bs%02X.lbf` (level states) and `undoredo/bcs%02X.cbf` (costume states) (`FUN_0883b8fc`, `FUN_0883e504`). Level metadata travels as a text block `objection / marqee / ltype / lid / owner / rootlev` (`FUN_089ed154`, `FUN_089ed25c`). | String references and the format calls. | high | - |
| 2.9 | **Placeholder materials.** The material loader `FUN_089efc90` names `materials\default\default_placeholder.mip` and `materials\default\ultradensedeuterium.mip` (backslash paths, unlike the rest of the game). | Pseudocode. | high | - |
| 2.10 | **Not-used markers.** Two functions that build fixed resource names use `thisisnotused.nop` and `thisisnotused2.nop` (`FUN_08a4bb3c`, `FUN_08a4c998`, `FUN_08a4cd24`). | String references. | high (code); low (meaning) | - |

## 3. Resource and level indexing

The disc holds two archives, `PSP_GAME/USRDIR/lbp_archive.arc` (202 MB) and `PSP_GAME/USRDIR/archives/gui.arc`
(4.6 MB, the GUI set the game installs to the Memory Stick), plus 93 Bink movies, `movies/tutorial_list.bin` and the
network dialog PRX. The archive reader is a FIOS media layer the game registers as `dearchiver`
(constructor `FUN_08920eb8`, vtable 0x08bb69b8, open/read `FUN_0891fa80` and `FUN_0891fec4`); payloads are decoded
on the resource thread `rm_data` (`FUN_0892e978`).

| # | Finding | Evidence | Confidence | Prototype lead |
| --- | --- | --- | --- | --- |
| 3.1 | **Archive layout.** A 28-byte header (an identifier, version 1, entry count), a table of 12-byte entries (32-bit name hash, offset, stored size), then a 16-byte MD5 of the table, which the reader checks. | `FUN_0891fa80`; the table checksum verified on both archives. | high | Alpha: `lbp_archive.psarc` (Sony's PSARC). Retail uses this simpler `.arc` instead. |
| 3.2 | **Encryption.** Header, table, checksum and every entry are encrypted with AES-128 in counter mode through the cipher registry of the SNC-built library (`FUN_08b1bc10` registers it as cipher 3 with 16-byte blocks; init `FUN_08b19fc0`, mode 5; decrypt `FUN_08b19354`; call site `FUN_08926d58`). The key is kept obfuscated in read-only data. | Pseudocode; standard AES tables in the library; decryption verified by the table MD5. Key and counter layout: private evidence only. | high | Alpha: archive not encrypted. So encryption was most likely added between June and November 2009. |
| 3.3 | **Compression.** Decrypted entries are LZO1X streams, decoded by a codec the game calls through a function pointer (`FUN_089266bc` -> `FUN_08ae436c`, which checks LZO's worst-case output bound). | Pseudocode; 8,347 entries decode as LZO1X, the other 4,563 are stored uncompressed. | high | - |
| 3.4 | **Name hash.** The 32-bit name is CRC-32 (zlib polynomial, no final inversion) of `"/" + path`, lower case with forward slashes. | Checked against the paths the EBOOT names. | high | - |
| 3.5 | **Levels reference resources by path.** Decoded level, catalog and object files contain the paths of what they use (for example a level names its `.background.biff`), so names can be recovered from the data itself. | Analyzer. | high | - |
| 3.6 | **Names are often built at run time.** Story levels, costume catalogs, Pop-it metadata and the Memory Stick install set are most likely found through names the code assembles (`%s/catalog%s`, `%s/lookup%s`, `%s_%04d.arc`, `%s/patch?data_v=%u`, per-language folders, numbered avatars and news), not through a stored path. Inside the data no entry refers to another by its 32-bit hash (tested on 120 catalog, level, object and background files: only chance matches). | Analyzer; format strings in the EBOOT. | high (no hash references); medium (which builders cover which entries) | - |
| 3.7 | **A second, PS3-style patch and DLC path.** The executable can fetch data patches (`%s/patch?data_v=%u&exe_v=%u`) and load numbered extra archives (`%s_%04d.arc`) and `additional_content`; the disc holds no extra archive. | String references. | high (code present); low (whether it was ever used) | - |

### Analyzer results on the owner's disc (counts only)

The analyzer (`tools/lbparc.py` in the maintainers' report folder, not published: it needs the key location)
decrypts and decodes every entry locally, recovers names from the EBOOT's strings and from the strings inside every
decoded entry (paths are packed without separators, so runs are cut at known resource extensions), and builds the
"entry names entry" graph from the paths the EBOOT names. Its per-entry output stays private.

| | lbp_archive.arc | gui.arc | both |
| --- | --- | --- | --- |
| entries | 8,937 | 3,973 | 12,910 |
| LZO1X-compressed / stored | 8,278 / 659 | 69 / 3,904 | 8,347 / 4,563 |
| named by a recovered path | | | 6,872 (53%) |
| UTF-16 text tables (one shared header, no path anywhere) | 3,128 | 0 | 3,128 |
| other entries no path names (EBOOT or data) | 1,130 | 1,780 | 2,910 |
| entries with the same contents as another entry | | | 431 |
| names present in both archives | | | 68 |

What this shows and does not show:

- Every named entry is mentioned somewhere (in the EBOOT or in another entry); the analyzer found no named entry
  that only exists on the disc.
- The 2,910 entries with no path anywhere (textures, Pop-it metadata, animations and others, judged by their headers)
  are the candidates for unreferenced data. They are only candidates: they may be reached through names the code
  builds (3.6). Reachability from the EBOOT's own paths covers 1,432 entries; that figure is a lower bound for the
  same reason (45 of the 48 level files, all 193 costume catalogs and all 37 font files are reached only through
  built names).
- Create Mode leftovers checked against the disc: the icons of 2.2 (photo booth, copy, painting, my photos,
  hearted) are present as distinct images; the GUI catalog names seven further Pop-it icons, with their metadata,
  that the EBOOT never names (their names are in the private evidence); the boombox and speaker models (2.3), the
  magic mouth texture (2.4), both placeholder materials (2.9) and all 43 `PS3/` gibberish banks (2.5) are present. The `thisisnotused` names (2.10) and the
  EU credits movie `movies/90_credits_mov_eu.bik` named in the EBOOT are not on this disc.
- `movies/` on the disc skips number 88 in the numbered tutorial movies, and holds an extra `tutorial01.bik`.

Next steps for a complete unreferenced list: decode the level-list and costume-catalog formats (3.6) so that built
names join the graph, and name the text tables by language.
