/*
 * This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
 * information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
 * or (at your option) any later version.
 */

#ifndef PLAYERBOTS_MTMULTIPLIERS_H
#define PLAYERBOTS_MTMULTIPLIERS_H

#include "Multiplier.h"

inline constexpr uint32 SPELL_DARK_SHELL = 32358;

// Pandemonius

class PandemoniusDarkShellMultiplier : public Multiplier
{
public:
    PandemoniusDarkShellMultiplier(PlayerbotAI* ai) : Multiplier(ai, "pandemonius dark shell") {}

    float GetValue(Action* action) override;
};

// Mana Leech (trash)

class ManaLeechMultiplier : public Multiplier
{
public:
    ManaLeechMultiplier(PlayerbotAI* ai) : Multiplier(ai, "mana leech") {}

    float GetValue(Action* action) override;
};

#endif
