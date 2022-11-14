#include "ReturnColorEvent.h"



ReturnColorEvent::ReturnColorEvent(const std::vector<EventSubscriber *> &loggers, Cell *newCell, Player *player)
    : CellEvent(loggers, newCell)
{
    this->player = player;
}

void ReturnColorEvent::trigger()
{
    player->removePoint();
    cell->setCell_type(CellSpace::TARGET_BOX);
    emit cell->typeChanged();
    notifySubscribers("the \"ReturnColorBox\" event triggered", "event");
}
