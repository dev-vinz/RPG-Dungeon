#include "..\include\map.h"

Map::Map(QWidget *parent)
    : QWidget(parent)
{
    createRooms();
    generateRoomType();
    changeActive(0);
    connectRooms();
    generateMiniMap();
    updateMiniMap();

    //window->show();
    //miniMapWindow->show();
}

QGridLayout *Map::getMiniMap() const
{
    return this->miniMapLayout;
}

QGridLayout *Map::getMap() const
{
    return this->layout;
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
        updateMiniMap();
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
int Map::checkDistX(int otherRoom)
{
    return rooms[otherRoom].getPosx()-rooms[activeRoom].getPosx();
}
int Map::checkDistY(int otherRoom)
{
    return rooms[otherRoom].getPosy()-rooms[activeRoom].getPosy();
}
void Map::generateMiniMap()
{
    activeMini->setStyleSheet(rooms[activeRoom].roomBtn->styleSheet());
    activeMini->setText(rooms[activeRoom].roomBtn->text());
    miniMapLayout->addWidget(topMini,0,1);
    miniMapLayout->addWidget(leftMini,1,0);
    miniMapLayout->addWidget(rightMini,1,2);
    miniMapLayout->addWidget(bottomMini, 2, 1);
    miniMapLayout->addWidget(activeMini, 1,1);
    topMini->setEnabled(false);
    leftMini->setEnabled(false);
    rightMini->setEnabled(false);
    bottomMini->setEnabled(false);
    activeMini->setEnabled(false);

}
void Map::updateMiniMap()
{
    topMini->setVisible(false);
    leftMini->setVisible(false);
    rightMini->setVisible(false);
    bottomMini->setVisible(false);
    for (int i = 0; i < NBROFROOMS; i++)
    {
        if(checkDistX(i) == -1 && checkDistY(i)==0)
        {
            topMini->setText(rooms[i].roomBtn->text());
            topMini->setStyleSheet(rooms[i].roomBtn->styleSheet());
            topMini->setVisible(true);
        }
        else if(checkDistX(i) == 0 && checkDistY(i)==-1)
        {
            leftMini->setText(rooms[i].roomBtn->text());
            leftMini->setStyleSheet(rooms[i].roomBtn->styleSheet());
            leftMini->setVisible(true);
        }
        else if(checkDistX(i) == 0 && checkDistY(i)== 1)
        {
            rightMini->setText(rooms[i].roomBtn->text());
            rightMini->setStyleSheet(rooms[i].roomBtn->styleSheet());
            rightMini->setVisible(true);
        }
        else if(checkDistX(i) == 1 && checkDistY(i)==0)
        {
            bottomMini->setText(rooms[i].roomBtn->text());
            bottomMini->setStyleSheet(rooms[i].roomBtn->styleSheet());
            bottomMini->setVisible(true);
        }
    }
}
void Map::changeActive(int newActive)
{
    if(rooms[activeRoom].getType() != Room::RoomType::Start)
    {
       rooms[activeRoom].roomBtn->setText("");
    }
    else
    {
        rooms[activeRoom].roomBtn->setText("E");
    }
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
            rooms[i].setType(Room::RoomType::Start);
        }
        else if(i==exitIndex)
        {
            rooms[i].setType(Room::RoomType::Exit);
        }
        else
        {
            int randEvent = QRandomGenerator::global()->bounded(0,2);
            if(randEvent == 0)
            {
                rooms[i].setType(Room::RoomType::Event);
            }
            else
            {
                rooms[i].setType(Room::RoomType::Battle);
            }
        }
    }
}

Room Map::getActive()
{
    return rooms[activeRoom];
}

QButtonGroup *Map::getButtonGroup() const
{
    return this->roomsBtnGroup;
}

Map::~Map()
{
}

