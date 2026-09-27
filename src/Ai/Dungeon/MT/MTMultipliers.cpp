/*
 * This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
 * information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
 * or (at your option) any later version.
 */

#include "MTMultipliers.h"
#include "GenericSpellActions.h"
#include "MTTriggers.h"
#include "Playerbots.h"
#include "ReachTargetActions.h"

// Pandemonius

// Dark Shell reflects incoming spells back at the caster for 6s, recast roughly every 20s.
// Melee swings and ranged shots aren't spells and go untouched; only direct-damage spell casts
// aimed at the boss are held back so casters don't nuke themselves. Heals, cures, and buffs are
// never suppressed, whatever their current target.
float PandemoniusDarkShellMultiplier::GetValue(Action* action)
{
    if (!dynamic_cast<CastSpellAction*>(action) ||
        dynamic_cast<CastHealingSpellAction*>(action) ||
        dynamic_cast<CastBuffSpellAction*>(action) ||
        dynamic_cast<CastCureSpellAction*>(action) ||
        dynamic_cast<CastAuraSpellAction*>(action) ||
        dynamic_cast<CastShootAction*>(action))
    {
        return 1.0f;
    }

    Unit* boss = AI_VALUE2(Unit*, "find target", "pandemonius");
    if (!boss || !boss->HasAura(SPELL_DARK_SHELL))
        return 1.0f;

    Unit* target = AI_VALUE(Unit*, "current target");
    if (!target || target->GetGUID() != boss->GetGUID())
        return 1.0f;

    return 0.0f;
}

// Mana Leech (trash)

// Stops non-tanks from ever closing to melee range of a Mana Leech in the first place;
// NonTankTooCloseToManaLeechTrigger/MoveAwayFromManaLeechAction handle anyone already
// standing too close (e.g. approaching before target selection settled on it).
float ManaLeechMultiplier::GetValue(Action* action)
{
    if (PlayerbotAI::IsTank(bot))
        return 1.0f;

    if (!dynamic_cast<ReachMeleeAction*>(action))
        return 1.0f;

    Unit* target = AI_VALUE(Unit*, "current target");
    if (!target || (target->GetEntry() != NPC_MANA_LEECH && target->GetEntry() != NPC_MANA_LEECH_HEROIC))
        return 1.0f;

    return 0.0f;
}
