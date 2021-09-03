#include "..\include\player.h"
Player::Player(int _damage, int _agility, int _defense, double _health) : Character(_damage, _agility, _defense, _health)
{
}

void Player::flee()
{
    exit(-1);
}
