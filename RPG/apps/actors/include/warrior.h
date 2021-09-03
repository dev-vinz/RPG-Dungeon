/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef WARRIOR_H
#define WARRIOR_H

#include "player.h"

class Warrior : public Player
{
protected:
    QString virtual attack1(Character *) override;
    QString virtual attack2(Character *) override;

public:
    Warrior() = delete;
    Warrior(int _damage, int _agility, int _defense, double _health);
    QString getName() const override { return QString("Guerrier"); };
    QString virtual showStat() const override;
    QGridLayout virtual *show() const override;

    QString virtual getAttackOneName() const override { return "Protection"; }
    QString virtual getAttackTwoName() const override { return "Coup d'estoc"; }
};

#endif
