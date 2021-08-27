#include "map.h"

Map::Map(QWidget *parent)
    : QWidget(parent)
{
    createRooms();
    generateRoomType();
    changeActive(0);
    connectRooms();
    window->show();
}

void Map::createRooms()
{
    for (int i = 0; i < NBROFROOMS; i++)
    {
        if(i<6)
        {
            rooms[i] = new Room(0,i);

        }
        else if(i<12)
        {
            rooms[i] = new Room(1,i-6);
        }
        else if(i<18)
        {
            rooms[i] = new Room(2 , i - 12);
        }
        else
        {
            rooms[i] = new Room(3,i-18);
        }
        roomsBtnGroup->addButton(rooms[i].roomBtn, i);
        layout->addWidget(rooms[i].roomBtn, rooms[i].getPosx(), rooms[i].getPosy());
    }
}

void Map::connectRooms()
{
    for(int i = 0; i < NBROFROOMS; i++)
    {
        connect(roomsBtnGroup, &QButtonGroup::idClicked, this, &Map::move);
    }
}

void Map::move(int clickedRoomid)
{

    if(checkDist(clickedRoomid))
    {
        changeActive(clickedRoomid);

    }
}
bool Map::checkDist(int otherRoom)
{

    int deltaX, deltaY, delta;
    deltaX = abs(rooms[otherRoom].getPosx()-rooms[activeRoom].getPosx());
    deltaY = abs(rooms[otherRoom].getPosy()-rooms[activeRoom].getPosy());
    delta = deltaX + deltaY;
    return(delta==1);
}



void Map::changeActive(int newActive)
{
    rooms[activeRoom].roomBtn->setText("");
    rooms[activeRoom].roomBtn->setStyleSheet("QPushButton{ background-color: rgb(200,200,200); }\n");
    rooms[activeRoom].setVisited(true);
    activeRoom = newActive;
    rooms[newActive].roomBtn->setText("P");
    rooms[newActive].roomBtn->setStyleSheet("QPushButton{ background-color: rgb(255,255,255); }\n");
    revealTile();

}

void Map::revealTile()
{
    for(int i = 0; i < NBROFROOMS; i++)
    {
        if(checkDist(i)==true && rooms[i].isVisited()==false)
        {
            QString roomType = QChar((char)rooms[i].getType());
            rooms[i].roomBtn->setStyleSheet("QPushButton{ background-color: rgb(100,100,100); }\n");
            rooms[i].roomBtn->setText(roomType);
        }
    }
}
void Map::generateRoomType()
{
    int exitIndex = QRandomGenerator::global()->bounded(1,25);
    for(int i = 0; i < NBROFROOMS; i++)
    {
        if(i==0)
        {
            rooms[i].setType(RoomType::Start);
        }
        else if(i==exitIndex)
        {
            rooms[i].setType(RoomType::Exit);
        }
        else
        {
            int randEvent = QRandomGenerator::global()->bounded(0,2);
            if(randEvent == 0)
            {
                rooms[i].setType(RoomType::Event);
            }
            else
            {
                rooms[i].setType(RoomType::Battle);
            }
        }
    }
}
Map::~Map()
{
}

