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
