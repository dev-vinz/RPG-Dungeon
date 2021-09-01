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
    //window->show(); //Used only for display when not connected to gameManger
    //miniMapWindow->show();//Used only for display when not connected to gameManger
}

int Map::getActiveId() const
{
    return this->activeRoom;
}

void Map::changeActive(int newActive)
{
    //IF condition to keep "E" active on the entry room of the dungeon
    if(rooms[activeRoom].getType() != Room::RoomType::Start)
    {
       rooms[activeRoom].roomBtn->setText("");
    }
    else
    {
        rooms[activeRoom].roomBtn->setText("E");
    }
    //Sets new colors for visited and active rooms
    rooms[activeRoom].roomBtn->setStyleSheet("QPushButton{ background-color: rgb(200,200,200); }\n QPushButton:disabled{ color: black; }\n");
    rooms[activeRoom].setVisited(true);
    activeRoom = newActive;
    rooms[newActive].roomBtn->setText("P");
    rooms[newActive].roomBtn->setStyleSheet("QPushButton{ background-color: rgb(255,255,255); }\n QPushButton:disabled{ color: black; }\n");
    //rooms[newActive].setVisited(true);
    revealTile();
}

bool Map::checkDist(int otherRoom)
{
    //By checking distance in x and y in the layout, it is possible to assume the distance between two rooms.
    //If it is strictly equal to 1 the rooms are adjacent. A diagonal room would be equal to 2
    return(getDist(otherRoom)==1);
}
int Map::getDist(int otherRoom)
{
    int deltaX, deltaY, delta;
    deltaX = abs(rooms[otherRoom].getPosx()-rooms[activeRoom].getPosx());
    deltaY = abs(rooms[otherRoom].getPosy()-rooms[activeRoom].getPosy());
    delta = deltaX + deltaY;
    return delta;
}

int Map::checkDistX(int otherRoom)
{
    return rooms[otherRoom].getPosx()-rooms[activeRoom].getPosx();
}

int Map::checkDistY(int otherRoom)
{
    return rooms[otherRoom].getPosy()-rooms[activeRoom].getPosy();
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
        rooms[i].roomBtn->setMinimumSize(MINWIDTH, MINHEIGHT);
        rooms[i].roomBtn->setMaximumSize(MAXWIDTH, MAXHEIGHT);
    }

    this->createScene(1700, 1000);
}

void Map::createScene(int _width, int _height)
{
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, _width, _height);

    const int SPACE_WIDTH = 100;
    const int SPACE_HEIGHT = 100;

    for (int k = 0; k < NBROFROOMS; k++)
    {
        Room room = this->rooms[k];
        QPushButton *btn = room.roomBtn;

        btn->setGeometry(SPACE_WIDTH * room.getPosy(), SPACE_HEIGHT * room.getPosx(), 90, 90);

        scene->addWidget(btn);
    }

    this->mapScene = scene;
}

void Map::connectRooms()
{
    for(int i = 0; i < NBROFROOMS; i++)
    {
        connect(roomsBtnGroup, &QButtonGroup::idClicked, this, &Map::move);
    }
}

