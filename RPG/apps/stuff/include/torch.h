/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef TORCH_H
#define TORCH_H

#include "iobject.h"

class Torch : public IObject
{
public:
    Torch(int _power = 0);
    ~Torch();
    void virtual use(Character *) override;
    int getFeature() override { return this->power; };
    QString getName() override { return QString("Torche"); };
    QString show() override;

    QString virtual getAction() const override { return "Vous révèlez l'entièreté de la map."; }
    QString virtual getDescription() const override { return "Révèle l'entièreté de la map"; }
};

#endif // TORCH_H
