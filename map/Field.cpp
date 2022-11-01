#include "Field.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Ivents/CellEventFactory.h"


Field::Field(ReadData *readData, const std::vector<EventSubscriber *> &loggers)
    : map_height(readData->getHeight()), map_width(readData->getWidth())
{
    eventFactory = new CellEventFactory(CellEventFactory::COLOR_BOX, loggers);
    subscribe(loggers);
    notifySubscribers("Field : the field was created with size ", "object", new LogArgs(ArgsLog::SIZE_WH, map_width, map_height));
    setMap(readData->getType_map());
    curPlayer.setX(readData->getPlayerXY()->x());
    curPlayer.setY(readData->getPlayerXY()->y());
}

Field::~Field()
{
    map_field.clear();
    std::vector< std::vector< Cell* > >( map_field ).swap( map_field );
    delete eventFactory;
}

Field::Field(const Field &field) : map_height(field.map_height), map_width(field.map_width) {
    std::copy(field.map_field.begin(), field.map_field.end(), std::back_inserter(map_field));
    curPlayer = field.curPlayer;
    curPoint = field.curPoint;
    hidDoor = field.hidDoor;
    eventFactory = new CellEventFactory(*field.eventFactory);
}

Field::Field(Field &&field) : map_height(field.map_height), map_width(field.map_width) {
    map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));
    for(int y = 0; y < map_height; y++)
        for(int x = 0; x < map_width; x++)
            std::swap(map_field[x][y], field.map_field[x][y]);
    std::swap(curPlayer, field.curPlayer);
    std::swap(curPlayer, field.curPlayer);
    std::swap(curPlayer, field.curPlayer);
    std::swap(eventFactory, field.eventFactory);
}

int Field::changeStatus()
{
    TypeOfCell curType;
    if(curPlayer != curPoint)
    {
        if(map_field[curPoint.y()][curPoint.x()]->getEvent())
            map_field[curPoint.y()][curPoint.x()]->getEvent()->trigger();

        curType = map_field[curPoint.y()][curPoint.x()]->getCell_type();

        if(curType == TARGET_BOX)
        {
            eventFactory->setCurrentType(CellEventFactory::COLOR_BOX, map_field[curPoint.y()][curPoint.x()]);
            map_field[curPoint.y()][curPoint.x()]->setEvent(eventFactory->createEvent());
            eventMediator->notify(this, "removePoint");

        }
        else if(curType == TARGET_WITH_BOX)
        {
            eventFactory->setCurrentType(CellEventFactory::RETURN_COLOR, map_field[curPoint.y()][curPoint.x()]);
            map_field[curPoint.y()][curPoint.x()]->setEvent(eventFactory->createEvent());
            eventMediator->notify(this, "addPoint");            
        }
    }
    else
    {
        curType = map_field[curPlayer.y()][curPlayer.x()]->getCell_type();
        if(curType == END_CELL)
            eventMediator->notify(this, "destroyPlayer");
    }
    return curType;
}

void Field::sendCignal(int type)
{
    map_field[hidDoor.y()][hidDoor.x()]->getEvent()->trigger();
    isHidDoorOpen = true;
}

void Field::setMap(std::vector<std::vector<CellSpace::TypeOfCell> > &arr)
{
    map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));
    for(int y = 0; y < map_height; y++)
        for(int x = 0; x < map_width; x++)
        {
            map_field[y][x] = new CellSpace::Cell(arr[y][x],
                              (arr[y][x] == CellSpace::WALL or arr[y][x] == CellSpace::TEMP_WALL) ? false : true);
            if(arr[y][x] == CellSpace::TARGET_BOX)
            {
                eventFactory->setCurrentType(CellEventFactory::COLOR_BOX, map_field[y][x]);
                map_field[y][x]->setEvent(eventFactory->createEvent());
            }
            else if(arr[y][x] == CellSpace::TEMP_WALL)
            {
                eventFactory->setCurrentType(CellEventFactory::HIDDEN_DOOR, map_field[y][x]);
                map_field[y][x]->setEvent(eventFactory->createEvent());
                hidDoor.setX(x);
                hidDoor.setY(y);
            }
        }
}

int Field::getFirstAttribute() const
{
    return curPoint.x();
}

int Field::getSecondAttribute() const
{
    return curPoint.y();
}

void Field::setFirstAttribute(int newAttribute)
{
    curPoint.setX(newAttribute);
}

void Field::setSecondAttribute(int newAttribute)
{
    curPoint.setY(newAttribute);
}

int Field::callAnObject()
{
    curPlayer.setX(curPoint.x());
    curPlayer.setY(curPoint.y());
    if(hidDoor.x() != 0 and hidDoor.y() != 0 and !isHidDoorOpen)
        eventMediator->notify(this, "OpenDoorCondition");
    return map_field[hidDoor.y()][hidDoor.x()]->getCell_type();
}

bool Field::checkState()
{
    bool var = map_field[curPoint.y()][curPoint.x()]->getIsPassable();
    if(!var)
        notifySubscribers("object : impassable cell", "warning");
    return var;
}

