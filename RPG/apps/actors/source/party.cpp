#include "..\include\party.h"

Party::Party(Character* _character1,Character*_character2 ,Character*_character3)
{
    myParty.push_front(_character1);
    myParty.push_front(_character2);
    myParty.push_front(_character3);
}

Party::~Party()
{

}
void Party::useBackpack()
{
    cout<<"Bienvenue dans votre sac à dos"<<endl;
    //affichage
    partybackpack.addItem(new Potion(5));
    partybackpack.show();
    //selection de l'objet

    //selection du personnage
    Character *_player = myParty.front();
    //utilisation
    partybackpack.useItem(0, _player);
}
void Party::begin()
{
    myParty.begin();
}
void Party::end()
{
    myParty.end();
}
Character* Party::front()
{
    return myParty.front();
}
void Party::pop_front()
{
    myParty.pop_front();
}
