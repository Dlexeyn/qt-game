QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    app/GameApplication.cpp \
    config/AppConfigurator.cpp \
    config/Configurator.cpp \
    data/Point.cpp \
    game/AbstractReader.cpp \
    game/CommandReader.cpp \
    game/Controller.cpp \
    game/GLMessage.cpp \
    game/Game.cpp \
    game/LogPool.cpp \
    game/Reader.cpp \
    graphics/BoxView.cpp \
    graphics/CellPainter.cpp \
    graphics/FieldView.cpp \
    graphics/PlayerView.cpp \
    graphics/dialoglevel.cpp \
    graphics/game_dialogs/HelpDialog.cpp \
    graphics/game_dialogs/LoadDialog.cpp \
    graphics/game_dialogs/MenuDialog.cpp \
    log/ConsoleLogDecorator.cpp \
    log/FileLogDecorator.cpp \
    log/GlobalLogger.cpp \
    log/LogArgs.cpp \
    log/LogData.cpp \
    log/LogDecorator.cpp \
    log/LogManager.cpp \
    log/LogObject.cpp \
    log/Logger.cpp \
    log/Message.cpp \
    log/ObjectLogger.cpp \
    log/StateLogger.cpp \
    main.cpp \
    graphics/basewindow.cpp \
    map/BoxesRule.cpp \
    map/ConditionsRule.cpp \
    map/GeneratorError.cpp \
    map/Ivents/DestroyPlayerEvent.cpp \
    map/Memento/CareTaker.cpp \
    map/Memento/Originator.cpp \
    map/Memento/SnapshotException.cpp \
    map/Memento/SnapshotReader.cpp \
    map/Memento/SnapshotWriter.cpp \
    map/PlayerRule.cpp \
    map/SaveReader/SaveHelper.cpp \
    map/Memento/Snapshot.cpp \
    map/StructMapReader.cpp \
    map/SubLevelDoorRule.cpp \
    map/TargetRule.cpp \
    map/TrapRule.cpp \
    map/WallRule.cpp \
    map/objects/Box.cpp \
    map/Cell.cpp \
    map/Field.cpp \
    map/Ivents/CellEvent.cpp \
    map/Ivents/CellEventFactory.cpp \
    map/Ivents/ColorBoxEvent.cpp \
    map/Ivents/EventFactory.cpp \
    map/Ivents/ExitEvent.cpp \
    map/Ivents/GlobalEvent.cpp \
    map/Ivents/GlobalEventFactory.cpp \
    map/Ivents/HiddenDoorEvent.cpp \
    map/Ivents/LoseEvent.cpp \
    map/Ivents/RestartEvent.cpp \
    map/Ivents/ReturnColorEvent.cpp \
    map/Ivents/VictoryEvent.cpp \
    map/LevelReader.cpp \
    map/ReadData.cpp \
    map/objects/Player.cpp

HEADERS += \
    app/GameApplication.h \
    config/AppConfigurator.h \
    config/ConfigTypes.h \
    config/Configurator.h \
    data/Point.h \
    game/AbstractReader.h \
    game/ArgsTypes.h \
    game/Command.h \
    game/CommandReader.h \
    game/GLMessage.h \
    game/GlobalComponent.h \
    game/GlobalMediator.h \
    game/LogPool.h \
    game/Mediator.h \
    game/Reader.h \
    graphics/BaseWindowStatus.h \
    graphics/BoxView.h \
    graphics/CellPainter.h \
    graphics/EventWindow.h \
    graphics/FieldView.h \
    graphics/StaticView.h \
    graphics/basewindow.h \
    game/Controller.h \
    game/Game.h \
    graphics/PlayerView.h \
    graphics/View.h \
    graphics/dialoglevel.h \
    graphics/game_dialogs/HelpDialog.h \
    graphics/game_dialogs/LoadDialog.h \
    graphics/game_dialogs/MenuDialog.h \
    graphics/game_dialogs/gameDialog.h \
    log/ConsoleLogDecorator.h \
    log/EventSubscriber.h \
    log/FileLogDecorator.h \
    log/GlobalLogger.h \
    log/LogArgs.h \
    log/LogData.h \
    log/LogDecorator.h \
    log/LogManager.h \
    log/LogObject.h \
    log/LogSource.h \
    log/LogTypes.h \
    log/Logger.h \
    log/Message.h \
    log/ObjectLogger.h \
    log/StateLogger.h \
    map/BoxesRule.h \
    map/ConditionsRule.h \
    map/GeneratorError.h \
    map/Ivents/DestroyPlayerEvent.h \
    map/MapGenerator.h \
    map/Memento/CareTaker.hpp \
    map/Memento/Memento.hpp \
    map/Memento/Originator.hpp \
    map/Memento/SnapshotException.h \
    map/Memento/SnapshotReader.h \
    map/Memento/SnapshotWriter.h \
    map/PlayerRule.h \
    map/SaveReader/SaveHelper.h \
    map/Memento/Snapshot.h \
    map/StructMapReader.h \
    map/SubLevelDoorRule.h \
    map/TargetRule.h \
    map/TrapRule.h \
    map/WallRule.h \
    map/objects/Box.h \
    map/Cell.h \
    map/Field.h \
    map/Ivents/CellEvent.h \
    map/Ivents/CellEventFactory.h \
    map/Ivents/ColorBoxEvent.h \
    map/Ivents/Event.h \
    map/Ivents/EventFactory.h \
    map/Ivents/ExitEvent.h \
    map/Ivents/GlobalEvent.h \
    map/Ivents/GlobalEventFactory.h \
    map/Ivents/HiddenDoorEvent.h \
    map/Ivents/LoseEvent.h \
    map/Ivents/RestartEvent.h \
    map/Ivents/ReturnColorEvent.h \
    map/Ivents/VictoryEvent.h \
    map/LevelReader.h \
    map/ReadData.h \
    map/objects/Object.h \
    map/objects/Player.h

FORMS += \
    graphics/basewindow.ui \
    graphics/dialoglevel.ui \
    graphics/game_dialogs/HelpDialog.ui \
    graphics/game_dialogs/LoadDialog.ui \
    graphics/game_dialogs/MenuDialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    graphics/ux/icons-menu.qrc
