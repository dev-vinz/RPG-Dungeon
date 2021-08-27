#include "..\include\warrior.h"

void Warrior::attack1(Character* _character)
{
    int damage = this->totalDamage(_character);
    cout << "Vous infligez des dégats" << endl;
    _character->updateHealth(-damage);
}

void Warrior::attack2(Character* _character)
{
    cout << "Vous protegez un allié" << endl;
    _character->show();
}

Warrior::Warrior(int _damage ,int _agility ,int _defense ,double _health) :Player (_damage, _agility, _defense, _health)
{

}

