#ifndef HEALER_H
#define HEALER_H
#include "player.h"
#include <iostream>
using namespace std;
class Healer : public Player
{
protected:
void virtual attack1(Character*) override;
void virtual attack2(Character*) override;
public:
Healer()=delete;
Healer(int _damage, int _agility, int _defense, double _health);
~Healer();
string getName() override{return "Healer";};

};
#endif
