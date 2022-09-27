#ifndef CELL_H
#define CELL_H

#include "objects/Player.h"
#include "map/MapObject.h"

class Cell: public MapObject
{

public:

    enum TypeOfCell{
        WATER,
        LAVA,
        DIRT,
        SAND,
        GRASS,
        WALL,
        BROKEN_WALL,
        TRAP,
        BROKEN_TRAP,
        EMPTY
    };

    Cell(TypeOfCell type, bool isPass, TypeOfCell nextType = EMPTY): cell_type(type),
        next_cell_type(nextType), isPassable(isPass) {}
    ~Cell(){}

    void changeStatus();

    bool getIsPassable() const;

    void setIsPassable(bool newIsPassable);

    Cell::TypeOfCell getCell_type() const;

    void triggerForPlayer(Player *player);

private:

    TypeOfCell cell_type;
    TypeOfCell next_cell_type = EMPTY;
    bool isPassable;

};



#endif // CELL_H