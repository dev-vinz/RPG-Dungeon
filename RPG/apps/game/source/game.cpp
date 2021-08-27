#include "game.h"

Game::Game(QSize _size, Map *_map, QWidget *_parent) : QGraphicsView(_parent)
{
    /*QGraphicsScene *mainScene = new QGraphicsScene(this);

    this->setBackgroundBrush(QBrush(Qt::gray));
    //resize(_size.width() / 1.3, _size.height() / 2.0);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mainScene->setSceneRect(0, 0, width(), height());

    this->setScene(mainScene);

    mainScene->addRect(mainScene->sceneRect(), QPen(Qt::DashDotLine));
    //mainScene->addRect(0, 0, width(), height(), QPen(Qt::black), QBrush(Qt::red));*/
}

QGraphicsScene *Game::getScene()
{

}
