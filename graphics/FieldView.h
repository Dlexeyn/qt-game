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
    FieldView(MapObject *object, ReadData *readData, QGraphicsScene *scene);
    //FieldView();
    ~FieldView();
    void moving(int &stepX, int &stepY);
    void setMap(ReadData *readData);
    void changeView(int type, int x, int y);
private:
    std::vector<std::vector<CellPainter*>> graphicsCellMap;
    int sizeCell;
};

#endif // FIELDVIEW_H
