#include "FieldView.h"
#include <QGraphicsScene>

FieldView::FieldView(Field *field, ReadData *rd, QGraphicsScene *scene)
    : field(field), sizeCell(rd->getSizeCell())
{
    // init CellMap ===================================================================
    graphicsCellMap = std::vector<std::vector<CellPainter*>>
        (field->map_height, std::vector<CellPainter*>(field->map_width, nullptr));
    for(int y = 0; y < field->map_height; y++)
        for(int x = 0; x < field->map_width; x++)
        {
            graphicsCellMap[y][x] = new CellPainter(sizeCell, field->map_field[y][x]);
            scene->addItem(graphicsCellMap[y][x]);
            graphicsCellMap[y][x]->setPos(rd->getStartW() + sizeCell * x,
                                          rd->getStartH() + sizeCell * y);
        }
    // ================================================================================

    // init PlayerView ================================================================
    pView = new PlayerView(rd->getSizeCell(), field->player);
    scene->addItem(pView);
    pView->setPos(rd->getStartW() + sizeCell * rd->getPlayerXY()->x(),
                  rd->getStartH() + sizeCell * rd->getPlayerXY()->y());

    // ================================================================================

    // init BoxViews ==================================================================
    bViewList = std::vector<BoxView*>(rd->getNumBox(), nullptr);
    for(int index = 0; index < rd->getNumBox(); index++)
    {
        bViewList[index] = new BoxView(rd->getSizeCell(), field->BoxList[index]);
        scene->addItem(bViewList[index]);
        bViewList[index]->setPos(rd->getStartW() + sizeCell * rd->getBoxXY()[index]->x(),
                                 rd->getStartH() + sizeCell * rd->getBoxXY()[index]->y());
    }
    // ================================================================================


}

FieldView::~FieldView()
{
    graphicsCellMap.clear();
    std::vector< std::vector<CellPainter*>>( graphicsCellMap ).swap( graphicsCellMap );
}

PlayerView *FieldView::getPView() const
{
    return pView;
}


