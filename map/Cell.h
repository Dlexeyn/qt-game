#ifndef CELL_H
#define CELL_H

#include "map/Ivents/Event.h"
#include <QObject>
#include "qobjectdefs.h"

namespace CellSpace {
enum TypeOfCell{
    DIRT = 100,             // 'd'
    SAND = 115,             // 's'
    GRASS = 103,            // 'g'
    WALL = 119,             // 'w'
    TEMP_WALL = 87,         // 'W'
    BROKEN_WALL = 6,        //
    TRAP = 84,              // 'T'
    BROKEN_TRAP = 116,      // 't'
    TARGET_BOX = 98,        // 'b'
    TARGET_WITH_BOX = 66,   // 'B'
    END_CELL = 101,         // 'e'
    EMPTY = 12
};

class Cell: public QObject
{
    Q_OBJECT
public:
    Cell(TypeOfCell type, bool isPass): cell_type(type),
        isPassable(isPass) {}
    ~Cell(){}

    bool getIsPassable() const;

    void setIsPassable(bool newIsPassable);

    TypeOfCell getCell_type() const;

    void clearEvent();

    Event *getEvent() const;

    void setCell_type(TypeOfCell newCell_type);

    void setEvent(Event *newEvent);

signals:
    void typeChanged();

private:
    Event *event = nullptr;
    TypeOfCell cell_type;
    bool isPassable;
};


}




#endif // CELL_H
