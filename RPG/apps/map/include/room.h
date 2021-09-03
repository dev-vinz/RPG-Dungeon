/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#ifndef ROOM_H
#define ROOM_H

#include <QPushButton>


/*Room class is used for the Map class. It is used to have a PushButton as well as a type and other attributes*/

class Room
{

public:
    enum class RoomType
    {
        Start = 'E',
        Exit = 'S',
        Event = '?',
        Battle = '!'
    };
    Room();
    Room(Room *r);
    /**
     * @brief Constructor used for the room generation in map class in order to have the correct room disposition in the layout
     */
    Room(int, int);  
    QPushButton *roomBtn = new QPushButton;

    //Getters
    int getPosx();
    int getPosy();
    bool isVisited();
    RoomType getType();
    //Setters
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
