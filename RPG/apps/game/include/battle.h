#ifndef BATTLE_H
#define BATTLE_H

#include "..\..\actors\include\character.h"
#include "..\..\actors\include\player.h"
#include <algorithm>
#include <list>
class Battle
{
    list<Character*> myParty;
    Character* enemy;
public:
    Battle(list<Character*> myParty, Character* enemy);



    void startBattle(list<Character*> myParty, Character* enemy);

};

#endif // BATTLE_H
