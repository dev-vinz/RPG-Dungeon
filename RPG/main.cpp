#include <QApplication>

#include "gamemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameManager gManager;

    gManager.showFullScreen();
    gManager.display();

    return a.exec();
}
