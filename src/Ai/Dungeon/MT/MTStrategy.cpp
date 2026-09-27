/*
 * This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
 * information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
 * or (at your option) any later version.
 */

#include "MTStrategy.h"
#include "MTMultipliers.h"
#include "MTTriggers.h"

void TbcDungeonManaTombsStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    // Nexus-Prince Shaffar
    triggers.push_back(new TriggerNode("shaffar ethereal beacon summoned", {
        NextAction("shaffar mark ethereal beacon with skull", ACTION_RAID) }));

    // Mana Leech (trash)
    triggers.push_back(new TriggerNode("non-tank too close to mana leech", {
        NextAction("move away from mana leech", ACTION_EMERGENCY + 10) }));
}

void TbcDungeonManaTombsStrategy::InitMultipliers(std::vector<Multiplier*>& multipliers)
{
    // Pandemonius
    multipliers.push_back(new PandemoniusDarkShellMultiplier(botAI));

    // Mana Leech (trash)
    multipliers.push_back(new ManaLeechMultiplier(botAI));
}
