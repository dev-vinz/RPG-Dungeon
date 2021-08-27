#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QtWidgets>
#include <QButtonGroup>
#include <cmath>
#include <QRandomGenerator>
#include <QString>
#include "room.h"

#define NBROFROOMS 24
class Map : public QWidget
{
    Q_OBJECT

public:
    Map(QWidget *parent = nullptr);

    QWidget *window = new QWidget;
    QWidget *miniMapWindow = new QWidget;
    QGridLayout *layout = new QGridLayout(window);
    QGridLayout *miniMapLayout = new QGridLayout(miniMapWindow);

    void changeActive(int);
    void move(int);
    bool checkDist(int);
    ~Map();

protected:
    int activeRoom = 0;
    void createRooms();
    void connectRooms();
    Room rooms[NBROFROOMS];
    void revealMap();
    void revealTile();
    void generateRoomType();
    QButtonGroup *roomsBtnGroup = new QButtonGroup;

};
#endif // MAP_H
