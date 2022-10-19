//#ifndef FIELDSCENE_H
//#define FIELDSCENE_H

//#include <QGraphicsScene>
//#include <vector>
//#include <QPoint>
//#include <list>
//#include "PlayerView.h"
//#include "View.h"
//#include "BoxView.h"
//#include "map/LevelReader.h"
//#include "map/GameMediator.h"
//#include "game/GlobalComponent.h"

//class FieldScene
//{
//public:
//    FieldScene(MapObject *object) : View(object) {}
//    FieldScene(LevelReader *lvlReader, int sizeCellPx);
//    //~FieldScene();

//    void sendCignal();

//    void changeView();

//    QGraphicsScene *getGameScene() const;

//    PlayerView *getPlayerView() const;

//    CellView *getCellView(int x, int y);

//    BoxView *isBox(int x, int y);

//    int getCountCellsX() const;

//    int getCountCellsY() const;

//    void playerMove(int stepX, int stepY);

//    bool boxMove(int stepX, int stepY);

//    void checkPlayerStep(int stepX, int stepY);

//private:
//    int width, height;  // in Px
//    int countCellsX, countCellsY; // in Cell
//    int sizeCellPx; // size of cell
//    int startW, startH; // start point
//    QPoint hiddenDoor;

//    //QGraphicsScene *gameScene = nullptr;
//    PlayerView *playerView = nullptr;


//    std::vector<BoxView*> listBoxView;
//    std::vector<std::vector<CellView*>> mapViewField;
//};

//#endif // FIELDSCENE_H
