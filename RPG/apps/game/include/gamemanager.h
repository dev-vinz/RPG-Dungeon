/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <map>

#include <QApplication>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>

#include <QGraphicsView>

#include "game.h"
#include "../../map/include/map.h"

class GameManager : public QWidget
{
    Q_OBJECT

    friend class Game;

public:
    GameManager(QWidget *_parent = nullptr);

    void display();
    void startGame();

    enum ActualDisplay
    {
        GameDisplay,
        MapDisplay
    };

    void updateLayout();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    ActualDisplay currentDisplay = GameManager::ActualDisplay::GameDisplay;
    Game *game;
    Map *map;
    QGridLayout *globalGrid = nullptr;
    QGraphicsView *globalView = nullptr;

    std::map<Player *, QLabel *> *playerStatLabel;

    QGridLayout *createActionButtons();
    QGridLayout *createCharacterStatistics();
    QGridLayout *createInformationsBox();
    QGridLayout *createLegends();
    QVBoxLayout *createMiniMap();

    void updateStatistics();

public slots:
    void refreshGame();

signals:
    void newActionRPG();
};

#endif // GAMEMANAGER_H
