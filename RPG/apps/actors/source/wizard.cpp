#include "..\include\wizard.h"



Wizard::Wizard(int _damage ,int _agility ,int _defense ,double _health, double _mana) :Player(_damage, _agility, _defense, _health)
{
    this->mana = _mana;
}
void Wizard::attack1(Character* _character)
{
    cout << "Vous faites une attaque simple" << endl;
    int damage = this->totalDamage(_character);
    _character->updateHealth(-damage);
}
 void Wizard::attack2(Character* _character)
{
    int manaCost = 8;
    if(manaCost>this->getMana())
    {
        //globalLabel->UpdateText("Vous n'avez pas assez de mana.");
        cout <<"Vous n'avez pas assez de mana." << endl;
        this->interaction(_character, Action::attack1);
    }else{
        this->updateMana(-manaCost);
        cout << "Vous faire une grosse attaque" << endl;
        int damage = this->totalDamage(_character) + 10;
        _character->updateHealth(-damage);
    }
}
void Wizard::show()
{
    cout << endl
         << "=========================" << endl
         << "Name : " << this->getName() << endl
         << "=========================" << endl
         << "Damage : " << this->getDamage() << endl
         << "Health : " << this->getHealth() << endl
         << "Agility : " << this->getAgility() << endl
         << "Defense : " << this->getDefense() << endl
         << "Mana :" << this->getMana() <<endl;
         //   << "Item : "; this->pObject->show();
         cout << "=========================" << endl
         << endl;
}

void Wizard::updateMana(double _mana)
{
    if(_mana>0)
    {
        //Soins
        if (_mana >= (MAX_MANA - this->getMana()))
        {
            this->mana = MAX_MANA;
        }else
        {
            this->mana +=_mana;
        }
    }else if (_mana<0)
    {
        this->mana += _mana;
    }
}
