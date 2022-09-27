#include "FieldScene.h"
#include "map/Field.h"

FieldScene::FieldScene(int countCellsX, int countCellsY, int sizeCellPx)
{
    this->countCellsX = countCellsX;
    this->countCellsY = countCellsY;
    this->sizeCellPx = sizeCellPx;

    width = countCellsX * sizeCellPx;
    height = countCellsY * sizeCellPx;
    startW = -(width/2-sizeCellPx/2);
    startH = -(height/2-sizeCellPx/2);

    object = new Field(countCellsY, countCellsX);
    object = dynamic_cast<Field*>(object);
    gameScene = new QGraphicsScene();

    gameScene->setSceneRect(-width/2, -height/2, width, height);

    gameScene->addLine(-width/2,-height/2, width/2,-height/2, QPen(Qt::black));
    gameScene->addLine(-width/2, height/2, width/2, height/2, QPen(Qt::black));
    gameScene->addLine(-width/2,-height/2,-width/2, height/2, QPen(Qt::black));
    gameScene->addLine(width/2,-height/2, width/2, height/2, QPen(Qt::black));

    mapViewField = std::vector<std::vector<CellView*>>(countCellsY, std::vector<CellView*>(countCellsX, nullptr));

    for(int indexY = 0; indexY < countCellsY; indexY++)
        for(int indexX = 0; indexX < countCellsX; indexX++)
        {
            mapViewField[indexY][indexX] = new CellView(sizeCellPx, sizeCellPx,
                                                        (dynamic_cast<Field*>(object))->getCell(indexY, indexX));
            gameScene->addItem(mapViewField[indexY][indexX]);
            mapViewField[indexY][indexX]->setPos(startW + sizeCellPx * indexX, startH + sizeCellPx * indexY);
        }

    playerView = new PlayerView(sizeCellPx-10, sizeCellPx-10, countCellsX/2, countCellsY/2,
                                (dynamic_cast<Field*>(object))->getPlayer(), sizeCellPx);
    gameScene->addItem(playerView);
    playerView->setPos(startW + sizeCellPx * (countCellsX/2), startH + sizeCellPx * (countCellsY/2));


}

void FieldScene::changeView()
{

}

QGraphicsScene *FieldScene::getGameScene() const
{
    return gameScene;
}

PlayerView *FieldScene::getPlayerView() const
{
    return playerView;
}

CellView *FieldScene::getCellView(int x, int y)
{
    return mapViewField[y][x];
}

int FieldScene::getCountCellsX() const
{
    return countCellsX;
}

int FieldScene::getCountCellsY() const
{
    return countCellsY;
}
