/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef Opponent_H
#define Opponent_H
#include "character.h"
#include <iostream>
using namespace std;

class Opponent : public Character
{
public:
    Opponent()=delete;
    Opponent(int _damage, int _agility, int _defense, double _health);
    ~Opponent();

    //QGridLayout virtual *show() const override;
    void virtual attack1(Character*) override = 0;
    void virtual attack2(Character*) override = 0;
};

#endif // Opponent_H
