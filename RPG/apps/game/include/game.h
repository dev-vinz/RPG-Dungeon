/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "../../event/include/eventmanager.h"
#include "../../map/include/map.h"

#include <QLabel>

class Game : public QGraphicsView
{
    Q_OBJECT

private:
    const double GAME_RATIO = 1.5;
    const int GAME_WIDTH = 1700;
    const int GAME_HEIGHT = 1000;

    bool isExitFound = false;

    EventManager eventManager;
    Map *map;
    QGraphicsScene *gameScene;

    void createScene();
    void end();
    void initializePlayer();

public:
    Game(Map *_map, QWidget *_parent = nullptr);

    QGraphicsScene *getScene();

    void play();
    void start();
    void updateScene();

protected:
    void battle();
    void chooseRandomEvent();
    void releaseEvent(Room::RoomType);
    void riddle();
    void treasure();
};

#endif // GAME_H
