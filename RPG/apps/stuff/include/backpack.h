/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */
#ifndef BACKPACK_H
#define BACKPACK_H

#include <QHBoxLayout>
#include <QGridLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include <deque>
#include <vector>

#include "../../actors/include/player.h"
#include "../../map/include/map.h"

#include "iobject.h"

class Backpack : public QWidget
{

    Q_OBJECT

    friend class Map;

private:
    std::vector<IObject *> myBackpack;
    std::deque<Player *> *player;
    QLabel *infoLabel;
    QListWidget *listItem;
    QPushButton *btnUse;
    QWidget *window;

    Player *chooseAlly() const;

public:
    Backpack(std::deque<Player *> *_player, QLabel *_infoLabel = nullptr, QWidget *_parent = nullptr);

    void addItem(IObject* _pObject);
    QPushButton *getUseButton() const;
    void useItem(int _indice);
    void show();

protected:
    QHBoxLayout *createButtons();
    QVBoxLayout *createLayout();
    QListWidget *createListItems();

public slots:
    void closeBackpack();
    void useItemButton();
};

#endif // BACKPACK_H
