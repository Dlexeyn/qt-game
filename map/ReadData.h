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
    std::vector<std::vector<CellSpace::TypeOfCell>> type_map;
    std::vector<QPoint*> boxXY;
    QPoint *hidDoorXY = nullptr;
    QPoint *playerXY = nullptr;
    int width, height;
    int numBox;
    int conditionHiddenDoors;
    int conditionVictory;
    int startW, startH;
    const int sizeCell = 50; //px

    friend class LevelReader;
};

#endif // READDATA_H
