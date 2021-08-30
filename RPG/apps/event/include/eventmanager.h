/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "battle.h"
#include "loot.h"
#include "riddle.h"

class EventManager
{
public:
    EventManager() = default;

    Battle createBattle() const;
    Loot createLoot() const;
    Riddle createRiddle() const;
};

#endif // EVENTMANAGER_H
