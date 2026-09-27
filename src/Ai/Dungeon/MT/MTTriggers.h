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

#endif
