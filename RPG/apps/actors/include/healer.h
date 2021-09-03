/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef HEALER_H
#define HEALER_H

#include "player.h"

class Healer : public Player
{
protected:
    QString virtual attack1(Character *) override;
    QString virtual attack2(Character *) override;

public:
    Healer() = delete;
    Healer(int _damage, int _agility, int _defense, double _health);
    QString getName() const override { return QString("Soigneur"); };
    QGridLayout virtual *show() const override;
    QString virtual showStat() const override;

    QString virtual getAttackOneName() const override { return "Soin"; }
    QString virtual getAttackTwoName() const override { return "Coup de bâton"; }
};

#endif
