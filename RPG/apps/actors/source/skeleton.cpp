#include "..\include\skeleton.h"


void Skeleton::attack1(Character* _character)
{
    //Watch to target a Player and not an oponnent
    int heal = 20;
    _character->updateHealth(heal);
}

void Skeleton::attack2(Character* _character)
{
    int damage = this->totalDamage(_character);
    _character->updateHealth(-damage);
}
Skeleton::Skeleton(int _damage ,int _agility ,int _defense ,double _health) : Opponent(_damage, _agility, _defense, _health)
{

}
