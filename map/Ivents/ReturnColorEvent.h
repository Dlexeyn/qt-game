#ifndef RETURNCOLOREVENT_H
#define RETURNCOLOREVENT_H

#include "CellEvent.h"
#include "map/Cell.h"

class ReturnColorEvent : public CellEvent
{
public:
    ReturnColorEvent(const std::vector<EventSubscriber *> &loggers, Cell *newCell, Player *player);
    using CellEvent::CellEvent;
    void trigger();
};

#endif // RETURNCOLOREVENT_H
