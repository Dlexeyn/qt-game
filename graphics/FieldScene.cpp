//#include "FieldScene.h"
//#include "map/Field.h"

//FieldScene::FieldScene(LevelReader *lvlReader, int sizeCellPx)
//{
//    this->countCellsX = lvlReader->getWidth();
//    this->countCellsY = lvlReader->getHeight();
//    this->sizeCellPx = sizeCellPx;

//    width = this->countCellsX * sizeCellPx;
//    height = this->countCellsY * sizeCellPx;

//    startW = -(width/2-sizeCellPx/2);
//    startH = -(height/2-sizeCellPx/2);

//    hiddenDoor.setX(lvlReader->getHidDoorXY().x());
//    hiddenDoor.setY(lvlReader->getHidDoorXY().y());

//    object = new Field(this->countCellsY, this->countCellsX,
//                       lvlReader->getType_map(), lvlReader->getNumBox());

//    gameScene = new QGraphicsScene();
//    gameScene->setSceneRect(-width/2, -height/2, width, height);
//    gameScene->addLine(-width/2,-height/2, width/2,-height/2, QPen(Qt::black));
//    gameScene->addLine(-width/2, height/2, width/2, height/2, QPen(Qt::black));
//    gameScene->addLine(-width/2,-height/2,-width/2, height/2, QPen(Qt::black));
//    gameScene->addLine(width/2,-height/2, width/2, height/2, QPen(Qt::black));

//    mapViewField = std::vector<std::vector<CellView*>>(this->countCellsY,
//                                               std::vector<CellView*>(this->countCellsX, nullptr));

//    for(int indexY = 0; indexY < this->countCellsY; indexY++)
//        for(int indexX = 0; indexX < this->countCellsX; indexX++)
//        {
//            mapViewField[indexY][indexX] = new CellView(sizeCellPx, sizeCellPx,
//                                                        (dynamic_cast<Field*>(object))->getCell(indexY, indexX),
//                                                        gameScene);
//            gameScene->addItem(mapViewField[indexY][indexX]);
//            mapViewField[indexY][indexX]->setPos(startW + sizeCellPx * indexX, startH + sizeCellPx * indexY);
//        }

//    listBoxView = std::vector<BoxView*>(lvlReader->getNumBox(), nullptr);

//    for(int index = 0; index < lvlReader->getNumBox(); index++)
//    {
//        listBoxView[index] = new BoxView(sizeCellPx/1.4f, sizeCellPx/1.4f,
//                                         lvlReader->getBoxXY()[index],
//                                         (dynamic_cast<Field*>(object))->getBox(index),
//                                         sizeCellPx);
//        gameScene->addItem(listBoxView[index]);
//        listBoxView[index]->setPos(startW + sizeCellPx * listBoxView[index]->getXY()->x(),
//                                   startH + sizeCellPx * listBoxView[index]->getXY()->y());
//    }


//    playerView = new PlayerView(sizeCellPx-10, sizeCellPx-10, this->countCellsX/2,
//                                this->countCellsY/2, sizeCellPx);
//    gameScene->addItem(playerView);
//    playerView->setPos(startW + sizeCellPx * (this->countCellsX/2), startH + sizeCellPx * (countCellsY/2));

//    mapViewField[playerView->getXY()->y()][playerView->getXY()->x()]->
//            playerOnCell(playerView->getPlayer());

//    GameMediator *gameMediator = new GameMediator(dynamic_cast<MapComponent*>(object),
//                                    dynamic_cast<MapComponent*>(playerView->getObject()),
//                                                  lvlReader);

//    object->setEventMediator(gameMediator);
//    playerView->getObject()->setEventMediator(gameMediator);
//}

//void FieldScene::sendCignal()
//{
//    game->notify(this, "fieldScene");
//}

//void FieldScene::changeView()
//{

//}

//QGraphicsScene *FieldScene::getGameScene() const
//{
//    return gameScene;
//}

//PlayerView *FieldScene::getPlayerView() const
//{
//    return playerView;
//}

//CellView *FieldScene::getCellView(int x, int y)
//{
//    return mapViewField[y][x];
//}

//BoxView *FieldScene::isBox(int x, int y)
//{
//    for(auto curBox : listBoxView)
//    {
//        if(curBox->getXY()->x() == x and
//                curBox->getXY()->y() == y)
//            return curBox;
//    }
//    return nullptr;
//}

//int FieldScene::getCountCellsX() const
//{
//    return countCellsX;
//}

//int FieldScene::getCountCellsY() const
//{
//    return countCellsY;
//}

//void FieldScene::playerMove(int stepX, int stepY)
//{
//    if(mapViewField[playerView->getXY()->y() + stepY][playerView->getXY()->x() + stepX]->isCellPassable())   // проверка на проходимость
//    {
//        mapViewField[playerView->getXY()->y()][playerView->getXY()->x()]->playerIsGone();

//        playerView->moving(stepX, stepY);

//        mapViewField[playerView->getXY()->y()][playerView->getXY()->x()]->
//                playerOnCell(playerView->getPlayer());
//        sendCignal();
//    }

//}

//bool FieldScene::boxMove(int stepX, int stepY)
//{
//    BoxView *box = isBox(playerView->getXY()->x() + stepX, playerView->getXY()->y() + stepY);
//    if(box and !mapViewField[playerView->getXY()->y() + 2*stepY][playerView->getXY()->x() + 2*stepX]->isCellPassable()) // проверка на ящик
//        return false;                                                                                     // и проходимость за ящиком
//    else if(box) // если нет гранцицы карты
//    {
//        if(isBox(playerView->getXY()->x() + 2*stepX, playerView->getXY()->y() + 2*stepY)) // проверка на два ящика подряд
//            return false;

//        mapViewField[box->getXY()->y()][box->getXY()->x()]->changeView();
//        box->moving(stepX, stepY);
//        mapViewField[box->getXY()->y()][box->getXY()->x()]->changeView();
//        mapViewField[hiddenDoor.y()][hiddenDoor.x()]->changeView();
//    }
//    return true;
//}

//void FieldScene::checkPlayerStep(int stepX, int stepY)
//{
//    QPoint *curPos = getPlayerView()->getXY();


//    if(curPos->y() == 0 and stepY == -1)
//        stepY = getCountCellsY()-1;
//    else if(curPos->y() == getCountCellsY()-1 and stepY == 1)
//        stepY = -(getCountCellsY()-1);
//    else if(curPos->x() == 0 and stepX == -1)
//        stepX = getCountCellsX()-1;
//    else if(curPos->x() == getCountCellsX()-1 and stepX == 1)
//        stepX = -(getCountCellsX()-1);

//    if(boxMove(stepX, stepY))
//        playerMove(stepX, stepY);
//}
