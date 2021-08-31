/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef OPONNENT_H
#define OPONNENT_H
#include "character.h"
#include <iostream>
using namespace std;

class Oponnent : public Character
{
public:
    Oponnent()=delete;
    Oponnent(int _damage, int _agility, int _defense, double _health);
    ~Oponnent();

    //QGridLayout virtual *show() const override;
    void virtual attack1(Character*) override = 0;
    void virtual attack2(Character*) override = 0;
};

#endif // OPONNENT_H
