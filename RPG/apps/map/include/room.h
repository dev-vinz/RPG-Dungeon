#ifndef ROOM_H
#define ROOM_H

#include <QPushButton>
enum class RoomType
{
    Start = 'E',
    Exit = 'S',
    Event = '?',
    Battle = '!',
    Current = 'P'
};

class Room
{

public:
    Room();
    Room(Room *r);
    Room(int, int);
    int getPosx();
    int getPosy();
    bool isVisited();
    void setVisited(bool);
    void setType(RoomType);
    //bool isActive();
    RoomType getType();
    QPushButton *roomBtn = new QPushButton;
    ~Room();

protected:
    int posx;
    int posy;
    bool visited = false;
    //bool active;
    RoomType type;


};

#endif // ROOM_H
