/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef SKELETON_H
#define SKELETON_H

#include "opponent.h"

class Skeleton : public Opponent
{
protected:
    QString virtual attack1(Character *) override;
    QString virtual attack2(Character *) override;

public:
    Skeleton() = delete;
    Skeleton(int, int, int, double);

    QGridLayout virtual *show() const override;

    QString virtual getAttackOneName() const override { return "Lancement d'os"; }
    QString virtual getAttackTwoName() const override { return "Coup de poignard"; }
    QString getName() const override { return QString("Squelette"); };
};

#endif // SKELETON_H
