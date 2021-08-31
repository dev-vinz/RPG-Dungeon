/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>

#include <QGraphicsView>

#include "game.h"
#include "../../map/include/map.h"

class GameManager : public QWidget
{
    Q_OBJECT

public:
    GameManager(QWidget *_parent = nullptr);

    void display();
    void startGame();

    enum ActualDisplay
    {
        GameDisplay,
        MapDisplay
    };

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    ActualDisplay currentDisplay = GameManager::ActualDisplay::MapDisplay;
    Game *game;
    Map *map;

    QGridLayout *createActionButtons();
    QGridLayout *createCharacterStatistics();
    QGridLayout *createInformationsBox();
    QGridLayout *createLegends();
    QGridLayout *createMiniMap();

public slots:
    void refreshGame();

signals:
    void newActionRPG();
};

#endif // GAMEMANAGER_H
