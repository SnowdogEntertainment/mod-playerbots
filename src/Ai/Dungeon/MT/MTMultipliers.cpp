/*
 * This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
 * information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
 * or (at your option) any later version.
 */

#include "MTMultipliers.h"
#include "GenericSpellActions.h"
#include "Playerbots.h"

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
