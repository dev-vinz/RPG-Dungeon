#ifndef SKELETON_H
#define SKELETON_H

#include "oponnent.h"
#include <iostream>

using namespace std;

class Skeleton : public Oponnent
{
protected:
    void virtual attack1(Character*) override;
    void virtual attack2(Character*) override;
public:
    Skeleton()=delete;
    Skeleton(int,int, int, double);
    ~Skeleton();
    QString getName() const override {return QString("Skeleton");};
};

#endif // SKELETON_H
