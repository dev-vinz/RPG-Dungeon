#include "..\include\potion.h"

Potion::Potion(int _power) : IObject(_power)
{

}

void Potion::use(Character* _character)
{
    _character->updateHealth(this->getFeature());
}
