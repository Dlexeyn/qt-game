#ifndef CELL_H
#define CELL_H

#include "map/Ivents/Event.h"
#include "objects/Player.h"
#include "map/MapObject.h"
#include "map/MapComponent.h"
#include "game/Mediator.h"

namespace CellSpace {
enum TypeOfCell{
    DIRT,
    SAND,
    GRASS,
    WALL,
    BROKEN_WALL,
    TRAP,
    BROKEN_TRAP,
    TARGET_BOX,
    TARGET_WITH_BOX,
    END_CELL,
    EMPTY
};

enum TypeOfSignal{
    CURRENT_CELL = 1
};

class Cell: public MapComponent
{

public:

    Cell(TypeOfCell type, bool isPass, TypeOfCell nextType = EMPTY): cell_type(type),
        next_cell_type(nextType), isPassable(isPass) {}
    ~Cell(){}

    void sendCignal(int type);

    void changeStatus();

    bool getIsPassable() const;

    void setIsPassable(bool newIsPassable);

    TypeOfCell getCell_type() const;

    //int triggerForPlayer(); // 0 - nothing to do, 1 - change view of cell

    void setPlayer(Player *newPlayer);

    void setNext_cell_type(TypeOfCell newNext_cell_type);

private:
    TypeOfCell cell_type;
    TypeOfCell next_cell_type = EMPTY;
    bool isPassable;
    Player *player = nullptr;
};


}




#endif // CELL_H
