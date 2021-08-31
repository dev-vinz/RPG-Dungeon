/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

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
    QGridLayout *layout = new QGridLayout;
    QGridLayout *miniMapLayout = new QGridLayout;

    QPushButton *topMini = new QPushButton;
    QPushButton *leftMini = new QPushButton;
    QPushButton *rightMini = new QPushButton;
    QPushButton *bottomMini = new QPushButton;
    QPushButton *activeMini = new QPushButton;

    Room getActive();
    QButtonGroup *getButtonGroup() const;

    void changeActive(int);
    void move(int);
    bool checkDist(int);
    int checkDistX(int);
    int checkDistY(int);

    QGridLayout *getMiniMap() const;
    QGridLayout *getMap() const;

    ~Map();

protected:
    int activeRoom = 0;
    void createRooms();
    void connectRooms();
    Room rooms[NBROFROOMS];
    void revealMap();
    void revealTile();
    void generateRoomType();
    void generateMiniMap();
    void updateMiniMap();

    QButtonGroup *roomsBtnGroup = new QButtonGroup;




};
#endif // MAP_H
