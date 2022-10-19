#include "graphics/basewindow.h"
#include "game/Controller.h"
#include "map/GameMediator.h"
#include "game/Game.h"
#include "map/LevelReader.h"
#include "graphics/FieldScene.h"
#include "map/Box.h"
#include "map/Cell.h"
#include "map/Field.h"
#include "objects/Player.h"
#include "graphics/BoxView.h"
#include "graphics/MapView.h"
#include <vector>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene();
    BaseWindow window;
    Controller controller;
    window.setController(&controller);

    LevelReader lvlReader(window.getDialogLevel()->getLevel());

    Game game(&window, &controller, lvlReader.getReadData());
    game.setReadData(lvlReader.getReadData());
    window.setMediator(&game);
    controller.setMediator(&game);
    lvlReader.setMediator(&game);

    MapComponent *field = new Field(lvlReader.getReadData());                   // реализация поля
    MapView *fieldView = new FieldView(field, lvlReader.getReadData(), scene);     // абстракция поля

    MapComponent *player = new Player;                                          // реализация игрока
    View *playerView = new PlayerView(player, lvlReader.getReadData(), scene);  // абстракция игрока

    std::vector<MapComponent*> listBox(lvlReader.getReadData()->getNumBox(), nullptr);          // реализация ящиков
    std::vector<View*> listBoxView(lvlReader.getReadData()->getNumBox(), nullptr);              // абстракция ящиков
    for(int index = 0; index < lvlReader.getReadData()->getNumBox(); index++)                   //
    {                                                                                           //
        listBox[index] = new Box(false);                                                        //
        listBoxView[index] = new BoxView(listBox[index], lvlReader.getReadData(), index, scene);//
    }                                                                                           //

    game.initGame(fieldView, playerView, listBoxView, lvlReader.getReadData()->getNumBox());  // клиентский код

    GameMediator objectMediator(field, player, listBox, lvlReader.getReadData());
    field->setEventMediator(&objectMediator);
    player->setEventMediator(&objectMediator);
    for(int index = 0; index < lvlReader.getReadData()->getNumBox(); index++)
        listBox[index]->setEventMediator(&objectMediator);

    window.init(lvlReader.getReadData(), scene, playerView);

    if(window.getCloseApp())
    {
        qApp->quit();
        return 0;
    }

    return a.exec();
}
