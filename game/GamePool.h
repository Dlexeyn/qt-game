#ifndef GAMEPOOL_H
#define GAMEPOOL_H
#include "map/Box.h"
#include "map/Cell.h"
#include "map/Field.h"
#include "objects/Player.h"
#include "graphics/BoxView.h"
#include "graphics/MapView.h"
#include "graphics/FieldView.h"
#include "graphics/PlayerView.h"
#include "map/LevelReader.h"
#include "map/GameMediator.h"
#include "game/LogPool.h"
#include <vector>
#include <QApplication>

class GamePool
{
public:
    GamePool(LevelReader *lvlReader, QGraphicsScene *scene, LogPool *logPool);
    ~GamePool();
    MapView *getFieldView();

    View *getPlayerView();

    std::vector<View *> &getListBoxView();

private:
    MapComponent *field = nullptr;                   // реализация поля
    MapView *fieldView = nullptr;                   // абстракция поля

    MapComponent *player = nullptr;               // реализация игрока
    View *playerView = nullptr;                  // абстракция игрока

    std::vector<MapComponent*> listBox;        // реализация ящиков
    std::vector<View*> listBoxView;           // абстракция ящиков

    GameMediator *objectMediator = nullptr;
};

#endif // GAMEPOOL_H
