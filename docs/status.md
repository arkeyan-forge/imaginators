# Skylanders Imaginators (imaginators)

> **Purpose:** which disc Imaginators needs, where the port stands, and where to start · **Status:** current (2026-11-04) · **Tags:** [Xbox] [XDK] [Alchemy] [Imaginators]

## Disc
| | |
|---|---|
| Release | 2016, Toys for Bob; Redump "Skylanders - Imaginators (Europe) (Fr,Nl)" (the only disc tried) |
| Title ID, media ID, version | `41560930`, `0133F901`, `0x00000004` [V] |
| `default.xex` SHA-256 | `1c6d7e05...` (full value in `game.txt` and `info.cpp`), 25739264 bytes |
| Engine | **Alchemy**, SuperChargers' line, XDK **2.0.21256** [V] ([research.md](research.md)) |

The disc stays outside git; everything derived from it is in `private/imaginators/`.

## Status (day 2, 2026-11-05)
A new game goes from the boot to the **first level, on foot with Eruptor**, without a fault (14-minute run); 30 fps at the default
limit ([boot.md](boot.md)).

| Step | Result |
|---|---|
| Codegen | one new instruction (`mulhd`); 440 function entries the analyzer missed, added to the config ([boot.md](boot.md) 2) |
| Shaders | 1190 of 1190 translate; no missing shader in the menus, the opening and the first level |
| Story | the movies, the title, the licence (Y), the difficulty, the opening and its cutscenes, the portal's figure, the first level |
| Figures | the emulated portal's Eruptor (`new:9`) is read and played |
| SKY_LEVEL | `SKY_LEVEL=<map>` enters `2016/<map>/<map>` instead of the first level (`hub_2016`: the hub) [V] |
| Test | `tools/regress/imaginators_hub.sh`: a new game to the hub, then a continue from its save: PASS (no fault, 30 fps, sound, saves) [V] |

## The finishing details (day 2, 2026-11-05)
Each checked in a run (`private/runs/`); [V] seen, [?] not checked.

| Detail | Result |
|---|---|
| Glyphs | the fonts' two button pictures redrawn for the device in use (SuperChargers' way; the body one is new, 128x250, with a Back): the pause menu's hints as PS5, Switch, keyboard and 360 [V] ([art.md](art.md), "Button pictures") |
| Portal prompt | **the Toy Box opens by itself** on Player 1 at "place your Skylander", Return seats the figure, the game takes it, the Toy Box closes (run `imgC1`) [V]; player 2 and the Dead state not run [?] ([toybox.md](toybox.md), "The portal prompt") |
| Text and voices | French or Dutch from the settings (`language`, `voice_language`); voices follow the text or take the other; the movies' voice track follows [V] ([boot.md](boot.md) 5) |
| Ultrawide | 21:9 (scene 1696x720, Hor+ 96.4 degrees) and 32:9 (scene 2048x576, 118.4 degrees) in the hub [V] ([ultrawide.md](https://github.com/arkeyan-forge/forge/blob/main/docs/runtime/gpu/ultrawide.md#imaginators-alchemy-imaginators-v-2026-11-05)) |
| Movies | the logos in `skip_intro_movies`; `fmv01` skipped with Y after a first press shows the game's prompt [V] ([boot.md](boot.md) 7) |
| Save task | Swap Force's race is not in this game's code: no hook [V] ([boot.md](boot.md) 6) |
| 60 FPS, scale 2 | the first level 59.6, the hub 58.4 before the Metal lossless compression (GPU-bound with the full-resolution scene; 60.0 with `original_resolution=1`); **now the hub and all 12 levels (`level_500`-`510`, `512`) hold 59.8-60.0, no drop to 30** (2026-11-05) [V] ([renderer_threads.md](https://github.com/arkeyan-forge/forge/blob/main/docs/runtime/gpu/renderer_threads.md)) |

## Next
1. The hub test in `tools/test_all.sh`.
2. The hub at a locked 60 with the full-resolution scene (the GPU's cost, stream P); player 2's prompts; the parts' names in the
   creation editor ([toybox.md](toybox.md)).
