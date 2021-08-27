#include "..\include\healer.h"


void Healer::attack1(Character* _character)
{
    //Watch to target a Player and not an oponnent

    int heal = 20;
    cout << "Vous soignez un allié" << endl;
    _character->updateHealth(heal);
}

void Healer::attack2(Character* _character)
{
    int damage = this->totalDamage(_character);
    cout << "Vous infligez des dégats." << endl;
    _character->updateHealth(-damage);
}

Healer::Healer(int _damage ,int _agility ,int _defense ,double _health) : Player(_damage, _agility, _defense, _health)
{

}
