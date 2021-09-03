#include "..\include\healer.h"

Healer::Healer(int _damage, int _agility, int _defense, double _health) : Player(_damage, _agility, _defense, _health)
{
}

QString Healer::attack1(Character *_character)
{
    //Watch to target a Player and not an Opponent
    int heal = 20;
    //cout << "Vous soignez un allié" << endl;
    _character->updateHealth(heal);

    return QString("%1 a gagné %2 HP").arg(_character->getName(), QString::number(heal));
}

QString Healer::attack2(Character *_character)
{
    QString attack;
    int damage = this->totalDamage(_character);
    //cout << "Vous infligez des dégats." << endl;
    bool hasDodged = _character->updateHealth(-damage);

    if (hasDodged)
    {
        attack = QString("%1 a esquivé l'attaque").arg(_character->getName());
    }
    else
    {
        attack = QString("%1 a perdu %2 points de vie").arg(_character->getName(), QString::number(damage));
    }

    return attack;
}

QGridLayout *Healer::show() const
{
    QGridLayout *statistics = new QGridLayout;
    //Sprite
    QLabel *myimage = new QLabel();
    QPixmap pix("C:/DEV/HES_ETE_Projet/QT/Serie7_Ex1/img/Smiley.jpg");
    pix.scaled(20, 20);
    myimage->setPixmap(pix);
    statistics->addWidget(myimage, 0, 0, Qt::AlignCenter);
    return statistics;
}

QString Healer::showStat() const
{
    //Name
    QString Name = QString("%1").arg(this->getName());
    //Stat
    QLabel *healerStat = new QLabel("HP : " + QString::number(this->getHealth()) + "/" + QString::number(MAX_HEALTH));

    return QString("%1\n%2").arg(Name, healerStat->text());
}
