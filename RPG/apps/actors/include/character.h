#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <QRandomGenerator>
#include <QString>

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

    int getDamage()const{return this->damage;};
    int getDefense()const{return this->defense;};
    int getAgility()const{return this->agility;};
    double getHealth()const{return this->health;};

    QString virtual getName() const = 0;
    void virtual attack1(Character*) = 0;
    void virtual attack2(Character*) = 0;

};
#endif
