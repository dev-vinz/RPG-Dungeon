/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#include <QApplication>
#include "apps\map\include\map.h"
#include "apps\map\include\room.h"

#include "RPG/apps/game/include/gamemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameManager gManager;

    gManager.showFullScreen();
    gManager.display();
    gManager.startGame();

    return a.exec();
}
