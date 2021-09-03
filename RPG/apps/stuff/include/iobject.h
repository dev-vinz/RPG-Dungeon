/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef IOBJECT_H
#define IOBJECT_H

#include <QString>

#include "..\..\actors\include\character.h"


class IObject
{
protected:
    int power;
public:
    IObject(int _power = 0);
    ~IObject();

    QString virtual getName() = 0;
    int virtual getFeature() = 0;
    QString virtual show();
    void virtual use(Character* _character) = 0;

    QString virtual getAction() const = 0;
    QString virtual getDescription() const = 0;
};

#endif // IOBJECT_H
