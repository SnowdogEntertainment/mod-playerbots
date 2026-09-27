/*
 * This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
 * information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
 * or (at your option) any later version.
 */

#ifndef PLAYERBOTS_MTACTIONCONTEXT_H
#define PLAYERBOTS_MTACTIONCONTEXT_H

#include "MTActions.h"
#include "NamedObjectContext.h"

class TbcDungeonManaTombsActionContext : public NamedObjectContext<Action>
{
public:
    TbcDungeonManaTombsActionContext()
    {
        creators["shaffar mark ethereal beacon with skull"] =
            &TbcDungeonManaTombsActionContext::shaffar_mark_ethereal_beacon_with_skull;
    }
private:
    static Action* shaffar_mark_ethereal_beacon_with_skull(PlayerbotAI* botAI) {
        return new ShaffarMarkEtherealBeaconWithSkullAction(botAI);
    }
};

#endif
