#include "..\include\oponnent.h"

Oponnent::Oponnent(int _damage, int _agility, int _defense, double _health/*,*_pObject*/) : Character(_damage, _agility, _defense, _health)
{

}

void Oponnent::show()
{
    cout << endl
         << "=========================" << endl
         //<< "Name : " << this->getName() << endl
         << "=========================" << endl
         << "Damage : " << this->getDamage() << endl
         << "Health : " << this->getHealth() << endl
         << "Agility : " << this->getAgility() << endl
         << "Defense : " << this->getDefense() << endl
         << "=========================" << endl
         << endl;
}
