#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QGraphicsItem>
#include <vector>
#include "graphics/BoxView.h"
#include "graphics/CellPainter.h"
#include "graphics/PlayerView.h"
#include "map/Field.h"

using namespace map;
class FieldView: public QObject
{
    Q_OBJECT
public:
    FieldView(Field *field, QGraphicsScene *scene);
    ~FieldView();
    PlayerView *getPView() const;

    int getSizeCell() const;

private:
    Field *field = nullptr;
    PlayerView *pView = nullptr;
    std::vector<BoxView*> bViewList;
    std::vector<std::vector<CellPainter*>> graphicsCellMap;
    std::vector<std::vector<CellSpace::TypeOfCell>> typeMap;
    const int sizeCell = 50;
    int start_h, start_w;               // in px
};

#endif // FIELDVIEW_H
