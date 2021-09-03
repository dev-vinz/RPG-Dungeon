/**
 * RPG Project
 * Authors : Vincent JEANNIN, Benjamin MOUCHET, Guillaume MOUCHET
 * Date : 30.08.2021
 * Course : HES d'Été
 */

#ifndef LOOT_H
#define LOOT_H

#include <QRandomGenerator>

#include "../../stuff/include/iobject.h"
#include "../../stuff/include/potion.h"
#include "../../stuff/include/scroll.h"
#include "../../stuff/include/torch.h"

class Loot
{
public:
    Loot() = default;

    IObject *getTreasure() const;

private:
    IObject *getDamageScroll() const;
    IObject *getHealPotion() const;
    IObject *getTorch() const;
};

#endif // LOOT_H
