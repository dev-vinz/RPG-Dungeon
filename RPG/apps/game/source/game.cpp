#include "../include/game.h"

Game::Game(Map *_map, QWidget *_parent) : QGraphicsView(_parent)
{
    this->map = _map;
    this->createScene();
}

QGraphicsScene *Game::getScene()
{
    return this->gameScene;
}

void Game::play()
{
    if (this->isExitFound) return;

    // Charger la salle
    Room currentRoom = this->map->getActive();

    // Récupérer l'évènement
    Room::RoomType eventType = currentRoom.getType();

    // Appeler EventManager
    if (!currentRoom.isVisited())
        this->releaseEvent(eventType);

    // Interaction avec boutons (Si bataille)

    // Si la sortie est trouvée, arrêter le jeu
    if (this->isExitFound)
        this->end();
}

void Game::start()
{
    this->isExitFound = false;
    this->initializePlayer();

    connect(this->map->getButtonGroup(), &QButtonGroup::buttonClicked, this, &Game::play);

    // TODO : Say Welcome
    this->play();
}

void Game::updateScene()
{
    this->scene()->addRect(100, 100, 300, 100, QPen(Qt::black), QBrush(Qt::yellow));
}

/* * * * * * * * * * * * * * * * *
 * * * * PROTECTED METHODS * * * *
 * * * * * * * * * * * * * * * * */

void Game::battle()
{
    QMessageBox::information(NULL, "Battle", "Nouvelle guerre");
}

void Game::chooseRandomEvent()
{
    QMessageBox::information(NULL, "Event", "Event random");
}

void Game::releaseEvent(Room::RoomType _roomType)
{
    switch (_roomType)
    {
    case Room::RoomType::Battle:
        this->battle();
        break;
    case Room::RoomType::Event:
        this->chooseRandomEvent();
        break;
    case Room::RoomType::Exit:
        this->isExitFound = true;
        QMessageBox::information(NULL, "Exit", "Sortie trouvée");
        break;
    case Room::RoomType::Start:
        QMessageBox::information(NULL, "Start", "Bienvenue en enfer");
        break;
    default:
        qDebug() << "[ERROR] Game::releaseEvent : Unknown type of Room::RoomType";
        exit(-1);
    }
}

void Game::riddle()
{
    QMessageBox::information(NULL, "Riddle", "Nouvelle énigme");
}

void Game::treasure()
{
    QMessageBox::information(NULL, "Treasure", "Nouveau butin");
}

/* * * * * * * * * * * * * * * *
 * * * * PRIVATE METHODS * * * *
 * * * * * * * * * * * * * * * */

void Game::createScene()
{
    QGraphicsScene *gameScene = new QGraphicsScene(this);
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

void Game::initializePlayer()
{

}
