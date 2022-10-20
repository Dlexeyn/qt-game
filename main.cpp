#include <game/GlobalPool.h>
#include <game/GamePool.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GlobalPool glPool;
    GamePool gamePool(glPool.getLvlReader(), glPool.getScene());
    glPool.startGame(gamePool.getFieldView(), gamePool.getPlayerView(), gamePool.getListBoxView());


    if(glPool.getWindow()->getCloseApp())
    {
        qApp->quit();
        return 0;
    }

    return a.exec();
}
