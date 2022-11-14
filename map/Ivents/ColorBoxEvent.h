#ifndef COLORBOXEVENT_H
#define COLORBOXEVENT_H

#include "CellEvent.h"
#include "map/Cell.h"

class ColorBoxEvent : public CellEvent
{
public:
    ColorBoxEvent(const std::vector<EventSubscriber*> &loggers,
                  Cell *newCell = nullptr, Player *player = nullptr);
    using CellEvent::CellEvent;
    void trigger();
};

#endif // COLORBOXEVENT_H
