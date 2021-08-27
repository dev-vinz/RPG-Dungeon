#include "..\include\battle.h"

Battle::Battle(list<Character*> _myParty, Character* _enemy)
{
    this->myParty = _myParty;
    this->enemy = _enemy;
}

void Battle::startBattle(list<Character*> _myParty, Character* _enemy)
{
    for_each(_myParty.begin(), _myParty.end(), [](Character *n)
    {
        n->show();
    });

    _myParty.front()->interaction(_enemy, attack1);
    _myParty.pop_front();

    _myParty.front()->interaction(_enemy, attack1);
    Player *_player = dynamic_cast<Player *>(_myParty.front());
    _player->backpack();
    _myParty.pop_front();

    Player *_player2 = dynamic_cast<Player *>(_myParty.front());
    _player2->backpack();


    _myParty.pop_front();

}

