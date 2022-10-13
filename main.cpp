#include "graphics/basewindow.h"
#include "game/Controller.h"
#include "game/Game.h"
#include "map/LevelReader.h"
#include "graphics/FieldScene.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BaseWindow window;
    Controller controller;
    window.setController(&controller);

    LevelReader lvlReader(window.getDialogLevel()->getLevel());
    FieldScene fieldScene(&lvlReader, 50);
    window.init(&lvlReader, &fieldScene);

    Game game(&window, &controller, &fieldScene, &lvlReader);
    window.setMediator(&game);
    controller.setMediator(&game);
    fieldScene.setMediator(&game);
    lvlReader.setMediator(&game);

    if(window.getCloseApp())
    {
        qApp->quit();
        return 0;
    }

    return a.exec();
}
