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
    void changeView(int type, int x, int y);
    void setGameScene(QGraphicsScene *newGameScene, ReadData *data);
private:
    std::vector<std::vector<CellPainter*>> graphicsCellMap;
    std::vector<std::vector<CellSpace::TypeOfCell>> typeMap;
    int sizeCell;
};

#endif // FIELDVIEW_H
