QT       += core gui \
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ".\RPG\main.cpp" \
    ".\RPG\apps\map\source\map.cpp" \
    ".\RPG\apps\map\source\room.cpp" \
    ".\RPG\apps\game\source\game.cpp" \
    ".\RPG\apps\game\source\gamemanager.cpp" \
    ".\RPG\apps\event\source\eventmanager.cpp" \
    ".\RPG\apps\event\source\battle.cpp" \
    ".\RPG\apps\event\source\loot.cpp" \
    ".\RPG\apps\event\source\riddle.cpp"


HEADERS += \
    ".\RPG\apps\map\include\map.h" \
    ".\RPG\apps\map\include\room.h" \
    ".\RPG\apps\game\include\game.h" \
    ".\RPG\apps\game\include\gamemanager.h" \
    ".\RPG\apps\event\include\eventmanager.h" \
    ".\RPG\apps\event\include\battle.h" \
    ".\RPG\apps\event\include\loot.h" \
    ".\RPG\apps\event\include\riddle.h"


FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
