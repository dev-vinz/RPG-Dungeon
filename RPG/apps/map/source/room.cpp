#include "room.h"

Room::Room()
{

}

Room::Room(int _x, int _y)
{
    this->posx = _x;
    this->posy = _y;
    roomBtn->setStyleSheet("QPushButton{ background-color: rgb(0,0,0); }\n");
}

Room::Room(Room *r)
{
    this->posx = r->getPosx();
    this->posy = r->getPosy();
    this->type = r->getType();
    this->visited = r->isVisited();
    //this->active = r->isActive();
    this->roomBtn = r->roomBtn;
}

int Room::getPosx()
{
    return posx;
}
int Room::getPosy()
{
    return posy;
}
RoomType Room::getType()
{
    return this->type;
}
void Room::setVisited(bool v)
{
    this->visited = v;
}
/*
bool Room::isActive()
{
    return active;
}*/
bool Room::isVisited()
{
    return visited;
}
void Room::setType(RoomType t)
{
    this->type = t;
}
Room::~Room()
{

}
