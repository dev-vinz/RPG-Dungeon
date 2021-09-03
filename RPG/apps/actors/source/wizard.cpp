#include "..\include\wizard.h"

Wizard::Wizard(int _damage, int _agility, int _defense, double _health, double _mana) : Player(_damage, _agility, _defense, _health)
{
    this->mana = _mana;
}

QString Wizard::attack1(Character *_character)
{
    QString attack;
    //cout << "Vous faites une attaque simple" << endl;
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

QString Wizard::attack2(Character *_character)
{
    QString attack;
    int manaCost = 8;
    if (manaCost > this->getMana())
    {
        //globalLabel->UpdateText("Vous n'avez pas assez de mana.");
        //cout <<"Vous n'avez pas assez de mana." << endl;
        attack = "Vous n'avez pas assez de mana\n";
        return attack.append(this->interaction(_character, Action::attack1));
    }
    else
    {
        this->updateMana(-manaCost);
        //cout << "Vous faire une grosse attaque" << endl;
        int damage = this->totalDamage(_character) + 10;
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
}

QGridLayout *Wizard::show() const
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

QString Wizard::showStat() const
{
    //Name
    QString Name = QString("%1").arg(this->getName());
    //stat
    QLabel *wizardStat1 = new QLabel("HP : " + QString::number(this->getHealth()) + "/" + QString::number(MAX_HEALTH));
    QLabel *wizardStat2 = new QLabel("Mana : " + QString::number(this->getMana()) + "/" + QString::number(MAX_MANA));

    return QString("%1\n%2\n%3").arg(Name, wizardStat1->text(), wizardStat2->text());
}

void Wizard::updateMana(double _mana)
{
    if (_mana > 0)
    {
        //Soins
        if (_mana >= (MAX_MANA - this->getMana()))
        {
            this->mana = MAX_MANA;
        }
        else
        {
            this->mana += _mana;
        }
    }
    else if (_mana < 0)
    {
        this->mana += _mana;
    }
}
