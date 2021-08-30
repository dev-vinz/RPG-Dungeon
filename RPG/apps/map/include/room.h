/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#ifndef ROOM_H
#define ROOM_H

#include <QPushButton>



class Room
{

public:
    enum class RoomType
    {
        Start = 'E',
        Exit = 'S',
        Event = '?',
        Battle = '!',
        Current = 'P'
    };
    Room();
    Room(Room *r);
    Room(int, int);  
    QPushButton *roomBtn = new QPushButton;

    int getPosx();
    int getPosy();
    bool isVisited();
    RoomType getType();

    void setVisited(bool);
    void setType(RoomType);

    ~Room();

protected:
    int posx;
    int posy;
    bool visited = false;
    RoomType type;


};

#endif // ROOM_H
