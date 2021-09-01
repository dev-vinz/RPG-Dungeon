#include "../include/game.h"
#include "../include/gamemanager.h"

double Game::GAME_RATIO = 1.5;

Game::Game(Map *_map, QWidget *_parent) : QGraphicsView(_parent)
{
    this->map = _map;
    this->createButtons();
    this->createScene();
    this->initializePlayer();
}

QGraphicsScene *Game::getScene()
{
    return this->gameScene;
}

void Game::play()
{
    if (this->isExitFound) return;

    // Load room
    Room currentRoom = this->map->getActive();

    // Get event
    Room::RoomType eventType = currentRoom.getType();

    // Call event manager
    if (!currentRoom.isVisited())
        this->releaseEvent(eventType);

    // TODO : Find other solution
    this->map->rooms[this->map->getActiveId()].setVisited(true);

    // Initial state of buttons
    this->btnMap->setEnabled(true);
    this->btnAttackOne->setEnabled(false);
    this->btnAttackTwo->setEnabled(false);
    this->btnBackpack->setEnabled(true);
    this->btnFlee->setEnabled(false);

    // If exit is found, stop the game
    if (this->isExitFound)
        return this->end();
}

void Game::start()
{
    this->isExitFound = false;

    QObject::connect(this->map->getButtonGroup(), &QButtonGroup::buttonClicked, this, &Game::play);

    // TODO : Say Welcome
    this->play();
}

void Game::updateScene()
{
    this->gameScene->addRect(100, 100, 300, 100, QPen(Qt::black), QBrush(Qt::yellow));
}

/* * * * * * * * * * * * * * * * *
 * * * * PROTECTED METHODS * * * *
 * * * * * * * * * * * * * * * * */

bool Game::battle()
{
    return this->eventManager.battleEvent(&player, this->btnAttackOne, this->btnAttackTwo, this->btnBackpack, this->btnFlee);
}

void Game::chooseRandomEvent()
{

    qint32 e = QRandomGenerator::global()->bounded(1, 5);

    switch (e)
    {
    case 1:
        // Empty room
        QMessageBox::information(NULL, "Event", "CHEH");
        break;
    case 2:
        // Riddle room
    case 3:
        // Riddle room
        this->riddle();
        break;
    case 4:
        this->treasure();
        // Loot room
        break;
    default:
        qDebug() << "[ERROR] Game::chooseRandomEvent : Problem with QRandomGenerator";
        exit(-1);
    }
}

void Game::releaseEvent(Room::RoomType _roomType)
{
    bool doWeContinue = true;

    switch (_roomType)
    {
    case Room::RoomType::Battle:
        doWeContinue = this->battle();
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

    if (!doWeContinue)
    {
        QMessageBox::information(NULL, "Information", "Vous êtes mort, vous avez perdu");
        exit(-1);
    }
}

void Game::riddle()
{
    this->eventManager.riddleEvent(&player);
}

void Game::treasure()
{
    this->eventManager.lootEvent(&player);
}

/* * * * * * * * * * * * * * * *
 * * * * PRIVATE METHODS * * * *
 * * * * * * * * * * * * * * * */

void Game::createButtons()
{
    this->btnMap = new QPushButton("&Ouvrir Map");
    this->btnAttackOne = new QPushButton("Attaque &1");
    this->btnAttackTwo = new QPushButton("Attaque &2");
    this->btnBackpack = new QPushButton("&Sac à Dos");
    this->btnFlee = new QPushButton("&Fuir");

    this->btnAttackOne->setEnabled(false);
    this->btnAttackTwo->setEnabled(false);
    this->btnBackpack->setEnabled(true);
    this->btnFlee->setEnabled(false);
}

void Game::createScene()
{
    QGraphicsScene *gameScene = new QGraphicsScene;
    gameScene->setSceneRect(0, 0, Game::GAME_WIDTH, Game::GAME_HEIGHT);

    gameScene->addRect(gameScene->sceneRect(), QPen(Qt::DashDotLine));

    //this->setScene(gameScene);

    /*qreal w = gameScene->sceneRect().width();
    qreal h = gameScene->sceneRect().height();

    this->fitInView(0, 0, w / this->GAME_RATIO, h / this->GAME_RATIO, Qt::KeepAspectRatioByExpanding);*/

    this->gameScene = gameScene;
}

void Game::end()
{
    QMessageBox::information(NULL, "Fin du Jeu", "Le jeu est terminé");
}

void Game::initializePlayer()
{
    this->player.push_back(new Warrior(80, 20, 90, 100));
    this->player.push_back(new Wizard(70, 50, 60, 100, 100));
    this->player.push_back(new Healer(20, 80, 50, 100));
}
