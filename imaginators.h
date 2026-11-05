#pragma once

#include <string_view>

// Imaginators' own code, shared by the files of games/imaginators/.
namespace imaginators
{
    // The text and the voices in one of the disc's languages (language.cpp): "fr" or "nl"; false for any other.
    bool SetTextLanguage(std::string_view code);
    bool SetVoiceLanguage(std::string_view code);
}
