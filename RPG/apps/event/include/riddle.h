/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef RIDDLE_H
#define RIDDLE_H

#include <map>

#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QEventLoop>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QRandomGenerator>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include "../../actors/include/player.h"

class Riddle : public QDialog
{
    Q_OBJECT

private:
    QPushButton *optionOne;
    QPushButton *optionTwo;
    QPushButton *optionThree;
    QSqlDatabase database;
    QDialog *window;

    struct Query
    {
        QString question;
        QString optionOne;
        QString optionTwo;
        QString optionThree;
        int answer;
    };

    bool pAnswer = false;
    Query query;

    bool RELEASE_MODE = true;

public:
    Riddle(QWidget *_parent = nullptr);

    void display();
    bool waitForAnswer();

protected:
    void checkAnswer(int _idButton);
    void connectToDatabase();
    QGridLayout *createLayout();
    void disconnectFromDatabase();
    Query getRandomQuery();
    int getTableLength() const;
};

#endif // RIDDLE_H
