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

public:
    Character() = delete;
    Character(int _damage, int _agility, int _defense, double _health);

    QGridLayout virtual *show() const = 0;

    bool isAlive();
    QString interaction(Character *_character, Action _action);
    bool dodge();
    int totalDamage(Character *_character);
    void updateDefense(double _defense);
    bool updateHealth(double _health);

    int getDamage() const { return this->damage; };
    int getDefense() const { return this->defense; };
    int getAgility() const { return this->agility; };
    double getHealth() const { return this->health; };

    QString virtual getName() const = 0;
    QString virtual attack1(Character *) = 0;
    QString virtual attack2(Character *) = 0;

    QString virtual getAttackOneName() const = 0;
    QString virtual getAttackTwoName() const = 0;
};

#endif
