#ifndef FIELD_H
#define FIELD_H

#include <vector>

#include "Cell.h"
#include "map/MapComponent.h"
#include "game/Mediator.h"
#include "Ivents/CellEventFactory.h"
#include "map/ReadData.h"
#include "log/LogObject.h"

class Field: public MapComponent
{
public:
    Field(ReadData *readData, const std::vector<EventSubscriber *> &loggers);

    Field(const Field& otherfield);

    Field(Field&& field);

    Field &operator=(const Field &other);

    Field &operator=(Field &&other);

    ~Field();

    int changeStatus();

    void sendCignal(int type);

    void setMap(std::vector<std::vector<CellSpace::TypeOfCell>> &arr);

    int getFirstAttribute() const; // return x current point
    int getSecondAttribute() const; // return y current point

    void setFirstAttribute(int newAttribute);   // set x current point
    void setSecondAttribute(int newAttribute);  // set y current point

    int callAnObject();

    bool checkState();

private:
    std::vector<std::vector<CellSpace::Cell*>> map_field;
    CellEventFactory *eventFactory = nullptr;
    int map_height, map_width; // size in cells
    QPoint curPoint;
    QPoint curPlayer;
    QPoint hidDoor;
    bool isHidDoorOpen = false;
};
#endif // FIELD_H
