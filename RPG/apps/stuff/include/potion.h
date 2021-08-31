#ifndef POTION_H
#define POTION_H

#include <iostream>
#include "iobject.h"
using namespace std;

class Potion : public IObject
{
public:
    Potion()=delete;

    Potion(int _power);

    ~Potion();

    void virtual use(Character* _character)override;

    int getFeature() override{return this->power;};
    string getName() override{return "Potion";};

};

#endif // POTION_H
