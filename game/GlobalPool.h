#ifndef GLOBALPOOL_H
#define GLOBALPOOL_H

#include <QGraphicsScene>
#include "game/Game.h"
#include "game/Controller.h"
#include "graphics/basewindow.h"
#include "map/LevelReader.h"
#include "graphics/MapView.h"
#include "game/LogPool.h"


class GlobalPool
{
public:
    GlobalPool(LogPool *logPool);
    LevelReader *getLvlReader() const;

    void startGame(MapView *fieldView, View *playerView, std::vector<View *> &listBoxView);

    QGraphicsScene *getScene();

    BaseWindow *getWindow() const;

private:
    QGraphicsScene *scene = nullptr;
    BaseWindow *window = nullptr;
    Controller *controller = nullptr;
    LevelReader *lvlReader = nullptr;
    Game *game = nullptr;
};

#endif // GLOBALPOOL_H
