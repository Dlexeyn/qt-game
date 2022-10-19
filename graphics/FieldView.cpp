#include "FieldView.h"

FieldView::FieldView(MapObject *object, ReadData *readData, QGraphicsScene *scene) : MapView(object, scene)
{
    this->height = readData->getHeight();
    this->width = readData->getWidth();

    this->XY = new QPoint();
    this->XY->setX(readData->getPlayerXY()->x());
    this->XY->setY(readData->getPlayerXY()->y());

    this->XYHidDoor = new QPoint();
    this->XYHidDoor->setX(readData->getHidDoorXY()->x());
    this->XYHidDoor->setY(readData->getHidDoorXY()->y());

    this->sizeCell = readData->getSizeCell();
    setMap(readData);
}

void FieldView::moving(int &stepX, int &stepY)
{
    object->setFirstAttribute(XY->x() + stepX);
    object->setSecondAttribute(XY->y() + stepY);
    if(object->checkState())    // проходимость клетки
    {
        XY->rx() += stepX;
        XY->ry() += stepY;
        changeView(object->callAnObject(), XYHidDoor->x(), XYHidDoor->y());
        changeView(object->changeStatus(), XY->x(), XY->y());
    }
    else
    {
        object->setFirstAttribute(XY->x());
        object->setSecondAttribute(XY->y());
        stepX = stepY = 0;
    }
}

void FieldView::setMap(ReadData *readData)
{
    graphicsCellMap = std::vector<std::vector<CellPainter*>> (height, std::vector<CellPainter*>(width, nullptr));
    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++)
        {
            graphicsCellMap[y][x] = new CellPainter(sizeCell, readData->getType_map()[y][x]);
            gameScene->addItem(graphicsCellMap[y][x]);
            graphicsCellMap[y][x]->setPos(readData->getStartW() + sizeCell * x, readData->getStartH() + sizeCell * y);
        }
}

void FieldView::changeView(int type, int x, int y)
{
    if(type)
    {
        graphicsCellMap[y][x]->setType(type);
        graphicsCellMap[y][x]->hide();
        graphicsCellMap[y][x]->show();
    }
}
