#include "..\include\warrior.h"
#include <QLabel>

#include <QMessageBox>

void Warrior::attack1(Character* _character)
{
    //cout << "Vous protegez un allié" << endl;
    _character->show();
    QMessageBox::information(NULL, "Warrior", QString("Help on %1").arg(_character->getName()));
}

void Warrior::attack2(Character* _character)
{
    QMessageBox::information(NULL, "Warrior", QString("Attack on %1").arg(_character->getName()));
    int damage = this->totalDamage(_character);
    //cout << "Vous infligez des dégats" << endl;
    _character->updateHealth(-damage);
}

Warrior::Warrior(int _damage ,int _agility ,int _defense ,double _health) :Player (_damage, _agility, _defense, _health)
{

}

QString Warrior::showStat() const
{
    //Name
    QString Name = QString("%1").arg(this->getName());
    //Stat
    QLabel *warriorStat = new QLabel("HP : " + QString::number(this->getHealth())+ "/" + QString::number(MAX_HEALTH));

    return QString("%1\n%2").arg(Name, warriorStat->text());
}

QGridLayout *Warrior::show() const{
    QGridLayout *statistics = new QGridLayout;
    //Sprite
    QLabel *myimage = new QLabel();
    QPixmap pix("C:/DEV/HES_ETE_Projet/QT/Serie7_Ex1/img/Smiley.jpg");
    pix.scaled(20,20);
    myimage->setPixmap(pix);
    statistics->addWidget(myimage,0,0,Qt::AlignCenter);
    return statistics;
}
