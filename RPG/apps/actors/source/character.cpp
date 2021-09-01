#include "..\include\character.h"
#include "..\include\player.h"
#include <QLabel>
Character::Character(int _damage, int _agility, int _defense, double _health)
{
    this->damage = _damage;
    this->agility = _agility;
    this->defense = _defense;
    this->health = _health;
}
Character::~Character()
{

}

QGridLayout *Character::show() const
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

bool Character::isAlive()
{
    return(getHealth()>0);
}

bool Character::dodge()
{
    qint32 v = QRandomGenerator::global()->bounded(0, 101);
    return (v % 100 + 1 <= this->getAgility());
}

int Character::totalDamage(Character *_character)
{
    int total = ((this->getDamage()) * (100.0/(100+_character->getDefense())));
    return total;
}
#include <QMessageBox>
void Character::updateHealth(double _health)
{
    if(_health>0)
    {
        //cout << this->getName() +" gagne des points de vie" << endl;
        if (_health >= (MAX_HEALTH - this->getHealth()))
        {
            this->health = MAX_HEALTH;
            //globalLabel->UpdateText("Vous regagnez tous vos Hp.");
        }
        else
        {
            this->health += _health;
            //globalLabel->UpdateText("Vous vous soignez de " + to_string(_health) + "Hp.");
        }
    }else if (_health<0)
    {
        //cout << this->getName() << " perds de points de vie" << endl;
        if (this->dodge())
        {
            QMessageBox::information(NULL, "Character", QString("%1 a dodge").arg(this->getName()));
            //globalLabel->UpdateText("Bravo vous avez esquivé l'attaque");
            //cout << this->getName() << " a esquivé l'attaque" << endl;
        } else
        {
            //Since damage are counted as negatives we must add them to the total health
            this->health += _health;
        }
    }
}

void Character::interaction(Character* _character, Action _action)
{
    Player *_player = dynamic_cast<Player *>(this);
    switch(_action)
    {
        case Action::attack1:
        this->attack1(_character);
        break;
        case Action::attack2:
        this->attack2(_character);
        break;
        case Action::backpack:
        _player->backpack();
        break;
        case Action::flee:
        _player->flee();
        break;

        default:
            //Retour au choix des boutons
            exit(-1);
    }
}
