#include "FieldView.h"
#include <QGraphicsScene>

FieldView::FieldView(Field *field, QGraphicsScene *scene)
    : field(field)
{
    // init CellMap ===================================================================
    int h = field->getMap_height(), w = field->getMap_width();

    start_h = (-(sizeCell/2) * (h-1));
    start_w = (-(sizeCell/2) * (w-1));

    graphicsCellMap = std::vector<std::vector<CellPainter*>>
        (h, std::vector<CellPainter*>(w, nullptr));
    for(int y = 0; y < h; y++)
        for(int x = 0; x < w; x++)
        {
            graphicsCellMap[y][x] = new CellPainter(sizeCell, field->getMap_field()[y][x]);
            scene->addItem(graphicsCellMap[y][x]);
            graphicsCellMap[y][x]->setPos(start_w + sizeCell * x,
                                          start_h + sizeCell * y);
        }
    // ================================================================================

    // init PlayerView ================================================================
    pView = new PlayerView(sizeCell, field->getPlayer());
    scene->addItem(pView);
    pView->setPos(start_w + sizeCell * field->getPlayer()->getPos(true),
                  start_h + sizeCell * field->getPlayer()->getPos(false));

    // ================================================================================

    // init BoxViews ==================================================================
    bViewList = std::vector<BoxView*>(field->getBoxList().size(), nullptr);
    for(size_t index = 0; index < field->getBoxList().size(); index++)
    {
        Box *cur =  field->getBoxList()[index];
        bViewList[index] = new BoxView(sizeCell, cur);
        scene->addItem(bViewList[index]);
        bViewList[index]->setPos(start_w + sizeCell * cur->getPos(true),
                                 start_h + sizeCell * cur->getPos(false));
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

int FieldView::getSizeCell() const
{
    return sizeCell;
}


