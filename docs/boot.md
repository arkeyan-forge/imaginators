# Imaginators: the first boots

> **Purpose:** how far each boot of Imaginators got, what stopped it, and the fix · **Status:** current (2026-11-04) · **Tags:** [Xbox] [Alchemy] [Imaginators] [V]

Runs: the Europe disc, offscreen, disk audio, scratch settings and saves (`private/imaginators/run.sh <name> <seconds>`), one at a
time. Presses come from `SKY_PRESS_FILE`, written by `private/imaginators/drive.sh` while the game runs (both local, not in git:
they hold the disc's path).

## 1. The shader cache
The first boot drew nothing but the clear colour: every draw was skipped (`no translated vertex/pixel shader`). A 3-minute run with
`SKY_DUMP_SHADERS` (the menus and the movies) gave 1190 containers; `SKY_GAME=imaginators tools/shaders/build_cache.sh <disc>
<dump>` merged them with the disc's (`shaders=igz:/archives/shaders_xenon.pak` in `game.txt`): **1190 of 1190 translate**, none
rejected [V]. Later runs in the menus, the opening and the first level log no missing shader [V].

## 2. Function entries the analyzer missed
Two aborts, `Indirect call to unrecompiled guest code`:
- `ctr=0x82D779B8` (2 min in, the menus): an 8-byte adapter after zero padding (`lwz r4,64(r4)`, then `b` into its neighbour).
  A scan of `.text` for every non-zero run after zero padding that the first mapping did not know found **437** of them (430 of 8
  bytes, the rest 12 to 164), added to `config/Imaginators.toml` [V].
- `ctr=0x8304AD98` (the opening's loading): a 16-byte flag setter after a `blr` (`li r11,1`, two `stb`, `b` back), reached only
  through a `lis`/`addi` address. A scan of every `lis`/`addi` constant into `.text` that is neither a known start, a branch target,
  a switch-table label nor an inline table of addresses (the jump tables built in the code) found **3**: the two setters and a catch
  funclet at `0x836C7FC0`, added too [V].
After both, the game runs 14 minutes from the boot into the first level without a fault [V].

## 3. The way in
The intro movies, the title ("Appuie sur Start"), then **Start** opens the software licence (`softwarelicense.pak`, 50 pages, French
on this disc): it is accepted with **Y**, not A (the screen's own glyphs say so). Then the save (`IMAGINATORS_OPTIONS`,
`IMAGINATORS_0`), the difficulty choice, the opening (`fmv01_cinematic.bk2`, `level_508.pak`, the `c508_*` cutscenes), the portal:
the emulated portal's figure (`SKY_PORTAL_PLACE=new:9`, Eruptor) is read and shown in its vortex, then the part sets screen, then
the first level, on foot with Eruptor [V]. 30 fps (the default limit), 1180 draws a frame taking 4.4 ms of our renderer [V].

## 4. SKY_LEVEL
`engines/alchemy/zone_request.cpp`, SuperChargers' zone request redirect, now shared: Imaginators' zone lookup is `sub_82D7B450`
(a strict shape match of SuperChargers' `sub_82DF1C58`), its zone enter `sub_82D82B50` (0.66; it reads the request global
`0x837E7A64` +44 and calls the lookup at `0x82D82C1C`, as SuperChargers' does), read in the generated code [V].
