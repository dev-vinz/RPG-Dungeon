/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef SCROLL_H
#define SCROLL_H

#include "iobject.h"

class Scroll : public IObject
{
public:
    Scroll()=delete;

    Scroll(int _power);

    ~Scroll();

    void virtual use(Character* _character) override;
    int getFeature() override{return this->power;};
    QString getName() override{return QString("Parchemin");};

};

#endif // SCROLL_H
