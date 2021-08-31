#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <QRandomGenerator>

#include "..\..\..\settings\settings.h"
using namespace std;
class Character
{
protected:
    int damage;
    int agility;
    int defense;
    double health;

public:
    Character()=delete;
    Character(int _damage, int _agility, int _defense, double _health);
    ~Character();

    void virtual show();

    bool isAlive();
    void interaction(Character* _character, Action _action);
    bool dodge();
    int totalDamage(Character* _character);
    void updateHealth(double _health);

    int getDamage(){return this->damage;};
    int getDefense(){return this->defense;};
    int getAgility(){return this->agility;};
    double getHealth(){return this->health;};

    string virtual getName() = 0;
    void virtual attack1(Character*) = 0;
    void virtual attack2(Character*) = 0;

};
#endif
