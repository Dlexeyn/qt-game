#ifndef FIELD_H
#define FIELD_H

#include <vector>

#include "Cell.h"
#include "map/MapComponent.h"
#include "game/Mediator.h"
#include "Ivents/CellEventFactory.h"
#include "map/ReadData.h"
#include "log/LogObject.h"

enum class Object{
    PLAYER = 1,
    BOX = 2
};

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

    void sendCignal();

    void setMap(std::vector<std::vector<CellSpace::TypeOfCell>> &arr);

    int getAttribute(ObjectAttribute at) const;

    void setAttribute(ObjectAttribute at, int arg);

    void callAnObject();

    bool checkState();

private:
    std::vector<std::vector<CellSpace::Cell*>> map_field;
    CellEventFactory *eventFactory = nullptr;
    int map_height, map_width; // size in cells
    QPoint curPoint;
    QPoint curPlayer;
    QPoint hidDoor;
    Object cur;

    bool isHidDoorOpen = false;
};
#endif // FIELD_H
