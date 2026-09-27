/*
 * This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
 * information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
 * or (at your option) any later version.
 */

#ifndef PLAYERBOTS_MTTRIGGERCONTEXT_H
#define PLAYERBOTS_MTTRIGGERCONTEXT_H

#include "MTTriggers.h"
#include "NamedObjectContext.h"

class TbcDungeonManaTombsTriggerContext : public NamedObjectContext<Trigger>
{
public:
    TbcDungeonManaTombsTriggerContext()
    {
        creators["shaffar ethereal beacon summoned"] =
            &TbcDungeonManaTombsTriggerContext::shaffar_ethereal_beacon_summoned;

        creators["non-tank too close to mana leech"] =
            &TbcDungeonManaTombsTriggerContext::non_tank_too_close_to_mana_leech;
    }
private:
    static Trigger* shaffar_ethereal_beacon_summoned(PlayerbotAI* botAI) {
        return new ShaffarEtherealBeaconSummonedTrigger(botAI);
    }
    static Trigger* non_tank_too_close_to_mana_leech(PlayerbotAI* botAI) {
        return new NonTankTooCloseToManaLeechTrigger(botAI);
    }
};

#endif
