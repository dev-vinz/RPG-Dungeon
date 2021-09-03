#include "../include/eventmanager.h"

EventManager::EventManager(std::map<Player *, QLabel *> *_statsLabels, QLabel *_gameLabel) : statsLabels(_statsLabels), gameLabel(_gameLabel)
{
}

bool EventManager::battleEvent(std::deque<Player *> *_player, Opponent *_opponent, QPushButton *_btnAOne, QPushButton *_btnATwo, QPushButton *_btnBackpack, QPushButton *_btnFlee) const
{
    Battle battle(this->statsLabels, _player, _opponent, this->gameLabel);

    Battle::Turn winner = battle.getWinner(_btnAOne, _btnATwo, _btnBackpack, _btnFlee);

    return winner == Battle::Turn::PlayerTurn;
}

IObject *EventManager::lootEvent() const
{
    Loot loot;

    IObject *treasure = loot.getTreasure();

    //QMessageBox::information(NULL, "Loot Récupéré", QString("Bravo, vous avez récupéré : %1").arg(treasure->getName()));
    this->gameLabel->setText(QString("Trésor Trouvé !\n\nBravo, vous avez récupéré une %1.\nDescription : %2").arg(treasure->show(), treasure->getDescription()));

    return treasure;
}

void EventManager::riddleEvent(std::deque<Player *> *_player) const
{
    Riddle riddle;

    riddle.display();
    bool isCorrect = riddle.waitForAnswer();

    if (isCorrect)
    {
        //QMessageBox::information(NULL, "Énigme", "Bravo, vous avez trouvé la bonne réponse !");
        this->gameLabel->setText("Bravo, vous avez trouvé la bonne réponse !");
        return;
    }

    std::vector<QString> pInformation = std::vector<QString>();

    for (Player *p : *_player)
    {
        double ratio = 10.0 / 100.0;
        bool hasDodged = p->updateHealth(-(ratio * p->getHealth()));

        if (hasDodged)
            pInformation.push_back(QString("%1 a esquivé").arg(p->getName()));
    }

    ExtensionMethod::UpdateStatsLayout(this->statsLabels);

    QString msg = "Oups, mauvaise réponse... certains personnages ont perdu 10% de leurs points de vie restants.\n";
    QString additionalMsg = ExtensionMethod::Join(pInformation, "\n");

    msg.append(additionalMsg);

    this->gameLabel->setText(msg);
}
