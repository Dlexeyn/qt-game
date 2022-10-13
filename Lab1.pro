QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game/Controller.cpp \
    game/Game.cpp \
    graphics/BoxView.cpp \
    graphics/CellView.cpp \
    graphics/DialogSize.cpp \
    graphics/FieldScene.cpp \
    graphics/PlayerView.cpp \
    graphics/dialoglevel.cpp \
    main.cpp \
    graphics/basewindow.cpp \
    map/Box.cpp \
    map/Cell.cpp \
    map/Field.cpp \
    map/GameMediator.cpp \
    map/Ivents/ColorBoxEvent.cpp \
    map/Ivents/DestroyPlayer.cpp \
    map/Ivents/EventFactory.cpp \
    map/Ivents/ExitEvent.cpp \
    map/Ivents/GlobalEvent.cpp \
    map/Ivents/GlobalEventFactory.cpp \
    map/Ivents/HiddenDoorEvent.cpp \
    map/Ivents/LoseEvent.cpp \
    map/Ivents/ObjectEvent.cpp \
    map/Ivents/ObjectEventFactory.cpp \
    map/Ivents/RestartEvent.cpp \
    map/Ivents/ReturnColorEvent.cpp \
    map/Ivents/VictoryEvent.cpp \
    map/LevelReader.cpp \
    objects/Player.cpp

HEADERS += \
    game/GlobalComponent.h \
    game/GlobalMediator.h \
    game/Mediator.h \
    graphics/BoxView.h \
    graphics/DialogSize.h \
    graphics/EventWindow.h \
    graphics/FieldScene.h \
    graphics/basewindow.h \
    game/Controller.h \
    game/Game.h \
    graphics/CellView.h \
    graphics/PlayerView.h \
    graphics/View.h \
    graphics/dialoglevel.h \
    map/Box.h \
    map/Cell.h \
    map/Field.h \
    map/GameMediator.h \
    map/Ivents/ColorBoxEvent.h \
    map/Ivents/DestroyPlayer.h \
    map/Ivents/Event.h \
    map/Ivents/EventFactory.h \
    map/Ivents/ExitEvent.h \
    map/Ivents/GlobalEvent.h \
    map/Ivents/GlobalEventFactory.h \
    map/Ivents/HiddenDoorEvent.h \
    map/Ivents/LoseEvent.h \
    map/Ivents/ObjectEvent.h \
    map/Ivents/ObjectEventFactory.h \
    map/Ivents/RestartEvent.h \
    map/Ivents/ReturnColorEvent.h \
    map/Ivents/VictoryEvent.h \
    map/LevelReader.h \
    map/MapComponent.h \
    map/MapObject.h \
    objects/Player.h

FORMS += \
    graphics/DialogSize.ui \
    graphics/basewindow.ui \
    graphics/dialoglevel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
