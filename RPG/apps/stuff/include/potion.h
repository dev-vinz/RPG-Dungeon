/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef POTION_H
#define POTION_H


#include "iobject.h"


class Potion : public IObject
{
public:
    Potion()=delete;

    Potion(int _power);

    ~Potion();

    void virtual use(Character* _character)override;

    int getFeature() override{return this->power;};
    QString getName() override{return QString("Potion");};

};

#endif // POTION_H
