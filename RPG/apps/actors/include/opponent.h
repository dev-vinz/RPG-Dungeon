#ifndef OPPONENT_H
#define OPPONENT_H

#include "character.h"

//#include <iostream>
//using namespace std;

class Opponent : public Character
{
public:
    Opponent()=delete;
    Opponent(int _damage, int _agility, int _defense, double _health);
    ~Opponent();

    void virtual show() override;
    void virtual attack1(Character*) override = 0;
    void virtual attack2(Character*) override = 0;
};

#endif // OPPONENT_H
