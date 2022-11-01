#include "app/GameApplication.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameApplication app(&a);
    app.start();
    return a.exec();
}
