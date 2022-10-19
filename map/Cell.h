#ifndef CELL_H
#define CELL_H

#include "map/MapComponent.h"
#include "map/Ivents/Event.h"

namespace CellSpace {
enum TypeOfCell{
    DIRT = 1,
    SAND = 2,
    GRASS = 3,
    WALL = 4,
    TEMP_WALL = 5,
    BROKEN_WALL = 6,
    TRAP = 7,
    BROKEN_TRAP = 8,
    TARGET_BOX = 9,
    TARGET_WITH_BOX = 10,
    END_CELL = 11,
    EMPTY = 12
};

class Cell
{

public:
    Cell(TypeOfCell type, bool isPass): cell_type(type),
        isPassable(isPass) {}
    ~Cell(){}

    bool getIsPassable() const;

    void setIsPassable(bool newIsPassable);

    TypeOfCell getCell_type() const;

    void setEvent(Event* newEvent);

    Event *getEvent() const;

    void setCell_type(TypeOfCell newCell_type);

private:
    Event *event = nullptr;
    TypeOfCell cell_type;
    bool isPassable;
};


}




#endif // CELL_H
