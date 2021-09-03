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
    int getFeature() override { return this->power; };
    QString getName() override { return QString("Parchemin"); };

    QString virtual getAction() const override { return QString("Vous infligez %1 dégâts").arg(QString::number(this->power)); }
    QString virtual getDescription() const override { return "Inflige des dégâts à l'ennemi"; }
};

#endif // SCROLL_H
