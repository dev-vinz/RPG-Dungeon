#include "../include/battle.h"

Battle::Battle(std::map<Player *, QLabel *> *_statsLabels, std::deque<Player *> *_player, Opponent *_opponent, QLabel *informations, QWidget *_parent) : QWidget(_parent)
{
    this->player = _player;
    this->opponent = _opponent;
    this->informations = informations;
    this->idPlayer = 0;
    this->statsLabels = _statsLabels;
}

Battle::Turn Battle::getWinner(QPushButton *_btnAOne, QPushButton *_btnATwo)
{
    this->turn = Battle::Turn::PlayerTurn;
    this->isBattle = true;

    this->btnAttackOne = _btnAOne;
    this->btnAttackTwo = _btnATwo;

    QButtonGroup *globalButtons = new QButtonGroup;
    globalButtons->addButton(_btnAOne, 1);
    globalButtons->addButton(_btnATwo, 2);

    QObject::connect(globalButtons, &QButtonGroup::idClicked, this, &Battle::doAction);

    while (this->isBattle)
    {
        ExtensionMethod::UpdateStatsLayout(this->statsLabels);
        QString report = this->nextTurn();
        this->informations->setText(report);
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
        default:
            exit(-1);
        }
    }

    ptrWarrior = nullptr;
    ptrWizard = nullptr;
    ptrHealer = nullptr;

    ExtensionMethod::UpdateStatsLayout(this->statsLabels);
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

        if (p->isAlive()){
            alivePlayers.push_back(p);
        }
        else
        {
            //delete p;
            p = nullptr;
        }
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

QString Battle::opponentTurn()
{
    this->oTurnString = "";

    // Disable buttons
    this->btnAttackOne->setEnabled(false);
    this->btnAttackTwo->setEnabled(false);

    // Do a random attack...
    qint32 a = QRandomGenerator::global()->bounded(1, 3);
    Action attack = (Action)(a);

    // ...to a random player
    qint32 pId = QRandomGenerator::global()->bounded(0, (int)this->player->size());
    Player *p = this->player->at(pId);

    oTurnString.append(QString("%1 utilise l'attaque %2").arg(this->opponent->getName(), QString::number(a)));

    this->opponent->interaction(p, attack);

    ExtensionMethod::UpdateStatsLayout(this->statsLabels);
    this->checkOver();

    return oTurnString;
}

QString Battle::playerTurn()
{
    this->pTurnString = "";

    // Réactiver les boutons
    this->btnAttackOne->setEnabled(true);
    this->btnAttackTwo->setEnabled(true);

    QMessageBox::information(NULL, "Information", "Here we go");
    QEventLoop loop;

    QObject::connect(btnAttackOne, &QPushButton::clicked, &loop, &QEventLoop::quit);
    QObject::connect(btnAttackTwo, &QPushButton::clicked, &loop, &QEventLoop::quit);

    // Wait for button to be clicked
    loop.exec();

    ExtensionMethod::UpdateStatsLayout(this->statsLabels);
    QMessageBox::information(NULL, "Information", "Thanks for clicking");

    return this->pTurnString;
}

QString Battle::nextTurn()
{
    QString report;

    if (this->turn == Battle::Turn::PlayerTurn)
    {
        report = this->playerTurn();
        this->turn = Battle::Turn::OpponentTurn;
    }
    else
    {
        report = this->opponentTurn();
        this->turn = Battle::Turn::PlayerTurn;
        //QThread::sleep(5);
    }

    return report;
}
