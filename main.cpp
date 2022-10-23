#include <game/GlobalPool.h>
#include <game/GamePool.h>
#include <QApplication>
#include "log/Logger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Logger logger;
    GlobalPool glPool(&logger);
    GamePool gamePool(glPool.getLvlReader(), glPool.getScene(), &logger);
    glPool.startGame(gamePool.getFieldView(), gamePool.getPlayerView(), gamePool.getListBoxView());


    if(glPool.getWindow()->getCloseApp())
    {
        qApp->quit();
        return 0;
    }

    return a.exec();
}
