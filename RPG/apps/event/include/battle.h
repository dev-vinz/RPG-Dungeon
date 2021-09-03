/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
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
#include <QTest>
#include <QThread>

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
        AttackTwoType = 2
    };

    Battle(std::map<Player *, QLabel *> *_statsLabels, std::deque<Player *> *, Opponent *, QLabel *informations, QWidget *_parent = nullptr);

    Turn getWinner(QPushButton *, QPushButton *, QPushButton *_btnBackpack, QPushButton *_btnFlee);

protected:
    Character *chooseAlly() const;

    void checkOver();
    QString nextTurn();
    QString opponentTurn();
    QString playerTurn();

private:
    bool isBattle;
    std::deque<Player *> *player;
    Opponent *opponent;
    Turn turn;
    Turn winner;

    int idPlayer;

    QLabel *informations;
    QString pTurnString;
    QString oTurnString;

    QPushButton *btnAttackOne;
    QPushButton *btnAttackTwo;
    QPushButton *btnBackpack;
    QPushButton *btnFlee;

    std::map<Player *, QLabel *> *statsLabels;

public slots:
    void doAction(int id);
    void stopBattle();
};

#endif // BATTLE_H
