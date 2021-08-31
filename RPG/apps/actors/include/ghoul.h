/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef GHOUL_H
#define GHOUL_H
#include "opponent.h"
#include <iostream>

using namespace std;
class Ghoul : public Opponent
{
protected:
    void virtual attack1(Character*) override;
    void virtual attack2(Character*) override;
public:
    Ghoul()=delete;
    Ghoul(int,int,int,double);
    ~Ghoul();
    QString getName() const override {return QString("Ghoul");};
    QGridLayout virtual *show() const override;
};

#endif // GHOUL_H
