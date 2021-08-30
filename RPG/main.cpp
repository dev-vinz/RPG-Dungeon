#include <QApplication>

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
