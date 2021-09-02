#include "..\include\player.h"
#include <QLabel>
#include "..\include\wizard.h"
#include "..\include\warrior.h"
#include "..\include\healer.h"
Player::Player(int _damage, int _agility, int _defense, double _health) : Character(_damage, _agility, _defense, _health)
{

}

void Player::flee()
{
    //cout << "Vous fuyez" << endl;
    exit(-1);
}

