#ifndef CELLEVENT_H
#define CELLEVENT_H

#include "Event.h"
#include "map/Cell.h"
#include "log/LogObject.h"

using namespace CellSpace;

class CellEvent: public Event, public LogObject
{
public:
    CellEvent(const std::vector<EventSubscriber*> &loggers, Cell *newCell = nullptr);

    void setCell(Cell *newCell);

protected:
    Cell *cell = nullptr;
};






#endif // CELLEVENT_H
