#ifndef WIZARD_H
#define WIZARD_H
#include "player.h"
#include <iostream>

using namespace std;
class Wizard : public Player
{
protected:
double mana;
void virtual attack1(Character*) override;
void virtual attack2(Character*) override;

public:
Wizard()=delete;
Wizard(int _damage, int _agility, int _defense, double _health, double _mana);
~Wizard();

void virtual show() override;
double getMana()const{return this->mana;};
void updateMana(double);
QString getName() const override{return QString("Wizard");};
QGridLayout virtual *showStat() const override;
};
#endif
