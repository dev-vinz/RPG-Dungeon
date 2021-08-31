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
    string getName() override {return "Ghoul";};
};

#endif // GHOUL_H
