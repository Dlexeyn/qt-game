#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QGraphicsItem>
#include <vector>
#include "graphics/BoxView.h"
#include "graphics/CellPainter.h"
#include "graphics/PlayerView.h"
#include "map/Field.h"
#include "map/ReadData.h"

class FieldView: public QObject
{
    Q_OBJECT
public:
    FieldView(Field *field, ReadData *rd, QGraphicsScene *scene);
    ~FieldView();
    PlayerView *getPView() const;

private:
    Field *field = nullptr;
    PlayerView *pView = nullptr;
    std::vector<BoxView*> bViewList;
    std::vector<std::vector<CellPainter*>> graphicsCellMap;
    std::vector<std::vector<CellSpace::TypeOfCell>> typeMap;
    int sizeCell;
};

#endif // FIELDVIEW_H
