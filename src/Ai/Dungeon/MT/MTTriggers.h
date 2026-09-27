/*
 * This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
 * information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
 * or (at your option) any later version.
 */

#ifndef PLAYERBOTS_MTTRIGGERS_H
#define PLAYERBOTS_MTTRIGGERS_H

#include "Trigger.h"

inline constexpr uint32 MANA_TOMBS_MAP_ID = 557;

// Nexus-Prince Shaffar

class ShaffarEtherealBeaconSummonedTrigger : public Trigger
{
public:
    ShaffarEtherealBeaconSummonedTrigger(PlayerbotAI* botAI)
        : Trigger(botAI, "shaffar ethereal beacon summoned") {}
    bool IsActive() override;
};

// Mana Leech (trash)

inline constexpr uint32 NPC_MANA_LEECH = 19306;
inline constexpr uint32 NPC_MANA_LEECH_HEROIC = 20263;
inline constexpr float MANA_LEECH_EXPLOSION_RADIUS = 10.0f;
inline constexpr float MANA_LEECH_SAFE_DISTANCE = MANA_LEECH_EXPLOSION_RADIUS + 2.0f;

class NonTankTooCloseToManaLeechTrigger : public Trigger
{
public:
    NonTankTooCloseToManaLeechTrigger(PlayerbotAI* botAI)
        : Trigger(botAI, "non-tank too close to mana leech") {}
    bool IsActive() override;
};

#endif
