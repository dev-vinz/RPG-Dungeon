/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
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
        RiddleEvent,
        ExitRoom
    };

    EventManager(std::map<Player *, QLabel *> *_statsLabels, QLabel *_gameLabel);

    bool battleEvent(std::deque<Player *> *_player, Opponent *_opponent, QPushButton *_btnAOne, QPushButton *_btnATwo, QPushButton *_btnBackpack, QPushButton *_btnFlee) const;
    IObject *lootEvent() const;
    void riddleEvent(std::deque<Player *> *_player) const;
};

#endif // EVENTMANAGER_H
