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

std::map<Player *, QLabel *> *Game::createStatsLabel()
{
    this->statsLabel = new std::map<Player *, QLabel *>();

    for (Player *p : this->player)
    {
        QLabel *playerStat = new QLabel;

        this->statsLabel->insert_or_assign(p, playerStat);
    }

    return this->statsLabel;
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
    this->btnFlee->setEnabled(true);

    // If exit is found, stop the game
    if (this->isExitFound)
        return this->end();
}

void Game::setLabelInformations(QLabel *_label)
{
    this->labelInformations = _label;
    this->playerBackpack = new Backpack(&player, _label);
    this->eventManager = new EventManager(this->statsLabel, _label);
}

void Game::start()
{
    this->isExitFound = false;

    QObject::connect(this->map->getButtonGroup(), &QButtonGroup::buttonClicked, this, &Game::play);

    // TODO : Say Welcome
    this->update();
    this->startGame = QTime::currentTime();
    this->play();
}

void Game::updateScene(EventManager::Event _event, Opponent *_opponent)
{
    // Update scene in function of room

    this->gameScene->clear();

    this->gameScene->addRect(gameScene->sceneRect(), QPen(Qt::DashDotLine));

    QPixmap basic("../img/rooms/basicRoom.png");
    QPixmap loot("../img/rooms/lootRoom.png");
    QPixmap riddle("../img/rooms/riddleRoom.png");

    basic = basic.scaled(this->gameScene->sceneRect().width(), this->gameScene->sceneRect().height(), Qt::KeepAspectRatioByExpanding);
    loot = loot.scaled(this->gameScene->sceneRect().width(), this->gameScene->sceneRect().height(), Qt::KeepAspectRatioByExpanding);
    riddle = riddle.scaled(this->gameScene->sceneRect().width(), this->gameScene->sceneRect().height(), Qt::KeepAspectRatioByExpanding);

    Room currentRoom = this->map->getActive();

    if (currentRoom.isVisited())
    {
        this->gameScene->setBackgroundBrush(QBrush(basic));
    }
    else
    {
        switch (_event)
        {
        case EventManager::Event::NothingEvent:
            this->gameScene->setBackgroundBrush(QBrush(basic));
            break;
        case EventManager::Event::LootEvent:
            this->gameScene->setBackgroundBrush(QBrush(loot));
            break;
        case EventManager::Event::RiddleEvent:
            this->gameScene->setBackgroundBrush(QBrush(riddle));
            break;
        default:
            qDebug() << "[ERROR] Game::updateScene : Unknown state of EventManager::Event";
            exit(-1);
        }
    }

    this->addScenePlayers();

    if (_opponent != nullptr)
        this->addSceneOpponent(_opponent);
}

/* * * * * * * * * * * * * * * * *
 * * * * PROTECTED METHODS * * * *
 * * * * * * * * * * * * * * * * */

bool Game::battle()
{
    this->opponent = new Ghoul(50, 20, 40, 100);
    this->updateScene(EventManager::Event::NothingEvent, this->opponent);
    bool win = this->eventManager->battleEvent(&player, this->opponent, this->btnAttackOne, this->btnAttackTwo);
    this->opponent = nullptr;
    this->updateScene();

    return win;
}

void Game::chooseRandomEvent()
{
    qint32 e = QRandomGenerator::global()->bounded(1, 5);

    switch (e)
    {
    case 1:
        // Empty room
        this->updateScene(EventManager::Event::NothingEvent);
        //QMessageBox::information(NULL, "Event", "CHEH");
        this->labelInformations->setText("Hum... il n'y a pas grand chose par ici...");
        break;
    case 2:
        // Riddle room
    case 3:
        // Riddle room
        this->updateScene(EventManager::Event::RiddleEvent);
        this->riddle();
        break;
    case 4:
        this->updateScene(EventManager::Event::LootEvent);
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
    this->eventManager->riddleEvent(&player);
}

void Game::treasure()
{
    IObject *treasure = this->eventManager->lootEvent();

    this->playerBackpack->addItem(treasure);
}

/* * * * * * * * * * * * * * * *
 * * * * PRIVATE METHODS * * * *
 * * * * * * * * * * * * * * * */

Opponent *Game::getOpponent() const
{
    return this->opponent;
}

void Game::addSceneOpponent(Opponent *_opponent)
{
    QPixmap opp(QString("../img/characters/sprite_%1.png").arg(_opponent->getName().toLower()));

    opp = opp.scaled(150, 150, Qt::KeepAspectRatioByExpanding);

    QGraphicsPixmapItem *iOpp = new QGraphicsPixmapItem(opp);

    iOpp->setPos(1050, 250);

    this->gameScene->addItem(iOpp);
}

void Game::addScenePlayers()
{
    QPixmap warrior("../img/characters/sprite_guerrier.png");
    QPixmap wizard("../img/characters/sprite_sorcier.png");
    QPixmap healer("../img/characters/sprite_soigneur.png");

    warrior = warrior.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    wizard = wizard.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    healer = healer.scaled(100, 100, Qt::KeepAspectRatioByExpanding);

    QGraphicsPixmapItem *iWarrior = new QGraphicsPixmapItem(warrior);
    QGraphicsPixmapItem *iWizard = new QGraphicsPixmapItem(wizard);
    QGraphicsPixmapItem *iHealer = new QGraphicsPixmapItem(healer);

    iWarrior->setPos(650, 350);
    iWizard->setPos(500, 200);
    iHealer->setPos(420, 450);

    for (Player *p : this->player)
    {
        Warrior *ptrWarrior = dynamic_cast<Warrior *>(p);
        Wizard *ptrWizard = dynamic_cast<Wizard *>(p);
        Healer *ptrHealer = dynamic_cast<Healer *>(p);

        if (!p->isAlive()) continue;

        if (ptrWarrior != nullptr)
            this->gameScene->addItem(iWarrior);

        if (ptrWizard != nullptr)
            this->gameScene->addItem(iWizard);

        if (ptrHealer != nullptr)
            this->gameScene->addItem(iHealer);
    }
}

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
    this->btnFlee->setEnabled(true);
}

void Game::createScene()
{
    QGraphicsScene *gameScene = new QGraphicsScene;
    gameScene->setSceneRect(0, 0, Game::GAME_WIDTH, Game::GAME_HEIGHT);

    //gameScene->addRect(gameScene->sceneRect(), QPen(Qt::DashDotLine));

    this->gameScene = gameScene;
}

void Game::end()
{
    // Disable all buttons...
    this->btnAttackOne->setEnabled(false);
    this->btnAttackTwo->setEnabled(false);
    this->btnBackpack->setEnabled(false);
    this->btnMap->setEnabled(false);

    // ... except exit button
    this->btnFlee->setEnabled(true);
    this->btnFlee->setText("&Quitter le jeu");

    // Get game duration
    QTime endTime = QTime::currentTime();
    int nbMsec = this->startGame.msecsTo(endTime);

    QTime gameTime = QTime(0, 0, 0, 0).addMSecs(nbMsec);

    this->labelInformations->setText(QString("Le jeu est terminé !\n\nTemps de jeu : %1").arg(gameTime.toString()));
    //QMessageBox::information(NULL, "Fin du Jeu", "Le jeu est terminé");
}

void Game::initializePlayer()
{
    this->player.push_back(new Warrior(80, 20, 90, 100));
    this->player.push_back(new Wizard(70, 50, 60, 100, 100));
    this->player.push_back(new Healer(20, 80, 50, 100));
}
