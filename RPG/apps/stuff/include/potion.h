/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef POTION_H
#define POTION_H

#include "iobject.h"

class Potion : public IObject
{
public:
    Potion(int _power = 0);

    ~Potion();

    void virtual use(Character *_character) override;

    QString virtual getAction() const override { return QString("Vous soignez votre personnage le plus faible de %1 HP").arg(QString::number(this->power)); }
    QString virtual getDescription() const override { return "Permet de soigner votre personnage le plus faible"; }
    int virtual getFeature() const override { return this->power; };
    QString virtual getName() const override { return QString("Potion"); };
};

#endif // POTION_H
