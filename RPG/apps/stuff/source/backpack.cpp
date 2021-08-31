#include "..\include\backpack.h"

Backpack::Backpack()
{
    Potion *potion1 = new Potion(5);
    Torch *torch = new Torch(5);
    Scroll *scroll = new Scroll(5);
    myBackpack.push_back(potion1);
    myBackpack.push_back(torch);
    myBackpack.push_back(scroll);
}

void Backpack::addItem(IObject* _pObject)
{
    myBackpack.push_back(_pObject);
}

void Backpack::useItem(int _indice, Character *_character)
{
    //il faut trouver l'item quon veut utiliser puis il faut l'enlever du sac

    myBackpack[_indice]->use(_character);

    myBackpack.erase(myBackpack.begin()+_indice);

}

void Backpack::show()
{
    for_each(myBackpack.begin(), myBackpack.end(), [](IObject *_object)
    {
        _object->show();
    });
}
