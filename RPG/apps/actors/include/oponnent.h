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

    void virtual show() override;
    void virtual attack1(Character*) override = 0;
    void virtual attack2(Character*) override = 0;
};

#endif // OPONNENT_H
