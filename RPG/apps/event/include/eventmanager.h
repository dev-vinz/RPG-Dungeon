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
    QLabel *gameLabel;

public:
    enum Event
    {
        NothingEvent,
        LootEvent,
        RiddleEvent
    };

    EventManager(std::map<Player *, QLabel *> *_statsLabels, QLabel *_gameLabel);

    bool battleEvent(std::deque<Player *> *_player, Opponent *_opponent, QPushButton *_btnAOne, QPushButton *_btnATwo) const;
    IObject *lootEvent() const;
    void riddleEvent(std::deque<Player *> *_player) const;
};

#endif // EVENTMANAGER_H
