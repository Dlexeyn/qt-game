#include <game/GlobalPool.h>
#include <game/GamePool.h>
#include <QApplication>
#include "game/LogPool.h"
#include "config/AppConfigurator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Config::AppConfigurator configurator;
    LogPool logPool(&configurator);
    GlobalPool glPool(&logPool);
    GamePool gamePool(glPool.getLvlReader(), glPool.getScene(), &logPool);
    glPool.startGame(gamePool.getFieldView(), gamePool.getPlayerView(), gamePool.getListBoxView());


    if(glPool.getWindow()->getCloseApp())
    {
        qApp->quit();
        return 0;
    }

    return a.exec();
}
