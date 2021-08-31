#include "..\include\healer.h"
#include <QLabel>

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
QGridLayout *Healer::showStat() const
{
    QGridLayout *statistics = new QGridLayout;
    //Sprite
    QLabel *myimage = new QLabel();
    QPixmap pix("C:/DEV/HES_ETE_Projet/QT/Serie7_Ex1/img/Smiley.jpg");
    pix.scaled(20,20);
    myimage->setPixmap(pix);
    //Name
    QString Name = QString("%1").arg(this->getName());
    QLabel *healerName = new QLabel(Name);
    //Stat
    QLabel *healerStat = new QLabel(QString::number(this->getHealth())+ "/" + QString::number(MAX_HEALTH));
    //ADD
    statistics->addWidget(myimage,7,0,Qt::AlignCenter);
    statistics->addWidget(healerName, 8, 0, Qt::AlignCenter);
    statistics->addWidget(healerStat,9, 0, Qt::AlignCenter);
return statistics;
}

