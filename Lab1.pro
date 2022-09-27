QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game/Controller.cpp \
    game/Game.cpp \
    graphics/CellView.cpp \
    graphics/DialogSize.cpp \
    graphics/FieldScene.cpp \
    graphics/PlayerView.cpp \
    main.cpp \
    graphics/basewindow.cpp \
    map/Cell.cpp \
    map/Field.cpp \
    objects/Player.cpp

HEADERS += \
    graphics/DialogSize.h \
    graphics/FieldScene.h \
    graphics/basewindow.h \
    game/Controller.h \
    game/Game.h \
    graphics/CellView.h \
    graphics/PlayerView.h \
    graphics/View.h \
    map/Cell.h \
    map/Field.h \
    map/Ivents/Ivent.h \
    map/MapObject.h \
    objects/Player.h

FORMS += \
    graphics/DialogSize.ui \
    graphics/basewindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
