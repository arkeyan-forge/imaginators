// Skylanders Imaginators: the guest functions the runtime hooks and the guest data it reads. Same names as the other
// games' addresses.h. A hook the game does not define is compiled out. A data global is a constexpr in namespace game, 0
// while the address is not known. Never reuse another game's address: every one here was re-found in Imaginators' own
// binary (tools/sigmatch against SuperChargers', Trap Team's and Swap Force's inventories, tools/xmatch.py as the second
// witness; games/imaginators/docs/research.md has the numbers).
#pragma once

// D3D (runtime/d3d/*.cpp): XDK D3D9 2.0.21256, Trap Team's and SuperChargers'. All eleven are strict matches (1.0) of
// SuperChargers' functions, Resolve included (Trap Team's: 0.62, shape 0.87); tools/xmatch.py offsets against Trap Team's
// ten others finds no device offset that moved (the displacements that differ are global addresses) [V].
#define GAME_HOOK_D3DDevice_NextRingSegment sub_82876E38
#define GAME_HOOK_D3DDevice_KickOff sub_82877C90
#define GAME_HOOK_D3DDevice_BlockOnFence sub_82877D90
#define GAME_HOOK_D3DDevice_InsertCallback sub_82877E88
#define GAME_HOOK_D3DDevice_DrawVertices sub_828840D0
#define GAME_HOOK_D3DDevice_DrawIndexedVertices sub_828844E8
#define GAME_HOOK_D3DDevice_Resolve sub_828829C0
#define GAME_HOOK_D3DDevice_ClearF_Worker sub_82881BF8
#define GAME_HOOK_D3DDevice_Swap sub_8287B638
#define GAME_HOOK_D3DVertexShader_Init sub_828804A8
#define GAME_HOOK_D3DPixelShader_Init sub_828802B0

// XMA (runtime/kernel/xma.cpp): the same two engines. Xma1_Init, Xma1_VoiceKick, Xma2_VoiceLock, Xma2_VoiceKick and
// Xma1_LockAll are strict matches of SuperChargers', Trap Team's and Swap Force's; Xma2_Init, Xma1_VoiceClear and
// Xma2_VoiceClear are loose (0.9), the same candidate from each inventory [?].
#define GAME_HOOK_Xma1_Init sub_8366CCD8
#define GAME_HOOK_Xma2_Init sub_827F64A0
#define GAME_HOOK_Xma1_VoiceClear sub_8366CD38
#define GAME_HOOK_Xma1_VoiceKick sub_8366D6D0
#define GAME_HOOK_Xma2_VoiceClear sub_82870E10
#define GAME_HOOK_Xma2_VoiceLock sub_82870FB8
#define GAME_HOOK_Xma2_VoiceKick sub_82871268
#define GAME_HOOK_Xma1_LockAll sub_8366D560

// LZMA (engines/alchemy/lzma.cpp): the LZMA SDK's LzmaDec_DecodeReal, strict against all three inventories.
#define GAME_HOOK_LzmaDec_DecodeReal sub_8253F2C0

// Bink 2 (runtime/d3d/bink_display.cpp): BinkOpen and BinkClose loose (0.9) against SuperChargers' (Trap Team's: 0.58 and
// 0.74, the same candidates) [?].
#define GAME_HOOK_BinkOpen sub_8329F798
#define GAME_HOOK_BinkClose sub_832A04B8

// SKY_LEVEL (engines/alchemy/zone_request.cpp): the zone list's lookup by name, (list, const char* name) -> the zone or 0, a
// strict shape match (1.00, 70 instructions) of SuperChargers' sub_82DF1C58 (tools/xmatch.py shape). Entering the zone the game
// asked for next: SuperChargers' sub_82DF9528 matches sub_82D82B50 (0.66), which reads the request global +44 and calls the
// lookup above (the call at 0x82D82C1C), as SuperChargers' does [V].
#define GAME_HOOK_Zone_Find sub_82D7B450
#define GAME_HOOK_Zone_Enter sub_82D82B50

#include <cstdint>
#include <string_view>

namespace game
{
    // D3D: the offsets the runtime reads, Trap Team's (Giants'), carried by the strict matches above [?].
    constexpr uint32_t DeviceVertexDeclaration = 0x2FD0;
    constexpr bool DrawIndexedBaseVertex = false; // DrawIndexedVertices: (device, primitive, start, count)
    constexpr bool ExpandTiledTargets = true;
    constexpr bool ResolveHasLevel = false; // Resolve: slice r8, color r9
    constexpr uint32_t DeviceStateShift = 0x80;
    constexpr uint32_t LanguageIndex = 0;
    constexpr uint32_t LanguageCodes = 0;
    constexpr uint32_t NglCurrentScene = 0;
    constexpr uint32_t Engine1CriticalSection =
        0x837AA970; // sigmatch 1.0 (Trap Team's and Swap Force's), via Xma1_LockAll
    constexpr uint32_t DeviceGlobal = 0;
    constexpr uint32_t UltrawideDisplayAspect = 0;
    constexpr uint32_t UltrawideSceneWidth = 0, UltrawideSceneHeight = 0;
    constexpr bool UltrawideSceneKeepsArea = false;
    constexpr uint32_t UltrawideCompositeVertices = 0;
    constexpr int UltrawideCompositeSlot = 0;
    constexpr bool UltrawideCompositeVpos = false;
    constexpr uint64_t HostKernelPixelShader = 0;
    constexpr uint32_t HostKernelThreshold = 0;
    // SKY_LEVEL: the return address of the zone lookup that enters a zone; the request global (its object holds the next
    // zone's name at +44, a string object, as SuperChargers'); the first zone a new game enters after the menus.
    constexpr uint32_t ZoneEnterReturn = 0x82D82C20;
    constexpr uint32_t ZoneRequest = 0x837E7A64, ZoneRequestName = 44;
    constexpr std::string_view ZoneAfterIntro = "2016/level_508/level_508"; // the first level, its opening inside
    constexpr std::string_view ZonePrefix = "2016/"; // zones are 2016/<map>/<map>: 2016/hub_2016/hub_2016, 2016/level_508/level_508
}

// The portal library's signature check (games/imaginators/docs/toybox.md, "Signature"): sub_831FD948(work, data, 96, key)
// verifies a 2016 toy's factory signature; `data` is blocks 2, 4, 34 and 62 (the signature) then blocks 0 and 1, and 0 means
// verified. Two callers: the tag check when the toy arrives (sub_831F27C0: result+8 bit 0x80000000) and the check before
// a write (sub_831F4238); without it the toy is "maybe corrupted, repair it". Found by the signature's words read in a run
// (a load watch: sub_831FC850, the hash under it), then up the calls [V].
#define GAME_HOOK_Portal_TagSignatureVerify sub_831FD948
