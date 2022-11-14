#include "DestroyPlayerEvent.h"

DestroyPlayerEvent::DestroyPlayerEvent(const std::vector<EventSubscriber *> &loggers, Cell *newCell, Player *player)
    : CellEvent(loggers, newCell)
{
    this->player = player;
}

void DestroyPlayerEvent::trigger()
{
    player->setCurHealth(0);
    //emit ...
    cell->setCell_type(CellSpace::GRASS);
    emit cell->typeChanged();
    notifySubscribers("the \"DestroyPlayer\" event triggered", "event");
}
