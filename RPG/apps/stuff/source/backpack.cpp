#include "..\include\backpack.h"

#include "../include/scroll.h"
#include "../include/potion.h"
#include "../include/torch.h"

Backpack::Backpack(std::deque<Player *> *_player, QWidget *_parent) : QWidget(_parent), player(_player)
{
    QVBoxLayout *layout = this->createLayout();

    this->window = new QWidget;
    this->window->setWindowFlags(Qt::WindowTitleHint);
    this->window->setWindowTitle("Sac à Dos");
    this->window->setLayout(layout);

    this->addItem(new Scroll(1));
    this->addItem(new Scroll(2));
    this->addItem(new Scroll(3));
    this->addItem(new Potion(4));
    this->addItem(new Potion(5));
    this->addItem(new Potion(6));
    this->addItem(new Torch(7));
    this->addItem(new Torch(8));
    this->addItem(new Torch(9));
}

void Backpack::addItem(IObject* _pObject)
{
    myBackpack.push_back(_pObject);

    QPixmap px(QString("../img/stuff/sprite_%1.png").arg(_pObject->getName().toLower()));
    QListWidgetItem *it = new QListWidgetItem(_pObject->show(), this->listItem);

    it->setIcon(px);
}

void Backpack::useItem(int _indice)
{
    // We must find the item we want and pop it from pack

    IObject *object = this->myBackpack.at(_indice);

    Potion *ptrPotion = dynamic_cast<Potion *>(object);
    Scroll *ptrScroll = dynamic_cast<Scroll *>(object);
    Torch *ptrTorch = dynamic_cast<Torch *>(object);

    // USE POTION
    if (ptrPotion != nullptr)
    {
        Player *p = this->chooseAlly();
        this->myBackpack.at(_indice)->use(p);
    }

    // USE SCROLL
    if (ptrScroll != nullptr)
    {
        // NOT IMPLEMENTED
    }

    // USE TORCH
    if (ptrTorch != nullptr)
    {
        Map::torchUsed = true;
    }

    //myBackpack[_indice]->use(_character);

    myBackpack.erase(myBackpack.begin() + _indice);

    QListWidgetItem *it = this->listItem->takeItem(_indice);
    delete it;
}

void Backpack::show()
{
    btnUse->setEnabled(this->myBackpack.size() > 0);

    QListWidgetItem *firstIt = this->listItem->item(0);

    if (firstIt != nullptr)
        this->listItem->setCurrentItem(firstIt);

    this->window->show();
}

/* * * * * * * * * * * * * * * * *
 * * * * PROTECTED METHODS * * * *
 * * * * * * * * * * * * * * * * */

QHBoxLayout *Backpack::createButtons()
{
    QHBoxLayout *box = new QHBoxLayout;

    QPushButton *btnUse = new QPushButton("&Utiliser");
    QPushButton *btnClose = new QPushButton("&Fermer");

    this->btnUse = btnUse;

    QObject::connect(btnUse, &QPushButton::clicked, this, &Backpack::useItemButton);
    QObject::connect(btnClose, &QPushButton::clicked, this, &Backpack::closeBackpack);

    box->addWidget(btnUse);
    box->addWidget(btnClose);

    return box;
}

QVBoxLayout *Backpack::createLayout()
{
    QVBoxLayout *backpackGrid = new QVBoxLayout;

    backpackGrid->addWidget(this->createListItems());
    backpackGrid->addLayout(this->createButtons());

    return backpackGrid;
}

QListWidget *Backpack::createListItems()
{
    this->listItem = new QListWidget;
    listItem->setIconSize(QSize(50, 50));

    return listItem;
}

/* * * * * * * * * * * * * * * *
 * * * * PRIVATE METHODS * * * *
 * * * * * * * * * * * * * * * */

Player *Backpack::chooseAlly() const
{
    // We choose always the one who has less pv

    int i = 0;
    int iMin = 0;

    for (Player *p : *this->player)
    {
        if (p->getHealth() < this->player->at(iMin)->getHealth())
            iMin = i++;
    }

    return this->player->at(iMin);

}

/* * * * * * * * * * * * * * *
 * * * * PUBLICS SLOTS * * * *
 * * * * * * * * * * * * * * */

void Backpack::closeBackpack()
{
    this->window->close();
}

void Backpack::useItemButton()
{
    int index = this->listItem->currentRow();
    IObject *item = this->myBackpack.at(index);
    this->useItem(index);

    qDebug() << "Utilisation de : " << item->show();

    if (this->listItem->count() == 0)
    {
        this->btnUse->setEnabled(false);
    }
    else
    {
        QListWidgetItem *firstIt = this->listItem->item(0);
        firstIt->setSelected(true);
    }

}
