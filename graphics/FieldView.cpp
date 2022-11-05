#include "FieldView.h"

FieldView::FieldView(MapObject *object, const std::vector<EventSubscriber *> &loggers, ReadData *readData)
    : MapView(object, loggers)
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
    graphicsCellMap = std::vector<std::vector<CellPainter*>>
    (height, std::vector<CellPainter*>(width, nullptr));
    typeMap = readData->getType_map();
}

FieldView::~FieldView()
{
    graphicsCellMap.clear();
    std::vector< std::vector<CellPainter*>>( graphicsCellMap ).swap( graphicsCellMap );
}

void FieldView::moving(int &stepX, int &stepY)
{
      XY->rx() += stepX;
      XY->ry() += stepY;
      changeView(XYHidDoor->x(), XYHidDoor->y());

}

void FieldView::changeView(int x, int y)
{
    movePointer(x, y);
    int t = object->changeStatus();
    if(t)
    {
        graphicsCellMap[y][x]->setType(t);
        graphicsCellMap[y][x]->hide();
        graphicsCellMap[y][x]->show();
    }
}

void FieldView::setGameScene(QGraphicsScene *newGameScene, ReadData *data)
{
    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++)
        {
            graphicsCellMap[y][x] = new CellPainter(sizeCell, data->getType_map()[y][x]);
            newGameScene->addItem(graphicsCellMap[y][x]);
            graphicsCellMap[y][x]->setPos(data->getStartW() + sizeCell * x, data->getStartH() + sizeCell * y);
        }
}

bool FieldView::isMoving(int x, int y)
{
    movePointer(x, y);

    bool var = object->checkState();

    movePointer(XY->x(), XY->y());

    return var;
}

void FieldView::impactOnObject(ObjectType type, const int &x, const int &y)
{
    movePointer(x, y);
    object->setAttribute(ObjectAttribute::OBJECT, int(type));
    object->callAnObject();
}

void FieldView::movePointer(int x, int y)
{
    object->setAttribute(ObjectAttribute::CUR_X, x);
    object->setAttribute(ObjectAttribute::CUR_Y, y);
}
