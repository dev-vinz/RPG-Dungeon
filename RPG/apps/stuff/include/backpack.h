/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
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
    std::vector<IObject *> myBackpack;
public:
    Backpack();
    ~Backpack();

    void addItem(IObject* _pObject);
    void useItem(int _indice, Character *_character);
    void show();
};

#endif // BACKPACK_H
