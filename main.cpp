#include "graphics/basewindow.h"
#include "game/Controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BaseWindow window;

    Controller controller(window.getFieldScene());
    window.setController(&controller);

    if(window.getCloseApp())
    {
        qApp->quit();
        return 0;
    }

    return a.exec();
}
