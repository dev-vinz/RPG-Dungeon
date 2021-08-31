#include "..\include\warrior.h"
#include <QLabel>
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

QGridLayout *Warrior::showStat() const
{
    QGridLayout *statistics = new QGridLayout;
    //Sprite
    QLabel *myimage = new QLabel();
    QPixmap pix("C:/DEV/HES_ETE_Projet/QT/Serie7_Ex1/img/Smiley.jpg");
    pix.scaled(20,20);
    myimage->setPixmap(pix);
    //Name
    QString Name = QString("%1").arg(this->getName());
    QLabel *warriorName = new QLabel(Name);
    //Stat
    QLabel *warriorStat = new QLabel(QString::number(this->getHealth())+ "/" + QString::number(MAX_HEALTH));
    //Add
    statistics->addWidget(myimage,4,0,Qt::AlignCenter);
    statistics->addWidget(warriorName, 5, 0, Qt::AlignCenter);
    statistics->addWidget(warriorStat,6, 0, Qt::AlignCenter);
    return statistics;
}
