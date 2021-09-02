/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#ifndef GAME_H
#define GAME_H

#include <deque>

#include <QGraphicsView>
#include <QGraphicsScene>

#include "../../actors/include/ghoul.h"
#include "../../actors/include/healer.h"
#include "../../actors/include/opponent.h"
#include "../../actors/include/player.h"
#include "../../actors/include/skeleton.h"
#include "../../actors/include/warrior.h"
#include "../../actors/include/wizard.h"

#include "../../event/include/eventmanager.h"
#include "../../map/include/map.h"

#include "../../stuff/include/backpack.h"

#include <QLabel>

class Game : public QGraphicsView
{
    Q_OBJECT

    friend class GameManager;

private:
    const int GAME_WIDTH = 1700;
    const int GAME_HEIGHT = 1000;

    bool isExitFound = false;
    std::deque<Player *> player;
    Backpack *playerBackpack;
    std::map<Player *, QLabel *> *statsLabel;

    EventManager *eventManager;
    Map *map;
    QGraphicsScene *gameScene;

    QPushButton *btnMap;
    QPushButton *btnAttackOne;
    QPushButton *btnAttackTwo;
    QPushButton *btnBackpack;
    QPushButton *btnFlee;

    void createButtons();
    void createScene();
    void end();
    void initializePlayer();

public:
    static double GAME_RATIO;
    Game(Map *_map, QWidget *_parent = nullptr);

    std::map<Player *, QLabel *> *createStatsLabel();

    QGraphicsScene *getScene();

    void play();
    void start();
    void updateScene();

protected:
    bool battle();
    void chooseRandomEvent();
    void releaseEvent(Room::RoomType);
    void riddle();
    void treasure();
};

#endif // GAME_H
