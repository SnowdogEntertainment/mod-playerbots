/*
 * This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
 * information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
 * or (at your option) any later version.
 */

#include "MTTriggers.h"
#include "EncounterHelpers.h"
#include "Playerbots.h"

using namespace EncounterHelpers;

// Nexus-Prince Shaffar

// Shaffar summons a fresh Ethereal Beacon roughly every 10s and lets it loose on a random
// player; left alive, they stack up faster than the group can absorb the damage. Only one bot
// needs to keep the skull on the current beacon for the group's normal kill-priority targeting
// to pick it up.
bool ShaffarEtherealBeaconSummonedTrigger::IsActive()
{
    if (!IsMechanicTrackerBot(bot, MANA_TOMBS_MAP_ID))
        return false;

    return bool(AI_VALUE2(Unit*, "find target", "ethereal beacon"));
}
