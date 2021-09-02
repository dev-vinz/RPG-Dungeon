/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#include <QApplication>

#include "RPG/apps/game/include/gamemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameManager gManager;
    /*
    auto f = QGuiApplication::primaryScreen()->geometry();
    qDebug() << f.width() << " " << f.height();*/

    //gManager.showFullScreen();
    gManager.showMaximized();
    gManager.display();
    gManager.startGame();

    return a.exec();
}
