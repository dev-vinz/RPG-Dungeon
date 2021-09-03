#include "..\include\warrior.h"

Warrior::Warrior(int _damage, int _agility, int _defense, double _health) : Player(_damage, _agility, _defense, _health)
{
}

QString Warrior::attack1(Character *_character)
{
    //cout << "Vous protegez un allié" << endl;
    int updateDef = 3;
    _character->updateDefense(updateDef);

    return QString("%1 gagne %2 points de défense").arg(_character->getName(), QString::number(updateDef));
}

QString Warrior::attack2(Character *_character)
{
    QString attack;
    int damage = this->totalDamage(_character);
    //cout << "Vous infligez des dégats" << endl;
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

QGridLayout *Warrior::show() const
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

QString Warrior::showStat() const
{
    //Name
    QString Name = QString("%1").arg(this->getName());
    //Stat
    QLabel *warriorStat = new QLabel("HP : " + QString::number(this->getHealth()) + "/" + QString::number(MAX_HEALTH));

    return QString("%1\n%2").arg(Name, warriorStat->text());
}
