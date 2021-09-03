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

#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QtWidgets>
#include <QButtonGroup>
#include <cmath>
#include <QRandomGenerator>
#include <QString>
#include <QGraphicsScene>
#include "room.h"

#define NBROFROOMS 24
#define MAXWIDTH 200
#define MINWIDTH 100
#define MAXHEIGHT 200
#define MINHEIGHT 100
#define VERTICALSPACING 5
#define HORIZONTALSPACING 5
#define UNKNOWNROOMPATH "../img/mapunknownRoom.png"

/*Map class is an aggregation of room instances, main purpose is to manage the player's movements*/

class Map : public QWidget
{
    Q_OBJECT

public:
    Map(QWidget *parent = nullptr);

    //QWidget *window = new QWidget; //Used only for display when not connected to gameManger
    //QWidget *miniMapWindow = new QWidget; //Used only for display when not connected to gameManger
    QGridLayout *layout = new QGridLayout; //Remove: (window) when connected with gameManager
    QGridLayout *miniMapLayout = new QGridLayout; //Remove: (window) when connected with gameManager
    QGraphicsScene *mapScene;

    QGraphicsScene *getScene();

    int getActiveId() const;
    /**
     * @brief Is called when Torch item is used
     */
    void revealMap();
    Room getActive();
    QButtonGroup *getButtonGroup() const;

    QGridLayout *getMiniMap() const;
    QGridLayout *getMap() const;

    ~Map();

    /**
     * @brief Checks distance with another room
     * @param otherRoom index
     * @return true if distance with a room == 1
     */
    bool checkDist(int);

    Room rooms[NBROFROOMS];
    static bool torchUsed;
protected:

    //Index of the active room
    int activeRoom = 0;
    //Array receiving generated rooms
    //ButtonGroup used to know which button is pushed, the button's id is the same as it's index in the rooms array
    QButtonGroup *roomsBtnGroup = new QButtonGroup;
    //Buttons used for the miniMap display
    QPushButton *topMini = new QPushButton;
    QPushButton *leftMini = new QPushButton;
    QPushButton *rightMini = new QPushButton;
    QPushButton *bottomMini = new QPushButton;
    QPushButton *activeMini = new QPushButton;

    /**
     * @brief sets new active room, changes buttons stylesheet
     */
    void changeActive(int);
    /**
     * @brief Used to check x distance for the miniMap display
     * @param otherRoom index
     */
    int checkDistX(int);
    /**
     * @brief Used to check y distance for the miniMap display
     * @param otherRoom index
     */
    int checkDistY(int);

    /**
     * @brief Generates room in 4x6 disposition, directly adds them to rooms array, ButtonGroup and layout
     */
    void createRooms();
    void createScene(int, int);
    /**
     * @brief Connects the idClicked signal from ButtonGroup to move() function
     */
    void connectRooms();
    void generateMiniMap();
    void generateRoomType();
    /**
     * @brief Used to move player if distance with a room is == 1
     * @param clickedRoomid
     */
    void move(int);
    /**
     * @brief Returns distance between two rooms
     */
    int getDist(int);

    /**
     * @brief Used when changing active room to show adjacent rooms
     */
    void revealTile();
    /**
     * @brief Called at each movement to update the miniMap
     */
    void updateMiniMap(); 

};
#endif // MAP_H
