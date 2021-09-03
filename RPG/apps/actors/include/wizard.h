/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef WIZARD_H
#define WIZARD_H

#include "player.h"

class Wizard : public Player
{
protected:
    double mana;
    QString virtual attack1(Character *) override;
    QString virtual attack2(Character *) override;

public:
    Wizard() = delete;
    Wizard(int _damage, int _agility, int _defense, double _health, double _mana);

    QGridLayout virtual *show() const override;
    QString virtual showStat() const override;
    void updateMana(double);

    QString virtual getAttackOneName() const override { return "Coup de bâton"; }
    QString virtual getAttackTwoName() const override { return "Boule de feu (8)"; }
    QString getName() const override { return QString("Sorcier"); };
    double getMana() const { return this->mana; };
};

#endif