void Map::generateMiniMap()
{
    miniMapLayout->setVerticalSpacing(VERTICALSPACING);
    miniMapLayout->setHorizontalSpacing(HORIZONTALSPACING);

    //activeMini button never changes stylesheet, it is defined here
    activeMini->setText(rooms[activeRoom].roomBtn->text());
    activeMini->setStyleSheet("QPushButton:disabled{ background-color: rgb(255,255,255);color: black; }\n");

    //The five buttons are added to the miniMap, they will be set in/visible when updateMiniMap() is called
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

    QSizePolicy sp_retain_top = topMini->sizePolicy();
    sp_retain_top.setRetainSizeWhenHidden(true);
    topMini->setSizePolicy(sp_retain_top);

    QSizePolicy sp_retain_left = leftMini->sizePolicy();
    sp_retain_left.setRetainSizeWhenHidden(true);
    leftMini->setSizePolicy(sp_retain_left);

    QSizePolicy sp_retain_right = rightMini->sizePolicy();
    sp_retain_right.setRetainSizeWhenHidden(true);
    rightMini->setSizePolicy(sp_retain_right);

    QSizePolicy sp_retain_bottom = bottomMini->sizePolicy();
    sp_retain_bottom.setRetainSizeWhenHidden(true);
    bottomMini->setSizePolicy(sp_retain_bottom);

    activeMini->setMinimumSize(MINWIDTH, MINHEIGHT);
    activeMini->setMaximumSize(MAXWIDTH, MAXHEIGHT);
    topMini->setMinimumSize(MINWIDTH, MINHEIGHT);
    topMini->setMaximumSize(MAXWIDTH, MAXHEIGHT);
    leftMini->setMinimumSize(MINWIDTH, MINHEIGHT);
    leftMini->setMaximumSize(MAXWIDTH, MAXHEIGHT);
    rightMini->setMinimumSize(MINWIDTH, MINHEIGHT);
    rightMini->setMaximumSize(MAXWIDTH, MAXHEIGHT);
    bottomMini->setMinimumSize(MINWIDTH, MINHEIGHT);
    bottomMini->setMaximumSize(MAXWIDTH, MAXHEIGHT);
}

void Map::generateRoomType()
{

    //Random determines exit room index
    int exitIndex = 0;
    do
    {
        exitIndex=QRandomGenerator::global()->bounded(1,25);
    }
    while(getDist(exitIndex) < 3);

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

void Map::move(int clickedRoomid)
{

    if(checkDist(clickedRoomid))
    {
        changeActive(clickedRoomid);
        updateMiniMap();
    }
}

QGraphicsScene *Map::getScene() const
{
    return this->mapScene;
}

void Map::revealTile()
{
    for(int i = 0; i < NBROFROOMS; i++)
    {
        if(checkDist(i)==true && rooms[i].isVisited()==false)
        {
            QString roomType = QChar((char)rooms[i].getType());
            rooms[i].roomBtn->setStyleSheet("QPushButton{ background-color: rgb(100,100,100); }\n QPushButton:disabled{ color: black; }\n");
            rooms[i].roomBtn->setText(roomType);
        }
    }
}

void Map::updateMiniMap()
{
    //The miniMap buttons are always set to invisible, they will be set back to visible they are neighboring the active room
    topMini->setVisible(false);
    leftMini->setVisible(false);
    rightMini->setVisible(false);
    bottomMini->setVisible(false);
    for (int i = 0; i < NBROFROOMS; i++)
    {
        //TOP Button
        if(checkDistX(i) == -1 && checkDistY(i)==0)
        {
            topMini->setText(rooms[i].roomBtn->text());
            topMini->setStyleSheet(rooms[i].roomBtn->styleSheet());
            topMini->setVisible(true);
        }
        //LEFT button
        else if(checkDistX(i) == 0 && checkDistY(i)==-1)
        {
            leftMini->setText(rooms[i].roomBtn->text());
            leftMini->setStyleSheet(rooms[i].roomBtn->styleSheet());
            leftMini->setVisible(true);
        }
        //RIGHT button
        else if(checkDistX(i) == 0 && checkDistY(i)== 1)
        {
            rightMini->setText(rooms[i].roomBtn->text());
            rightMini->setStyleSheet(rooms[i].roomBtn->styleSheet());
            rightMini->setVisible(true);
        }
        //BOTTOM button
        else if(checkDistX(i) == 1 && checkDistY(i)==0)
        {
            bottomMini->setText(rooms[i].roomBtn->text());
            bottomMini->setStyleSheet(rooms[i].roomBtn->styleSheet());
            bottomMini->setVisible(true);
        }
    }

    miniMapLayout->setVerticalSpacing(VERTICALSPACING);
    miniMapLayout->setHorizontalSpacing(HORIZONTALSPACING);
}


QButtonGroup *Map::getButtonGroup() const
{
    return this->roomsBtnGroup;
}

QGridLayout *Map::getMap() const
{
    return layout;
}

QGridLayout *Map::getMiniMap() const
{
    return miniMapLayout;
}

Map::~Map()
{
}

