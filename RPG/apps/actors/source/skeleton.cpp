#include "..\include\skeleton.h"

#include <QLabel>
void Skeleton::attack1(Character* _character)
{
    int damage = this->totalDamage(_character);
    _character->updateHealth(-damage);
}

void Skeleton::attack2(Character* _character)
{
    int damage = this->totalDamage(_character);
    _character->updateHealth(-damage);
}
Skeleton::Skeleton(int _damage ,int _agility ,int _defense ,double _health) : Opponent(_damage, _agility, _defense, _health)
{

}
QGridLayout *Skeleton::show() const
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
