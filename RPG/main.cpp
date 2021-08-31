#include <iostream>
#include <algorithm>
#include <vector>

#include ".\RPG\settings\settings.h"

#include ".\apps\actors\include\character.h"

#include ".\apps\actors\include\player.h"
#include ".\apps\actors\include\warrior.h"
#include ".\apps\actors\include\healer.h"
#include ".\apps\actors\include\wizard.h"

#include ".\apps\actors\include\oponnent.h"
#include ".\apps\actors\include\skeleton.h"
#include ".\apps\actors\include\ghoul.h"

#include ".\apps\stuff\include\iobject.h"
#include ".\apps\stuff\include\potion.h"
#include ".\apps\stuff\include\scroll.h"
#include ".\apps\stuff\include\torch.h"

#include ".\apps\game\include\battle.h"

#include ".\apps\game\include\graph.h"
using namespace std;
#include <QApplication>
int main(int argc, char *argv[])
{
    cout << "Hi" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    list<Character *> myParty;
    Warrior *warrior = new Warrior(20,20,20,MAX_HEALTH);
    Wizard *wizard = new Wizard(10,20,20,MAX_HEALTH,MAX_MANA);
    Healer *healer = new Healer(10,20,20,MAX_HEALTH);

    //Potion *potion = new Potion(10);
    //warrior->playerBackpack.addItem(potion);

    Ghoul *ghoul = new Ghoul(10,10,10,10);
    Skeleton *skeleton = new Skeleton(10,10,10,10);


    myParty.push_back(warrior);
    myParty.push_front(wizard);
    myParty.push_back(healer);

    Battle myBattle;
    myBattle.startBattle(myParty,ghoul);

    ghoul->show();
    skeleton->show();

    QApplication a(argc, argv);
    Graph myGraph;
    myGraph.show();
    return a.exec();

    return 0;
}
