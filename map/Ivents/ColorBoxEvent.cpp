#include "ColorBoxEvent.h"

ColorBoxEvent::ColorBoxEvent(const std::vector<EventSubscriber *> &loggers, Cell *newCell, Player *player)
    : CellEvent(loggers, newCell)
{
    this->player = player;
}

void ColorBoxEvent::trigger()
{
    player->addPoint();
    cell->setCell_type(CellSpace::TARGET_WITH_BOX);
    emit cell->typeChanged();
    notifySubscribers("the \"ColorBox\" event triggered", "event");
}
