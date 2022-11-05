#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QGraphicsItem>
#include <vector>
#include "MapView.h"
#include "graphics/CellPainter.h"
#include "map/ReadData.h"

class FieldView : public MapView
{
public:
    FieldView(MapObject* object, const std::vector<EventSubscriber *> &loggers, ReadData* readData);
    ~FieldView();
    void moving(int &stepX, int &stepY);
    void changeView(int x, int y);
    void setGameScene(QGraphicsScene *newGameScene, ReadData *data);
    bool isMoving(int x, int y);
    void impactOnObject(ObjectType type, const int &x, const int &y);
private:
    void movePointer(int x, int y);
    std::vector<std::vector<CellPainter*>> graphicsCellMap;
    std::vector<std::vector<CellSpace::TypeOfCell>> typeMap;
    int sizeCell;
};

#endif // FIELDVIEW_H
