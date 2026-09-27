/*
 * This file is part of the mod-playerbots module for AzerothCore. See AUTHORS file for Copyright
 * information; released under GNU GPL v2 license, redistribute/modify under version 2 of the License,
 * or (at your option) any later version.
 */

#ifndef PLAYERBOTS_MTACTIONS_H
#define PLAYERBOTS_MTACTIONS_H

#include "Action.h"
#include "MovementActions.h"

// Nexus-Prince Shaffar

class ShaffarMarkEtherealBeaconWithSkullAction : public Action
{
public:
    ShaffarMarkEtherealBeaconWithSkullAction(PlayerbotAI* botAI)
        : Action(botAI, "shaffar mark ethereal beacon with skull") {}
    bool Execute(Event event) override;
};

// Mana Leech (trash)

class MoveAwayFromManaLeechAction : public MovementAction
{
public:
    MoveAwayFromManaLeechAction(PlayerbotAI* botAI)
        : MovementAction(botAI, "move away from mana leech") {}
    bool Execute(Event event) override;
};

#endif
