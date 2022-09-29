#ifndef FIELDSCENE_H
#define FIELDSCENE_H

#include <QGraphicsScene>
#include <vector>
#include <QPoint>
#include "PlayerView.h"
#include "CellView.h"
#include "View.h"

class FieldScene: public View
{
public:
    FieldScene(int countCellsX, int countCellsY, int sizeCellPx);
    //~FieldScene();

    void changeView();

    QGraphicsScene *getGameScene() const;

    PlayerView *getPlayerView() const;

    CellView *getCellView(int x, int y);

    int getCountCellsX() const;

    int getCountCellsY() const;

    void playerMove(int stepX, int stepY);

private:
    int width, height;  // in Px
    int countCellsX, countCellsY; // in Cell
    int sizeCellPx; // size of cell
    int startW, startH; // start point

    //QGraphicsScene *gameScene = nullptr;
    PlayerView *playerView = nullptr;
    std::vector<std::vector<CellView*>> mapViewField;
};

#endif // FIELDSCENE_H
