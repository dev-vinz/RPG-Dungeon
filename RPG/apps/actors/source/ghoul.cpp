#include "..\include\ghoul.h"
#include <QLabel>
Ghoul::Ghoul(int _damage ,int _agility ,int _defense ,double _health/*, *pObject*/) : Oponnent(_damage, _agility, _defense, _health)
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
QGridLayout *Ghoul::show() const
{
    QGridLayout *statistics = new QGridLayout;
    //Sprite
    QLabel *myimage = new QLabel();
    QPixmap pix("C:/DEV/HES_ETE_Projet/QT/Serie7_Ex1/img/Smiley.jpg");
    pix.scaled(20,20);
    myimage->setPixmap(pix);
    statistics->addWidget(myimage,0,0,Qt::AlignCenter);
    return statistics;
}
