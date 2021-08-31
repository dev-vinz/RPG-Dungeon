#include "..\include\wizard.h"

#include <QLabel>

Wizard::Wizard(int _damage ,int _agility ,int _defense ,double _health, double _mana) : Player(_damage, _agility, _defense, _health)
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
QGridLayout *Wizard::show() const
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
QGridLayout *Wizard::showStat() const
{
    QGridLayout *statistics = new QGridLayout;
    //sprite
    QLabel *myimage = new QLabel();
    QPixmap pix("C:/DEV/HES_ETE_Projet/QT/Serie7_Ex1/img/Smiley.jpg");
    pix.scaled(20,20);
    myimage->setPixmap(pix);
    //Name
    QString Name = QString("%1").arg(this->getName());
    QLabel *wizardName = new QLabel(Name);
    //stat
    QLabel *wizardStat1 = new QLabel(QString::number(this->getHealth())+ "/" + QString::number(MAX_HEALTH));
    QLabel *wizardStat2 = new QLabel(QString::number(this->getMana())+ "/" + QString::number(MAX_MANA));
    //add
    statistics->addWidget(myimage,0,0,Qt::AlignCenter);
    statistics->addWidget(wizardName, 1, 0, Qt::AlignCenter);
    statistics->addWidget(wizardStat1,2, 0, Qt::AlignCenter);
    statistics->addWidget(wizardStat2,3, 0, Qt::AlignCenter);
    return statistics;
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
