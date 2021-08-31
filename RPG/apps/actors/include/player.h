/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"

#include "..\..\stuff\include\iobject.h"
#include "..\..\stuff\include\backpack.h"
#include <QtWidgets/QGridLayout>
#include <iostream>
#include <QtWidgets/QGraphicsScene>
using namespace std;
class Player : public Character{

public:
Backpack playerBackpack;
Player()= delete;
Player(int _damage, int _agility, int _defense, double _health);
~Player();
//void virtual show() const override;
QGridLayout virtual *showStat() const = 0 ;
void backpack();
void flee();
void virtual attack1(Character*) override = 0;
void virtual attack2(Character*) override = 0;

};
#endif
