/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef GAME_H
#define GAME_H

#include <deque>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>

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

#include "../../../settings/settings.h"

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

    Opponent *opponent = nullptr;

    QLabel *labelInformations = nullptr;
    QTime startGame;

    QPushButton *btnMap;
    QPushButton *btnAttackOne;
    QPushButton *btnAttackTwo;
    QPushButton *btnBackpack;
    QPushButton *btnFlee;

    Opponent *getOpponent() const;

    void addSceneOpponent(Opponent *_opponent);
    void addScenePlayers();
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
    void setLabelInformations(QLabel *_label);
    void start();
    void updateScene(EventManager::Event _event = EventManager::Event::NothingEvent, Opponent *_opponent = nullptr);

protected:
    bool battle();
    void chooseRandomEvent();
    void releaseEvent(Room::RoomType);
    void riddle();
    void treasure();
};

#endif // GAME_H
