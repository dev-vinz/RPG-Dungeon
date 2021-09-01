/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef WARRIOR_H
#define WARRIOR_H
#include "player.h"



class Warrior : public Player
{
protected:
void virtual attack1(Character*) override;
void virtual attack2(Character*) override;
public:
Warrior()=delete;
Warrior(int _damage, int _agility, int _defense, double _health);
~Warrior();
QString getName() const override {return QString("Warrior");};
QString virtual showStat() const override;
QGridLayout virtual *show() const override;

};
#endif
