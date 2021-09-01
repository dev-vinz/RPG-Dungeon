#include "../include/battle.h"

Battle::Battle(std::deque<Player *> *_player, Opponent *_opponent, QWidget *_parent) : QWidget(_parent)
{
    this->player = _player;
    this->opponent = _opponent;
    this->idPlayer = 0;
}

Battle::Turn Battle::getWinner(QPushButton *_btnAOne, QPushButton *_btnATwo, QPushButton *_btnBackpack, QPushButton *_btnFlee)
{
    this->turn = Battle::Turn::PlayerTurn;
    this->isBattle = true;

    this->btnAttackOne = _btnAOne;
    this->btnAttackTwo = _btnATwo;
    this->btnBackpack = _btnBackpack;
    this->btnFlee = _btnFlee;

    QButtonGroup *globalButtons = new QButtonGroup;
    globalButtons->addButton(_btnAOne, 1);
    globalButtons->addButton(_btnATwo, 2);
    globalButtons->addButton(_btnBackpack, 3);
    globalButtons->addButton(_btnFlee, 4);

    QObject::connect(globalButtons, &QButtonGroup::idClicked, this, &Battle::doAction);

    while (this->isBattle)
    {
        this->nextTurn();
    }

    return this->winner;
}

void Battle::doAction(int _id)
{
    Battle::ButtonType btnType = (Battle::ButtonType)_id;
    // Get current player
    Player *currentPlayer = this->player->at(this->idPlayer % this->player->size());
    this->idPlayer++;

    QMessageBox::information(NULL, "Information", QString("Current player : %1").arg(currentPlayer->getName()));
    QMessageBox::information(NULL, "Information", QString("Button clicked : %1").arg(btnType));

    Warrior *ptrWarrior = dynamic_cast<Warrior *>(currentPlayer);
    Wizard *ptrWizard = dynamic_cast<Wizard *>(currentPlayer);
    Healer *ptrHealer = dynamic_cast<Healer *>(currentPlayer);

    /**
     *  NAME : Warrior
     *  Attack 1 : Ally
     *  Attack 2 : Ennemy
     */
    if (ptrWarrior != nullptr)
    {
        Character *target;
        Action action;

        switch (btnType)
        {
        case Battle::ButtonType::AttackOneType:
            target = this->chooseAlly();
            action = Action::attack1;
            ptrWarrior->interaction(target, action);
            break;
        case Battle::ButtonType::AttackTwoType:
            target = this->opponent;
            action = Action::attack2;
            ptrWarrior->interaction(target, action);
            break;
        case Battle::ButtonType::BackpackType:
        case Battle::ButtonType::FleeType:
            break;
        default:
            exit(-1);
        }
    }

    /**
     * NAME : Wizard
     * Attack 1 : Ennemy
     * Attack 2: Ennemy
     */
    if (ptrWizard != nullptr)
    {
        Character *target;
        Action action;

        switch (btnType)
        {
        case Battle::ButtonType::AttackOneType:
            target = this->opponent;
            action = Action::attack1;
            ptrWizard->interaction(target, action);
            break;
        case Battle::ButtonType::AttackTwoType:
            target = this->opponent;
            action = Action::attack2;
            ptrWizard->interaction(target, action);
            break;
        case Battle::ButtonType::BackpackType:
        case Battle::ButtonType::FleeType:
            break;
        default:
            exit(-1);
        }
    }

    /**
     * NAME : Healer
     * Attack 1 : Ally
     * Attack 2 : Ennemy
     */
    if (ptrHealer != nullptr)
    {
        Character *target;
        Action action;

        switch (btnType)
        {
        case Battle::ButtonType::AttackOneType:
            target = this->chooseAlly();
            action = Action::attack1;
            ptrHealer->interaction(target, action);
            break;
        case Battle::ButtonType::AttackTwoType:
            target = this->opponent;
            action = Action::attack2;
            ptrHealer->interaction(target, action);
            break;
        case Battle::ButtonType::BackpackType:
        case Battle::ButtonType::FleeType:
            break;
        default:
            exit(-1);
        }
    }

    ptrWarrior = nullptr;
    ptrWizard = nullptr;
    ptrHealer = nullptr;

    this->checkOver();
}

/* * * * * * * * * * * * * * * * *
 * * * * PROTECTED METHODS * * * *
 * * * * * * * * * * * * * * * * */

void Battle::checkOver()
{
    // We actualize alive players
    std::deque<Player *> alivePlayers = std::deque<Player *>();

    while (!this->player->empty())
    {
        Player *p = this->player->front();
        this->player->pop_front();

        if (p->isAlive()) alivePlayers.push_back(p);
    }

    while (!alivePlayers.empty())
    {
        Player *p = alivePlayers.front();
        alivePlayers.pop_front();

        this->player->push_back(p);
    }

    if (this->player->size() == 0)
    {
        this->isBattle = false;
        this->winner = Battle::Turn::OpponentTurn;

        return;
    }

    if (!this->opponent->isAlive())
    {
        this->isBattle = false;
        this->winner = Battle::Turn::PlayerTurn;

        return;
    }
}

Character *Battle::chooseAlly() const
{
    // We choose always the one who has less pv

    int i = 0;
    int iMin = 0;

    for (Player *p : *this->player)
    {
        if (p->getHealth() < this->player->at(iMin)->getHealth())
            iMin = i++;
    }

    return this->player->at(iMin);

}

void Battle::opponentTurn()
{
    // Disable buttons
    this->btnAttackOne->setEnabled(false);
    this->btnAttackTwo->setEnabled(false);
    this->btnBackpack->setEnabled(false);
    this->btnFlee->setEnabled(false);

    // Do a random attack...
    qint32 a = QRandomGenerator::global()->bounded(1, 3);
    Action attack = (Action)(a);

    // ...to a random player
    qint32 pId = QRandomGenerator::global()->bounded(0, (int)this->player->size());
    Player *p = this->player->at(pId);

    this->opponent->interaction(p, attack);

    this->checkOver();
}

void Battle::playerTurn()
{
    // Réactiver les boutons
    this->btnAttackOne->setEnabled(true);
    this->btnAttackTwo->setEnabled(true);
    this->btnBackpack->setEnabled(true);
    this->btnFlee->setEnabled(true);

    QMessageBox::information(NULL, "Information", "Here we go");
    QEventLoop loop;

    QObject::connect(btnAttackOne, &QPushButton::clicked, &loop, &QEventLoop::quit);
    QObject::connect(btnAttackTwo, &QPushButton::clicked, &loop, &QEventLoop::quit);
    QObject::connect(btnBackpack, &QPushButton::clicked, &loop, &QEventLoop::quit);
    QObject::connect(btnFlee, &QPushButton::clicked, &loop, &QEventLoop::quit);

    // Wait for button to be clicked
    loop.exec();

    QMessageBox::information(NULL, "Information", "Thanks for clicking");
}

void Battle::nextTurn()
{
    if (this->turn == Battle::Turn::PlayerTurn)
    {
        this->playerTurn();
        this->turn = Battle::Turn::OpponentTurn;
    }
    else
    {
        this->opponentTurn();
        this->turn = Battle::Turn::PlayerTurn;
    }
}
