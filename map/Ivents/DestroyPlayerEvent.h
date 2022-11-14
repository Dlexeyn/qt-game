#ifndef DESTROYPLAYEREVENT_H
#define DESTROYPLAYEREVENT_H

#include "CellEvent.h"

class DestroyPlayerEvent : public CellEvent
{
public:
    DestroyPlayerEvent(const std::vector<EventSubscriber*> &loggers,
                  Cell *newCell = nullptr, Player *player = nullptr);
    void trigger();
};

#endif // DESTROYPLAYEREVENT_H
