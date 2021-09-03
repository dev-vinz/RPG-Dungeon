/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef SCROLL_H
#define SCROLL_H

#include "iobject.h"

class Scroll : public IObject
{
public:
    Scroll(int _power = 0);
    ~Scroll();

    void virtual use(Character *_character) override;

    QString virtual getAction() const override { return QString("Vous infligez %1 dégâts").arg(QString::number(this->power)); }
    QString virtual getDescription() const override { return "Inflige des dégâts à l'ennemi"; }
    int virtual getFeature() const override { return this->power; };
    QString virtual getName() const override { return QString("Parchemin"); };
};

#endif // SCROLL_H
