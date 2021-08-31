QT       += core gui \
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ".\RPG\apps\actors\source\character.cpp" \
    ".\RPG\apps\actors\source\ghoul.cpp" \
    ".\RPG\apps\actors\source\healer.cpp" \
    ".\RPG\apps\actors\source\opponent.cpp" \
    ".\RPG\apps\actors\source\player.cpp" \
    ".\RPG\apps\actors\source\skeleton.cpp" \
    ".\RPG\apps\actors\source\warrior.cpp" \
    ".\RPG\apps\actors\source\wizard.cpp" \
    \
    ".\RPG\apps\event\source\battle.cpp" \
    ".\RPG\apps\event\source\eventmanager.cpp" \
    ".\RPG\apps\event\source\loot.cpp" \
    ".\RPG\apps\event\source\riddle.cpp" \
    \
    ".\RPG\apps\game\source\game.cpp" \
    ".\RPG\apps\game\source\gamemanager.cpp" \
    \
    ".\RPG\apps\map\source\map.cpp" \
    ".\RPG\apps\map\source\room.cpp" \
    \
    ".\RPG\apps\stuff\source\backpack.cpp" \
    ".\RPG\apps\stuff\source\iobject.cpp" \
    ".\RPG\apps\stuff\source\potion.cpp" \
    ".\RPG\apps\stuff\source\scroll.cpp" \
    ".\RPG\apps\stuff\source\torch.cpp" \
    \
    ".\RPG\main.cpp" \


HEADERS += \
    ".\RPG\apps\actors\include\character.h" \
    ".\RPG\apps\actors\include\ghoul.h" \
    ".\RPG\apps\actors\include\healer.h" \
    ".\RPG\apps\actors\include\opponent.h" \
    ".\RPG\apps\actors\include\player.h" \
    ".\RPG\apps\actors\include\skeleton.h" \
    ".\RPG\apps\actors\include\warrior.h" \
    ".\RPG\apps\actors\include\wizard.h" \
    \
    ".\RPG\apps\event\include\battle.h" \
    ".\RPG\apps\event\include\eventmanager.h" \
    ".\RPG\apps\event\include\loot.h" \
    ".\RPG\apps\event\include\riddle.h" \
    \
    ".\RPG\apps\game\include\game.h" \
    ".\RPG\apps\game\include\gamemanager.h" \
    \
    ".\RPG\apps\map\include\map.h" \
    ".\RPG\apps\map\include\room.h" \
    \
    ".\RPG\apps\stuff\include\backpack.h" \
    ".\RPG\apps\stuff\include\iobject.h" \
    ".\RPG\apps\stuff\include\potion.h" \
    ".\RPG\apps\stuff\include\scroll.h" \
    ".\RPG\apps\stuff\include\torch.h" \
    \
    ".\RPG\settings\settings.h"


FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
