/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 * Games assets taken from:     https://0x72.itch.io/dungeontileset-ii?download  Artist: 0x72
 *                              https://pixel-poem.itch.io/dungeon-assetpuck    Artist: Pixel_Poem
 *                              https://ohnoponogames.itch.io/retro-cloud-tileset   Artist: ohnoponogames
 *                              https://darkpixel-kronovi.itch.io/mecha-golem-free Artist: Kronovi
 */

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
