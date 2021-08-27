#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include <QGraphicsView>

#include "game.h"
#include "map.h"

class GameManager : public QWidget
{
    Q_OBJECT

private:
    bool isGameDisplaying = true;
    Game *game;
    Map *map;

    QGridLayout *createActionButtons();
    QGridLayout *createCharacterStatistics();
    QGridLayout *createGameLayout();
    QGridLayout *createInformationsBox();
    QGridLayout *createLegends();
    QGridLayout *createMiniMap();

public:
    GameManager(QWidget *_parent = nullptr);

    void display();
};

#endif // GAMEMANAGER_H
