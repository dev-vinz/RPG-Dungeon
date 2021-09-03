/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

#include <QtWidgets/QGridLayout>
#include <QLabel>
#include <QtWidgets/QGraphicsScene>

class Player : public Character
{
protected:
    QString virtual attack1(Character *) override = 0;
    QString virtual attack2(Character *) override = 0;
public:
    Player() = delete;
    Player(int _damage, int _agility, int _defense, double _health);

    void flee();
    QString virtual showStat() const = 0;

    QString virtual getAttackOneName() const override = 0;
    QString virtual getAttackTwoName() const override = 0;
};

#endif
