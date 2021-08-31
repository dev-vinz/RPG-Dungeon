#include "..\include\character.h"
#include "..\include\player.h"

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

void Character::show()
{
    //QString _string = "\n=========================\n" + QString("Damage : ") + QString::number(this->getDamage()) + "\nHealth : " + QString::number(this->getHealth()) + "\nAgility : " + QString::number(this->getAgility()) + "\nDefense : " + QString::number(this->getDefense()) + "\n=========================\n";
    cout << endl
         << "=========================" << endl
         //<< "Name : " << this->getName() << endl
         << "=========================" << endl
         << "Damage : " << this->getDamage() << endl
         << "Health : " << this->getHealth() << endl
         << "Agility : " << this->getAgility() << endl
         << "Defense : " << this->getDefense() << endl
         << "=========================" << endl
         << endl;
    //return _string;
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
