#ifndef CELL_H
#define CELL_H

#include "Ivents/Event.h"
#include "objects/Player.h"
#include "map/MapObject.h"
#include "map/MapComponent.h"
#include "game/Mediator.h"

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

enum TypeOfSignal{
    BOX_EVENT = 1,
    RANDOM_EVENT = 2,
    CONDITION_IS_TRUE = 3,
    GET_EVENT = 4
};

class Cell: public MapComponent
{

public:

    Cell(TypeOfCell type, bool isPass, TypeOfCell nextType = EMPTY): cell_type(type),
        next_cell_type(nextType), isPassable(isPass) {}
    ~Cell(){}

    void sendCignal(int type);

    int getFirstAttribute() const;  // return cell type

    int getSecondAttribute() const; // return future cell type

    void setFirstAttribute(int newAttribute);

    void setSecondAttribute(int newAttribute);

    void changeStatus();

    bool getIsPassable() const;

    void setIsPassable(bool newIsPassable);

    TypeOfCell getCell_type() const;

    void setPlayer(Player *newPlayer);

    void setNext_cell_type(TypeOfCell newNext_cell_type);

    Player *getPlayer() const;

private:
    TypeOfCell cell_type;
    TypeOfCell next_cell_type = EMPTY;
    bool isPassable;
    Player *player = nullptr;
};


}




#endif // CELL_H
