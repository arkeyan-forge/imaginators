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

## Status (day 1, 2026-11-04)
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

## Next
1. The hub test in `tools/test_all.sh`.
2. 60 FPS at scale 2 (the `perf-090` lane), glyphs, the portal prompt, the Creation Crystals in the Toy Box, ultrawide, the
   language hooks, the launcher's art and menu music: the 0.9.0 plan.
