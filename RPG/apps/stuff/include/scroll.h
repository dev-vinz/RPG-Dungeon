#ifndef SCROLL_H
#define SCROLL_H

#include "iobject.h"
#include <iostream>
class Scroll : public IObject
{
public:
    Scroll()=delete;

    Scroll(int _power);

    ~Scroll();

    void virtual use(Character* _character) override;
    int getFeature() override{return this->power;};
    string getName() override{return "Scroll";};

};

#endif // SCROLL_H
