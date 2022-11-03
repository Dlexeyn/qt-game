#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H
#include <QObject>
#include <QGraphicsScene>
#include "game/Game.h"
#include "graphics/basewindow.h"
#include "graphics/dialoglevel.h"
#include "game/Controller.h"
#include "map/LevelReader.h"
#include "game/LogPool.h"
#include "config/AppConfigurator.h"

class GameApplication: public QObject
{
    Q_OBJECT
public:
    explicit GameApplication(QApplication *app, QObject *parent = nullptr);
    ~GameApplication();
    void start();
signals:

private:
    QApplication *app = nullptr;
    Config::AppConfigurator *config = nullptr;
    QTimer gameTimer;
    DialogLevel *levelWindow = nullptr;
    BaseWindow *baseWindow = nullptr;
    Controller *controller = nullptr;
    LevelReader *lvlReader = nullptr;
    LogPool *logPool = nullptr;
    QGraphicsScene *scene = nullptr;
    Game *game = nullptr;
private slots:
    void setLevel(int level);
    void changeConfigs();
    void changeLevel();
    void exit();
};

#endif // GAMEAPPLICATION_H
