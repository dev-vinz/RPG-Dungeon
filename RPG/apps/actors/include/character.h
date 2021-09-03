/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include <QLabel>
#include <QRandomGenerator>
#include <QString>
#include <QGridLayout>

#include "..\..\..\settings\settings.h"

class Character
{
protected:
    int damage;
    int agility;
    int defense;
    double health;

    QString virtual attack1(Character*) = 0;
    QString virtual attack2(Character*) = 0;

    bool dodge();
    int totalDamage(Character* _character);

public:
    Character()=delete;
    Character(int _damage, int _agility, int _defense, double _health);

    bool isAlive();

    QString interaction(Character* _character, Action _action);
    QGridLayout virtual *show() const = 0;

    void updateDefense(double _defense);
    bool updateHealth(double _health);



    QString virtual getAttackOneName() const = 0;
    QString virtual getAttackTwoName() const = 0;
    QString virtual getName() const = 0;
    int getDamage()const{return this->damage;};
    int getAgility()const{return this->agility;};
    int getDefense()const{return this->defense;};
    double getHealth()const{return this->health;};

};

#endif
