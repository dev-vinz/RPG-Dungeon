/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#ifndef BATTLE_H
#define BATTLE_H

#include <deque>
#include <map>

#include <QObject>
#include <QButtonGroup>
#include <QEventLoop>
#include <QMessageBox>
#include <QPushButton>

#include "../../actors/include/ghoul.h"
#include "../../actors/include/healer.h"
#include "../../actors/include/opponent.h"
#include "../../actors/include/player.h"
#include "../../actors/include/skeleton.h"
#include "../../actors/include/warrior.h"
#include "../../actors/include/wizard.h"

#include "../../../settings/ExtensionMethod.h"

class Battle : public QWidget
{
    Q_OBJECT

public:
    enum Turn
    {
      PlayerTurn,
      OpponentTurn
    };

    enum ButtonType
    {
        AttackOneType = 1,
        AttackTwoType = 2,
        BackpackType = 3,
        FleeType = 4
    };

    Battle(std::map<Player *, QLabel *> *_statsLabels, std::deque<Player *> *, Opponent *, QWidget *_parent = nullptr);

    Turn getWinner(QPushButton *, QPushButton *, QPushButton *, QPushButton *);

protected:
    Character *chooseAlly() const;

    void checkOver();
    void nextTurn();
    void opponentTurn();
    void playerTurn();

private:
    bool isBattle;
    std::deque<Player *> *player;
    Opponent *opponent;
    Turn turn;
    Turn winner;

    int idPlayer;

    QPushButton *btnAttackOne;
    QPushButton *btnAttackTwo;
    QPushButton *btnBackpack;
    QPushButton *btnFlee;

    std::map<Player *, QLabel *> *statsLabels;

public slots:
    void doAction(int id);
};

#endif // BATTLE_H