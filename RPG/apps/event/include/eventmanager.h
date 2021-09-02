/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <map>

#include "battle.h"
#include "loot.h"
#include "riddle.h"

#include "../../../settings/ExtensionMethod.h"

class EventManager
{
private:
    std::map<Player *, QLabel *> *statsLabels;

public:
    EventManager(std::map<Player *, QLabel *> *_statsLabels);

    bool battleEvent(std::deque<Player *> *_player, QPushButton *_btnAOne, QPushButton *_btnATwo) const;
    IObject *lootEvent() const;
    void riddleEvent(std::deque<Player *> *_player) const;
};

#endif // EVENTMANAGER_H
