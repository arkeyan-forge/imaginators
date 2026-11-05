// Imaginators' adapter: day 1, the minimum (runtime/game.h). No portal prompt, glyphs, intro list, language or first-level
// redirect yet. The game asks for present interval 2 and paces itself on it, as SuperChargers and Swap Force:
// presentIntervalPacesGame (at fps_limit 60 it held 33.3 ms a frame without it) [V].
#include "game.h"

namespace
{
    const game::Adapter g_adapter = { g_gameInfo, nullptr, false, nullptr, {}, {}, false, nullptr, {}, {}, true };
}

const game::Adapter& game::Current() { return g_adapter; }
