/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 03.09.2021
 * Course : HES d'Été
 */

#ifndef BACKPACK_H
#define BACKPACK_H

#include <QDialog>
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
#include "potion.h"
#include "scroll.h"
#include "torch.h"

class Backpack : public QDialog
{

    Q_OBJECT

    friend class Map;

private:
    std::vector<IObject *> myBackpack;
    std::deque<Player *> *player;
    QLabel *infoLabel;
    QListWidget *listItem;
    QPushButton *btnUse;
    QDialog *window;

    Player *chooseAlly() const;

public:
    Backpack(std::deque<Player *> *_player, QLabel *_infoLabel = nullptr, QWidget *_parent = nullptr);

    void addItem(IObject *_pObject);
    void show();
    void useItem(int _indice);

    QPushButton *getUseButton() const;

protected:
    QHBoxLayout *createButtons();
    QVBoxLayout *createLayout();
    QListWidget *createListItems();

public slots:
    void closeBackpack();
    void useItemButton();
};

#endif // BACKPACK_H
