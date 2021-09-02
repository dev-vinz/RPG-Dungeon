#include "../include/loot.h"

IObject *Loot::getTreasure() const
{
    qint32 id = QRandomGenerator::global()->bounded(1, 10);

    IObject *item;

    switch (id)
    {
    case 1:
        // Potion Heal
    case 2:
        // Potion Heal
    case 3:
        // Potion Heal
    case 4:
        // Potion Heal
    case 5:
        // Potion Heal
    case 6:
        // Potion Heal
    case 7:
        // Potion Heal
    case 8:
        // Potion Heal
        item = this->getHealPotion();
        break;
    case 9:
        // Torch
        item = this->getTorch();
        break;
    default:
        exit(-1);
    }

    return item;
}

/* * * * * * * * * * * * * * * *
 * * * * PRIVATE METHODS * * * *
 * * * * * * * * * * * * * * * */

IObject *Loot::getDamageScroll() const
{
    qint32 power = QRandomGenerator::global()->bounded(1, 11);
    return new Scroll(power);
}

IObject *Loot::getHealPotion() const
{
    qint32 power = QRandomGenerator::global()->bounded(1, 11);
    return new Potion(power);
}

IObject *Loot::getTorch() const
{
    return new Torch(0);
}
