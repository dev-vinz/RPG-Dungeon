/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef BATTLE_H
#define BATTLE_H

#include "..\..\actors\include\character.h"
#include "..\..\actors\include\player.h"
#include <algorithm>
#include <list>
class Battle
{

public:
    Battle();
    void startBattle(list<Character*> myParty, Character* enemy);

};

#endif // BATTLE_H
