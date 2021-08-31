/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef TORCH_H
#define TORCH_H

#include <iostream>

#include "iobject.h"
using namespace std;

class Torch : public IObject
{
public:
    Torch()= delete;
    Torch(int  _power);
    ~Torch();
    void virtual use(Character* _character) override;
    int getFeature() override{return this->power;};
    string getName() override{return "Torch";};

};

#endif // TORCH_H