#ifndef READDATA_H
#define READDATA_H

#include <vector>
#include <QPoint>
#include "map/Cell.h"

class ReadData
{
public:
    ReadData();

    std::vector<std::vector<CellSpace::TypeOfCell> > &getType_map();

    std::vector<QPoint*> &getBoxXY();

    int getWidth() const;

    int getHeight() const;

    int getNumBox() const;

    int getConditionHiddenDoors() const;

    int getConditionVictory() const;

    int getSizeCell() const;

    QPoint *getHidDoorXY() const;

    QPoint *getPlayerXY() const;

    int getStartW() const;

    int getStartH() const;

private:
    QPoint *playerXY = nullptr;                     // player

    int width, height;                              // size
    int startW, startH;                             //
    const int sizeCell = 50;                        //

    std::vector<std::vector                         //
               <CellSpace::TypeOfCell>> type_map;   // cell

    QPoint *hidDoorXY = nullptr;                    // door for sublevel

    std::vector<QPoint*> boxXY;                     // boxes
    int numBox;                                     //

    int conditionHiddenDoors;                       // 
    int conditionVictory;

    friend class LevelReader;
    friend class Game;
};

#endif // READDATA_H
