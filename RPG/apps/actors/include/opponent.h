/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef OPPONENT_H
#define OPPONENT_H

#include "character.h"

class Opponent : public Character
{
protected:
    QString virtual attack1(Character *) override = 0;
    QString virtual attack2(Character *) override = 0;
public:
    Opponent() = delete;
    Opponent(int _damage, int _agility, int _defense, double _health);

    QString virtual getAttackOneName() const override = 0;
    QString virtual getAttackTwoName() const override = 0;
};

#endif // OPPONENT_H
