/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#ifndef RIDDLE_H
#define RIDDLE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

class Riddle
{
public:
    Riddle();

    void display();
};

#endif // RIDDLE_H
