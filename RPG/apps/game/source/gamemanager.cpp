#include "../include/gamemanager.h"

GameManager::GameManager(QWidget *_parent) : QWidget(_parent)
{
    connect(this, &GameManager::newActionRPG, this, &GameManager::refreshGame);
}

void GameManager::display()
{
    // Créer une scène ici, et ajouter le game (item)
    QGridLayout *globalGrid = new QGridLayout(this);
    this->map = new Map;
    this->game = new Game(this->map);

    QGridLayout *actionButtons = this->createActionButtons();
    QGridLayout *characterStatistics = this->createCharacterStatistics();
    QGridLayout *informations = this->createInformationsBox();
    QGridLayout *legends = this->createLegends();
    QGridLayout *miniMap = this->createMiniMap();

    // Create the global layout
    if (this->currentDisplay == GameManager::ActualDisplay::GameDisplay)
        globalGrid->addWidget(this->game, 0, 0, 4, 4);
    else
        globalGrid->addLayout(this->map->getMap(), 0, 0, 4, 4);

    globalGrid->addLayout(actionButtons, 4, 0, 1, 2);
    globalGrid->addLayout(characterStatistics, 0, 4, 3, 1);
    globalGrid->addLayout(informations, 5, 0, 1, 4);
    globalGrid->addLayout(legends, 4, 2, 1, 2);
    globalGrid->addLayout(miniMap, 4, 4, 1, 1);

    this->setWindowTitle("RPG - HE-Arc");
    this->setLayout(globalGrid);
}

void GameManager::startGame()
{
    this->game->start();
}

void GameManager::mousePressEvent(QMouseEvent *_event)
{
    if (_event->button() == Qt::LeftButton)
        emit GameManager::newActionRPG();
}

void GameManager::refreshGame()
{
    this->game->updateScene();
}

/* * * * * * * * * * * * * * * *
 * * * * PRIVATE METHODS * * * *
 * * * * * * * * * * * * * * * */

/**
 * @brief Creates the layout for the action buttons
 * @return The layout
 */
QGridLayout *GameManager::createActionButtons()
{
    QPushButton *btnOne = new QPushButton("Attaque &1");
    QPushButton *btnTwo = new QPushButton("Attaque &2");
    QPushButton *btnThree = new QPushButton("&Sac à Dos");
    QPushButton *btnFour = new QPushButton("&Fuir");

    // TODO : Connect to player methods

    QGridLayout *actionButtons = new QGridLayout;
    actionButtons->addWidget(btnOne, 0, 0);
    actionButtons->addWidget(btnTwo, 0, 1);
    actionButtons->addWidget(btnThree, 1, 0);
    actionButtons->addWidget(btnFour, 1, 1);

    return actionButtons;
}

/**
 * @brief Creates the layout for the characters' statistics
 * @return The layout
 */
QGridLayout *GameManager::createCharacterStatistics()
{
    // TODO : Add QGraphicsView *Player::getStatistics();
    // TEMP : Labels
    QLabel *mageStatistics = new QLabel("Stats Mage");
    QLabel *healerStatistics = new QLabel("Stats Healer");
    QLabel *warriorStatistics = new QLabel("Stats Warrior");

    QGridLayout *statistics = new QGridLayout;
    statistics->addWidget(mageStatistics, 0, 0, Qt::AlignCenter);
    statistics->addWidget(healerStatistics, 1, 0, Qt::AlignCenter);
    statistics->addWidget(warriorStatistics, 2, 0, Qt::AlignCenter);

    return statistics;
}

/**
 * @brief Creates the layout for informations box
 * @return The layout
 */
QGridLayout *GameManager::createInformationsBox()
{
    QPushButton *btnQuit = new QPushButton("&Quitter Jeu");
    QLabel *informationBox = new QLabel("Box d'informations et de dialogue");

    QObject::connect(btnQuit, &QPushButton::clicked, this, &QApplication::quit);

    QGridLayout *informations = new QGridLayout;
    informations->addWidget(btnQuit, 0, 0, 1, 1);
    informations->addWidget(informationBox, 0, 1, 1, 6);

    return informations;
}

/**
 * @brief Creates the layout for the game's legends
 * @return The layout
 */
QGridLayout *GameManager::createLegends()
{
    QLabel *labelLegend = new QLabel("Légendes :");
    QLabel *emptyLabel = new QLabel;
    QLabel *entryLabel = new QLabel("( E ) : Entrée");
    QLabel *exitLabel = new QLabel("( S ) : Sortie");
    QLabel *eventLabel = new QLabel("( ? ) : Évènement");
    QLabel *battleLabel = new QLabel("( ! ) : Combat");

    QGridLayout *legends = new QGridLayout;
    legends->addWidget(labelLegend, 0, 0, Qt::AlignRight);
    legends->addWidget(emptyLabel, 0, 1);
    legends->addWidget(entryLabel, 0, 2);
    legends->addWidget(exitLabel, 0, 3);
    legends->addWidget(eventLabel, 0, 4);
    legends->addWidget(battleLabel, 0, 5);

    return legends;
}

/**
 * @brief Create the layout for the mini map
 * @return The layout
 */
QGridLayout *GameManager::createMiniMap()
{
    QLabel *mapTitle = new QLabel("Mini Map");
    QGridLayout *miniMap = this->map->getMiniMap();

    miniMap->addWidget(mapTitle, 0, 0, Qt::AlignHCenter);
    miniMap->addLayout(miniMap, 1, 0);

    return miniMap;
}
