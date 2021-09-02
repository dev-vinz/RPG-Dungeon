#include "../include/gamemanager.h"

GameManager::GameManager(QWidget *_parent) : QWidget(_parent)
{
    this->map = new Map;
    this->game = new Game(this->map);
    this->playerStatLabel = this->game->createStatsLabel();

    connect(this->map->getButtonGroup(), &QButtonGroup::buttonClicked, this, &GameManager::updateLayout);
    connect(this, &GameManager::newActionRPG, this, &GameManager::refreshGame);
}

void GameManager::display()
{
    this->globalGrid = new QGridLayout(this);

    QGridLayout *actionButtons = this->createActionButtons();
    QGridLayout *characterStatistics = this->createCharacterStatistics();
    //QGridLayout *informations = this->createInformationsBox();
    //QGridLayout *legends = this->createLegends();
    QVBoxLayout *miniMap = this->createMiniMap();

    QLabel *gameInformations = new QLabel("ACTIONS JEU");
    gameInformations->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    this->globalView = new QGraphicsView;
    QGraphicsScene *mainScene = this->game->getScene();

    globalView->setScene(mainScene);
    globalView->fitInView(mainScene->sceneRect());

    globalGrid->addWidget(globalView, 0, 0, 5, 4);
    globalGrid->addLayout(actionButtons, 5, 0, 1, 2);
    globalGrid->addLayout(characterStatistics, 0, 4, 3, 1);
    //globalGrid->addLayout(informations, 5, 0, 1, 4);
    //globalGrid->addLayout(legends, 4, 2, 1, 2);
    globalGrid->addWidget(gameInformations, 5, 2, 2, 2);
    globalGrid->addLayout(miniMap, 4, 4, 2, 1);

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

void GameManager::updateLayout()
{
    this->updateStatistics();

    QGraphicsScene *scene;

    if (this->currentDisplay == GameManager::ActualDisplay::MapDisplay)
    {
        scene = this->game->getScene();
        this->currentDisplay = GameManager::ActualDisplay::GameDisplay;
    }
    else
    {
        scene = this->map->getScene();
        scene->addRect(scene->sceneRect(), Qt::DashDotLine);
        this->currentDisplay = GameManager::ActualDisplay::MapDisplay;
        this->game->btnMap->setEnabled(false);
    }

    this->globalView->setScene(scene);
    this->globalView->fitInView(this->globalView->sceneRect());

    this->globalGrid->update();
}

/* * * * * * * * * * * * * * * *
 * * * * PRIVATE METHODS * * * *
 * * * * * * * * * * * * * * * */

void GameManager::updateStatistics()
{
    // We update the statistics shown

    for (auto item : *this->playerStatLabel)
    {
        Player *p = item.first;
        QLabel *l = item.second;

        if (p->isAlive())
        {
            l->setText(p->showStat());
        }
        else
        {
            l->setText(p->getName() + "\nRIP");
        }
    }
}

/**
 * @brief Creates the layout for the action buttons
 * @return The layout
 */
QGridLayout *GameManager::createActionButtons()
{
    QGridLayout *actionButtons = new QGridLayout;
    actionButtons->addWidget(this->game->btnAttackOne, 0, 0);
    actionButtons->addWidget(this->game->btnAttackTwo, 0, 1);
    actionButtons->addWidget(this->game->btnBackpack, 1, 0);
    actionButtons->addWidget(this->game->btnFlee, 1, 1);

    this->game->btnAttackOne->setFixedHeight(50);
    this->game->btnAttackTwo->setFixedHeight(50);
    this->game->btnBackpack->setFixedHeight(50);
    this->game->btnFlee->setFixedHeight(50);

    return actionButtons;
}

/**
 * @brief Creates the layout for the characters' statistics
 * @return The layout
 */
QGridLayout *GameManager::createCharacterStatistics()
{
    int row = 0;

    QGridLayout *statistics = new QGridLayout;

    for (auto item : *this->playerStatLabel)
    {
        Player *p = item.first;
        QLabel *l = item.second;

        QLabel *iconLabel = new QLabel;
        QPixmap pix(QString("../img/characters/sprite_%1.png").arg(p->getName().toLower()));
        pix = pix.scaled(50, 50, Qt::KeepAspectRatioByExpanding);
        iconLabel->setPixmap(pix);

        l->setText(p->showStat());

        QVBoxLayout *box = new QVBoxLayout;
        box->addWidget(iconLabel, Qt::AlignHCenter);
        box->addWidget(l, Qt::AlignHCenter);

        statistics->addLayout(box, row, 0, Qt::AlignHCenter);

        row++;
    }

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
QVBoxLayout *GameManager::createMiniMap()
{
    QVBoxLayout *miniMap = new QVBoxLayout;

    QLabel *mapTitle = new QLabel("Mini Map");
    QGridLayout *map = this->map->getMiniMap();

    connect(this->game->btnMap, &QPushButton::clicked, this, &GameManager::updateLayout);

    mapTitle->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    mapTitle->setStyleSheet("font: bold 20px; text-decoration: underline");

    this->game->btnMap->setFixedWidth(225);
    this->game->btnMap->setFixedHeight(50);

    miniMap->addWidget(mapTitle, Qt::AlignHCenter);
    miniMap->addLayout(map, Qt::AlignHCenter);
    miniMap->addWidget(this->game->btnMap, Qt::AlignHCenter);

    return miniMap;
}
