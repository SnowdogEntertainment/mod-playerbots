/*
 * This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
 * information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
 * or (at your option) any later version.
 */

#include "MTActions.h"
#include "EncounterHelpers.h"
#include "MTTriggers.h"
#include "Playerbots.h"

using namespace EncounterHelpers;

// Nexus-Prince Shaffar

bool ShaffarMarkEtherealBeaconWithSkullAction::Execute(Event /*event*/)
{
    Unit* beacon = AI_VALUE2(Unit*, "find target", "ethereal beacon");
    if (!beacon)
        return false;

    return MarkTargetWithSkull(bot, beacon);
}

// Mana Leech (trash)

bool MoveAwayFromManaLeechAction::Execute(Event /*event*/)
{
    Unit* target = AI_VALUE(Unit*, "current target");
    if (!target)
        return false;

    float currentDistance = bot->GetExactDist2d(target);
    if (currentDistance >= MANA_LEECH_SAFE_DISTANCE)
        return false;

    bot->CastStop();
    return MoveAway(target, MANA_LEECH_SAFE_DISTANCE - currentDistance);
}
