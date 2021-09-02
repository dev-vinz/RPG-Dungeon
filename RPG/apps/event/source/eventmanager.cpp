#include "../include/eventmanager.h"

EventManager::EventManager(std::map<Player *, QLabel *> *_statsLabels, QLabel *_gameLabel) : statsLabels(_statsLabels), gameLabel(_gameLabel)
{
}

bool EventManager::battleEvent(std::deque<Player *> *_player, Opponent *_opponent, QPushButton *_btnAOne, QPushButton *_btnATwo) const
{
    Battle battle(this->statsLabels, _player, _opponent, this->gameLabel);

    Battle::Turn winner = battle.getWinner(_btnAOne, _btnATwo);

    return winner == Battle::Turn::PlayerTurn;
}

IObject *EventManager::lootEvent() const
{
    Loot loot;

    IObject *treasure = loot.getTreasure();

    QMessageBox::information(NULL, "Loot Récupéré", QString("Bravo, vous avez récupéré : %1").arg(treasure->getName()));

    return treasure;
}

void EventManager::riddleEvent(std::deque<Player *> *_player) const
{
    Riddle riddle;

    riddle.display();
    bool isCorrect = riddle.waitForAnswer();

    if (isCorrect)
    {
        QMessageBox::information(NULL, "Énigme", "Bravo, vous avez trouvé la bonne réponse !");
        return;
    }

    std::vector<QString> pInformation = std::vector<QString>();

    for (Player *p : *_player)
    {
        double ratio = 10.0 / 100.0;
        p->updateHealth(-(ratio * p->getHealth()));

        pInformation.push_back(QString("%1 : %2 HP").arg(p->getName(), QString::number(p->getHealth())));
    }

    ExtensionMethod::UpdateStatsLayout(this->statsLabels);

    QString msgStatus = ExtensionMethod::Join(pInformation, "\n");
    QString msg = QString("Oups, mauvaise réponse... chacun de vos personnages a perdu 10% de ses points de vie restants.\n\nStatut des Personnages\n\n%1").arg(msgStatus);
    QMessageBox::critical(NULL, "Énigme", msg);
}
