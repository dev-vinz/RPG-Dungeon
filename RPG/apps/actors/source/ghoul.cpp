#include "..\include\ghoul.h"

Ghoul::Ghoul(int _damage ,int _agility ,int _defense ,double _health/*, *pObject*/) : Opponent(_damage, _agility, _defense, _health)
{

}

void Ghoul::attack1(Character* _character)
{
    //Watch to target a Player and not an oponnent
    int heal = 20;
    _character->updateHealth(heal);
}

void Ghoul::attack2(Character* _character)
{
    int damage = this->totalDamage(_character);
    _character->updateHealth(-damage);
}
