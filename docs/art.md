# Imaginators: the launcher's pictures and menu theme on the disc

> **Purpose:** where Imaginators keeps the logo, background, portraits and menu theme the launcher reads from the player's disc · **Status:** current (2026-11-04) · **Tags:** [Xbox] [Alchemy] [Imaginators] [V]

The manifest is `games/imaginators/art.json` (names only; the reader is SuperChargers': IGA v11 big-endian, IGZ v9).

## Where they are [V]
| What | Archive | Entry | Result |
|---|---|---|---|
| Logo | `archives/legal.pak` | `textures@!UI_TFB!TitleLogo!TitleLogo_2016_001` | 1024x724, opaque: the logo in its burst of light on black (the title screen's picture) |
| Background | `archives/ap_loading.pak` | `textures@!UI_TFB!MenuComponents!Backgrounds_Water` | 344x344, the menus' blue gradient |
| Portraits | `archives/toycollectionmaterials.pak` | `materialInstances/ToyCollection/Collection_<Toy>_<Variant>.igz` | **565** |
| Menu theme | `archives/inter_streamed_bank.pak` | `mu_main_menu_2016_apm_heroes_all.wav,0,48000,kDefaultFormat,40,1,0,1` | 43.9 s, 48 kHz stereo, mean -15 dB, peak -0.2 dB |

Proof: `SSAArtTest`'s disc extraction run once with a temporary `IMAGINATORS_ISO` call (logo 1, background 1, title icon 1, 565
portraits, 2.0 s); `Arkeyan-Builder --iso <disc> --menu-music <file.wav> --kit <scratch kit>` (`@done`). The disc test is not
permanent: `TestDisc`'s later checks (upgrades, drawn icons) are the older games'.

## Open
- The logo has no transparency. The disc's other logos: `prototitle.pak`'s `TitleLogo_2016` is the prototype "Skylanders 2016" one;
  the start screen's `MainMenuBackground.pak` `imaginators_TM` (a `,111.igz` entry) is not found by the reader [?].
- The background is a plain gradient; the menus are 3D scenes, as SuperChargers'.

## Button pictures (glyphs, 2026-11-05) [Alchemy] [Imaginators] [V]
SuperChargers' way ([its art.md](https://github.com/arkeyan-forge/superchargers/blob/main/docs/art.md), "Button pictures"): the game composes its strings on the CPU, so
the buttons inside every text come from two pictures named in the fonts, which `glyphs::MemoryImage` (adapter `GlyphImages`) redraws
in guest memory for the device in use.

| Picture | Where | Cells |
|---|---|---|
| Info font's buttons, 256x168, 32-bit tiled ARGB | `fonts/ProximaNova-Info.igz` (`languagestartup.pak`), `igImage2` 1 | **SuperChargers' and Swap Force's own** (the same XXH3 of the first 4096 bytes, `7360B650D459A892`): SuperChargers' cells [V] |
| Body font's buttons, **128x250**, 32-bit tiled ARGB | `fonts/ProximaNova-Body.igz` (`essentialui.pak`), `igImage2` 1, `3B9E95737FB43E23` | SuperChargers' 128x209 layout plus one row: A 1,1-38,39 · B 44,1-80,39 · Y 85,1-123,39 · X 2,42-39,80 · LB 43,49-106,75 · LT 4,83-40,121 · RT 49,83-86,121 · RB 3,131-66,157 · LS 73,125-110,161 · RS 5,166-42,202 · **Back** 47,172-83,196 and 89,172-125,196; the D-pad at 2,205-43,243 has no glyph and stays |

The two "Back" pills are the same picture (0 pixels differ). The font's glyph records (48 bytes after its letters: `8, 1, code << 16`,
the advance, the size, then u0, v0, u1, v1 over 128x250) give each cell its character: A `0x298`, B `0x5E`, Y `0x60`, X `0x7E`, LB
`0x5B`, RB `0x5D`, LT `0x3C`, RT `0x3E`, LS `0x7B`, RS `0x7D`, the D-pad `0xA4`, the pills `0x86` and `0x2020`: the dagger "†" in
Windows-1252 and in Unicode, one button under two encodings, so both are Back (the 360's Back shows that left arrow).
Proof (run `imgB1`, `SKY_LEVEL=hub_2016`, 2560x1080, `SKY_GLYPHS_SCRIPT=ps5:120,switch:132,key:144,xbox360:156`, Start at the hub):
`body font buttons 128x250 found in guest memory`, `info font buttons 256x168 found ...`, each `drawn as` playstation, nintendo,
keyboard, xbox360; the pause menu's hints in the shots: cross and circle; B and A (Nintendo, by position); Space and X keycaps; the
360's A and B. The movie's skip prompt shows the Y as the keyboard's V (run `imgD1`). The Back pills were not met in a run [?].
How (30 min): the two archives extracted from the disc (`tools/shaders/xdvdfs.py`) into `private/imaginators/disc/`, SuperChargers'
scratch tools (picture list and hash, untile and boxes) run on them, the body picture looked at; the records read in the entry.
