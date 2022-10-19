#include "ReadData.h"

ReadData::ReadData()
{

}

std::vector<std::vector<CellSpace::TypeOfCell> > &ReadData::getType_map()
{
    return type_map;
}

std::vector<QPoint *> &ReadData::getBoxXY()
{
    return boxXY;
}

int ReadData::getWidth() const
{
    return width;
}

int ReadData::getHeight() const
{
    return height;
}

int ReadData::getNumBox() const
{
    return numBox;
}

int ReadData::getConditionHiddenDoors() const
{
    return conditionHiddenDoors;
}

int ReadData::getConditionVictory() const
{
    return conditionVictory;
}

int ReadData::getSizeCell() const
{
    return sizeCell;
}

QPoint *ReadData::getHidDoorXY() const
{
    return hidDoorXY;
}

QPoint *ReadData::getPlayerXY() const
{
    return playerXY;
}

int ReadData::getStartW() const
{
    return startW;
}

int ReadData::getStartH() const
{
    return startH;
}
