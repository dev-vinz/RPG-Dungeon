/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"

#include <QtWidgets/QGridLayout>
#include <QLabel>
#include <QtWidgets/QGraphicsScene>

class Player : public Character{

public:
    Player()= delete;
    Player(int _damage, int _agility, int _defense, double _health);
    ~Player();
    //void virtual show() const override;
    QString virtual showStat() const = 0 ;
    void flee();
    void virtual attack1(Character*) override = 0;
    void virtual attack2(Character*) override = 0;

};
#endif
