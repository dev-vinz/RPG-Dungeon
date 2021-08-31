/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef IOBJECT_H
#define IOBJECT_H

#include <iostream>
#include "..\..\actors\include\character.h"
using namespace std;

class IObject
{
protected:
    int power;
public:
    IObject()=delete;
    IObject(int _power);
    ~IObject();

    string virtual getName() = 0;
    int virtual getFeature() = 0;
    void show();
    void virtual use(Character* _character) = 0;

};

#endif // IOBJECT_H
