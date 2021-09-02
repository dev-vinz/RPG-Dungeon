/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef OPPONENT_H
#define OPPONENT_H
#include "character.h"

class Opponent : public Character
{
public:
    Opponent()=delete;
    Opponent(int _damage, int _agility, int _defense, double _health);
    //QGridLayout virtual *show() const override;
    void virtual attack1(Character*) override = 0;
    void virtual attack2(Character*) override = 0;
};

#endif // OPPONENT_H
