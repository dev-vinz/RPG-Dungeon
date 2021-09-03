/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef GHOUL_H
#define GHOUL_H

#include "opponent.h"

class Ghoul : public Opponent
{
protected:
    QString virtual attack1(Character *) override;
    QString virtual attack2(Character *) override;

public:
    Ghoul() = delete;
    Ghoul(int, int, int, double);
    QString getName() const override { return QString("Goule"); };
    QGridLayout virtual *show() const override;

    QString virtual getAttackOneName() const override { return "Griffe"; }
    QString virtual getAttackTwoName() const override { return "Tranche"; }
};

#endif // GHOUL_H
