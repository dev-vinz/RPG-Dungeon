/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef SKELETON_H
#define SKELETON_H

#include "opponent.h"




class Skeleton : public Opponent
{
protected:
    void virtual attack1(Character*) override;
    void virtual attack2(Character*) override;
public:
    Skeleton()=delete;
    Skeleton(int,int, int, double);
    QString getName() const override {return QString("Squelette");};
    QGridLayout virtual *show() const override;
};

#endif // SKELETON_H
