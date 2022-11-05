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
    if(map_field[curPoint.y()][curPoint.x()]->getEvent())
        map_field[curPoint.y()][curPoint.x()]->getEvent()->trigger();

    curType = map_field[curPoint.y()][curPoint.x()]->getCell_type();

    if(curType == TARGET_BOX)
    {
        eventFactory->setCurrentType(CellEventFactory::COLOR_BOX, map_field[curPoint.y()][curPoint.x()]);
        map_field[curPoint.y()][curPoint.x()]->setEvent(eventFactory->createEvent());
        eventMediator->notify("removePoint");

    }
    else if(curType == TARGET_WITH_BOX)
    {
        eventFactory->setCurrentType(CellEventFactory::RETURN_COLOR, map_field[curPoint.y()][curPoint.x()]);
        map_field[curPoint.y()][curPoint.x()]->setEvent(eventFactory->createEvent());
        eventMediator->notify("addPoint");
    }
    return curType;
}

void Field::sendCignal()
{
    int y = hidDoor.y(), x = hidDoor.x();
    eventFactory->setCurrentType(CellEventFactory::HIDDEN_DOOR, map_field[y][x]);
    map_field[y][x]->setEvent(eventFactory->createEvent());

    map_field[y][x]->getEvent()->trigger();
    map_field[hidDoor.y()][hidDoor.x()]->clearEvent();
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
                hidDoor.setX(x);
                hidDoor.setY(y);
            }
        }
}

int Field::getAttribute(ObjectAttribute at) const
{
    switch (at) {
    case ObjectAttribute::OBJECT:
        return int(cur);
    case ObjectAttribute::CUR_X:
        return curPoint.x();
    case ObjectAttribute::CUR_Y:
        return curPoint.y();
    default:
        return 0;
    }
}

void Field::setAttribute(ObjectAttribute at, int arg)
{
    switch (at) {
    case ObjectAttribute::OBJECT:
        cur = Object(arg);
        break;
    case ObjectAttribute::CUR_X:
        curPoint.setX(arg);
        break;
    case ObjectAttribute::CUR_Y:
        curPoint.setY(arg);
        break;
    default:
        break;
    }
}

void Field::callAnObject()
{
    TypeOfCell curType = map_field[curPoint.y()][curPoint.x()]->getCell_type();
    switch (cur) {
    case Object::BOX:
        break;
    case Object::PLAYER:
        if(curType == END_CELL)
                eventMediator->notify("destroyPlayer");
        break;
    }
}

bool Field::checkState()
{
    bool var = map_field[curPoint.y()][curPoint.x()]->getIsPassable();
    if(!var)
        notifySubscribers("object : impassable cell", "warning");
    return var;
}


