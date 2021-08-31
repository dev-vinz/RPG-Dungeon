
/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef HEALER_H
#define HEALER_H
#include "player.h"


class Healer : public Player
{
protected:
void virtual attack1(Character*) override;
void virtual attack2(Character*) override;
public:
Healer()=delete;
Healer(int _damage, int _agility, int _defense, double _health);
~Healer();
QString getName() const override{return QString("Healer");};
QGridLayout virtual *show() const override;
QGridLayout virtual *showStat() const override;

};
#endif
