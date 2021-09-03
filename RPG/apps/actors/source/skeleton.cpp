#include "..\include\skeleton.h"

QString Skeleton::attack1(Character *_character)
{
    QString attack;
    int damage = this->totalDamage(_character);
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

QString Skeleton::attack2(Character *_character)
{
    QString attack;
    double damage = 1.5 * this->totalDamage(_character);
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

Skeleton::Skeleton(int _damage, int _agility, int _defense, double _health) : Opponent(_damage, _agility, _defense, _health)
{
}

QGridLayout *Skeleton::show() const
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
