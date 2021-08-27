#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "map.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QSize _size, Map *_map, QWidget *_parent = nullptr);

    QGraphicsScene *getScene();
};

#endif // GAME_H
