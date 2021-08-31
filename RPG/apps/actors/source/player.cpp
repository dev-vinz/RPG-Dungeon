#include "..\include\player.h"
#include <QLabel>
#include "..\include\wizard.h"
#include "..\include\warrior.h"
#include "..\include\healer.h"
Player::Player(int _damage, int _agility, int _defense, double _health) : Character(_damage, _agility, _defense, _health)
{

}
void Player::show()
{

    //On affiche le sprit du personnage pour les events
    cout << endl
         << "=========================" << endl
         //<< "Name : " << this->getName() << endl
         << "=========================" << endl
         << "Damage : " << this->getDamage() << endl
         << "Health : " << this->getHealth() << endl
         << "Agility : " << this->getAgility() << endl
         << "Defense : " << this->getDefense() << endl;
         //<< "Item : "; this->pObject->show();
         cout << "=========================" << endl
         << endl;
}

void Player::backpack()
{
    cout<<"Bienvenue dans votre sac à dos"<<endl;
    this->playerBackpack.show();

    this->playerBackpack.useItem(0,this);
    this->playerBackpack.show();
}

void Player::flee()
{
    cout << "Vous fuyez" << endl;
    exit(-1);
}

