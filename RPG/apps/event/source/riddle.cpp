#include "../include/riddle.h"

Riddle::Riddle()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C:\\dev\\HE-ARC\\BA2\\ConceptionLogicielle\\030-Projet\\030-Sources\\RPG\\settings\\database.db");
    //db.setDatabaseName("../../../settings/database.db");

    if (!db.open())
    {
        QMessageBox::information(NULL, "ERROR", "Problème DB");
    }

    QSqlQuery query;
    query.exec("SELECT * FROM riddle WHERE id=1");
    query.next();

    QString question = query.value("question").toString();
    QString optionOne = query.value("option_1").toString();
    QString optionTwo = query.value("option_2").toString();
    QString optionThree = query.value("option_2").toString();
    int answer = query.value("answer").toInt();

    QMessageBox::information(NULL, "Question", question + "\n(1) : " + optionOne + "\n(2) : " + optionTwo + "\n(3) : " + optionThree + "\n\nRéponse : " + QString::number(answer));
}

void Riddle::display()
{
}
