#ifndef BACKPACK_H
#define BACKPACK_H

#include <vector>

#include "iobject.h"
#include "..\..\actors\include\character.h"
#include "..\include\torch.h"
#include "..\include\potion.h"
#include "..\include\scroll.h"

class Backpack
{

private:
    vector<IObject *> myBackpack;
public:
    Backpack();
    ~Backpack();

    void addItem(IObject* _pObject);
    void useItem(int _indice, Character *_character);
    void show();
};

#endif // BACKPACK_H
