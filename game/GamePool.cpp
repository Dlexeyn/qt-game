#include "GamePool.h"

GamePool::GamePool(LevelReader *lvlReader, QGraphicsScene *scene)
{
    if(!lvlReader->getIsReading())
        qApp->quit();
    else
    {
        field = new Field(lvlReader->getReadData());                            // реализация поля
        fieldView = new FieldView(field, lvlReader->getReadData(), scene);     // абстракция поля

        player = new Player;                                                    // реализация игрока
        playerView = new PlayerView(player, lvlReader->getReadData(), scene);  // абстракция игрока

        listBox = std::vector<MapComponent*>(lvlReader->getReadData()->getNumBox(), nullptr);          // реализация ящиков
        listBoxView = std::vector<View*>(lvlReader->getReadData()->getNumBox(), nullptr);             // абстракция ящиков
        for(int index = 0; index < lvlReader->getReadData()->getNumBox(); index++)                   //
        {                                                                                                 //
            listBox[index] = new Box(false);                                                             //
            listBoxView[index] = new BoxView(listBox[index], lvlReader->getReadData(), index, scene);   //
        }

        objectMediator = new GameMediator(field, player, listBox, lvlReader->getReadData());
        field->setEventMediator(objectMediator);
        player->setEventMediator(objectMediator);
        for(int index = 0; index < lvlReader->getReadData()->getNumBox(); index++)
            listBox[index]->setEventMediator(objectMediator);
    }
}

MapView *GamePool::getFieldView()
{
    return fieldView;
}

View *GamePool::getPlayerView()
{
    return playerView;
}

std::vector<View *> &GamePool::getListBoxView()
{
    return listBoxView;
}
