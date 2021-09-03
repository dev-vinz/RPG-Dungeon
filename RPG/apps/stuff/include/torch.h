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

    QString show() const override;
    void virtual use(Character *) override;

    QString virtual getAction() const override { return "Vous révèlez l'entièreté de la map."; }
    QString virtual getDescription() const override { return "Révèle l'entièreté de la map"; }
    int virtual getFeature() const override { return this->power; };
    QString virtual getName() const override { return QString("Torche"); };
};

#endif // TORCH_H
