/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef TORCH_H
#define TORCH_H



#include "iobject.h"


class Torch : public IObject
{
public:
    Torch()= delete;
    Torch(int  _power);
    ~Torch();
    void virtual use(Character* _character) override;
    int getFeature() override{return this->power;};
    QString getName() override{return QString("Torch");};
    QString show() override;
};

#endif // TORCH_H
