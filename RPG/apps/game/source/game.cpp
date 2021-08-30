#include "../include/game.h"

Game::Game(QSize _size, Map *_map, QWidget *_parent) : QGraphicsView(_parent)
{
    this->map = _map;
    this->createScene(_size);
}

QGraphicsScene *Game::getScene()
{
    return this->gameScene;
}

void Game::start()
{
    this->isPlaying = true;

    // Initialisation de l'équipe et des adversaires (nb donné par map)

    while (this->isPlaying)
    {
        // Charger la salle
        // Récupérer l'évènement
        // Appeler EventManager
        // Interaction avec boutons (Si bataille)
        // Boucle

        this->isPlaying = false;
    }

    this->end();
}

void Game::updateScene()
{
    this->scene()->addRect(100, 100, 300, 100, QPen(Qt::black), QBrush(Qt::yellow));
}

/* * * * * * * * * * * * * * * *
 * * * * PRIVATE METHODS * * * *
 * * * * * * * * * * * * * * * */

void Game::createScene(QSize _size)
{
    QGraphicsScene *gameScene = new QGraphicsScene(this);
    //gameScene->setSceneRect(0, 0, _size.width(), _size.height());
    gameScene->setSceneRect(0, 0, Game::GAME_WIDTH, Game::GAME_HEIGHT);

    gameScene->addRect(gameScene->sceneRect(), QPen(Qt::DashDotLine));

    this->setScene(gameScene);

    qreal w = gameScene->sceneRect().width();
    qreal h = gameScene->sceneRect().height();

    this->fitInView(0, 0, w / this->GAME_RATIO, h / this->GAME_RATIO, Qt::KeepAspectRatioByExpanding);

    this->gameScene = gameScene;
}

void Game::end()
{
    QMessageBox::information(NULL, "Fin du Jeu", "Le jeu est terminé");
}
