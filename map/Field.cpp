#include "Field.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Ivents/CellEventFactory.h"


Field::Field(ReadData *readData, const std::vector<EventSubscriber *> &loggers)
    : map_height(readData->getHeight()),
      map_width(readData->getWidth()),
      condition(readData->getConditionHiddenDoors())
{
    // init player ==============================================================
    player = new Player();
    player->subscribe(loggers);
    notifySubscribers("Player : the player was created ", "object");
    player->setPos(readData->getPlayerXY()->x(), readData->getPlayerXY()->y());
    //===========================================================================

    // intit Boxes ==============================================================
    BoxList = std::vector<Box*>(readData->getNumBox(), nullptr);
    for(int index = 0; index < readData->getNumBox(); index++)
    {
        BoxList[index] = new Box(false);
        BoxList[index]->subscribe(loggers);
        BoxList[index]->setPos(readData->getBoxXY().at(index)->x(),
                              readData->getBoxXY().at(index)->y());
    }
    notifySubscribers("Boxes : Boxes were created ", "object");
    //===========================================================================

    // map ======================================================================
    eventFactory = new CellEventFactory(COLOR_BOX, loggers, player);
    setMap(readData->getType_map());
    //===========================================================================

    // logs =====================================================================
    subscribe(loggers);
    notifySubscribers("Field : the field was created with size ", "object",
                      new LogArgs(ArgsLog::SIZE_WH, map_width, map_height));
    //===========================================================================
}

Field::~Field()
{
    map_field.clear();
    std::vector< std::vector< Cell* > >( map_field ).swap( map_field );
    delete eventFactory;
}

void Field::movement(int stepX, int stepY)
{
    int x = player->getPos(true), y = player->getPos(false);
    // проверка на проходимость клетки --------------------------------------
    if(!checkCell(x + stepX, y + stepY))
        return;
    //-----------------------------------------------------------------------

    // Движение коробки -----------------------------------------------------
    if(!boxMovement(isBox(x + stepX,
                          y + stepY),
                          stepX, stepY))
        return;
    //-----------------------------------------------------------------------

    // Движение игрока ------------------------------------------------------
    player->setPos(x + stepX, y + stepY);
    emit player->changePosSignal(stepX, stepY);
    changePlayer(map_field[y + stepY][x + stepX]);
    //-----------------------------------------------------------------------

    if(player->getVictoryPoints() == condition and hidDoor)
        map_field[hidDoor->y()][hidDoor->x()]->getEvent()->trigger();
}



//Field::Field(const Field &field) : map_height(field.map_height), map_width(field.map_width) {
//    std::copy(field.map_field.begin(), field.map_field.end(), std::back_inserter(map_field));
//    field.setPlayer(new Player(*player));
//    hidDoor = field.hidDoor;
//    eventFactory = new CellEventFactory(*field.eventFactory);
//}

//Field::Field(Field &&field) : map_height(field.map_height), map_width(field.map_width) {
//    map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));
//    for(int y = 0; y < map_height; y++)
//        for(int x = 0; x < map_width; x++)
//            std::swap(map_field[x][y], field.map_field[x][y]);
//    std::swap(curPlayer, field.curPlayer);
//    std::swap(curPlayer, field.curPlayer);
//    std::swap(curPlayer, field.curPlayer);
//    std::swap(eventFactory, field.eventFactory);
//}


void Field::setMap(std::vector<std::vector<CellSpace::TypeOfCell> > &arr)
{
    map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));
    for(int y = 0; y < map_height; y++)
        for(int x = 0; x < map_width; x++)
        {
            map_field[y][x] = new CellSpace::Cell(arr[y][x],
                              (arr[y][x] == CellSpace::WALL or arr[y][x] == CellSpace::TEMP_WALL) ? false : true);
            switch (arr[y][x]) {
            case CellSpace::TARGET_BOX:
                eventFactory->setCurrentType(COLOR_BOX, map_field[y][x]);
                break;
            case CellSpace::TEMP_WALL:
                hidDoor = new QPoint(x, y);
                eventFactory->setCurrentType(HIDDEN_DOOR, map_field[y][x]);
                break;
            case CellSpace::END_CELL:
                eventFactory->setCurrentType(DESTROY_PLAYER, map_field[y][x]);
                break;
            default:
                break;
            }
            if(arr[y][x] != WALL and arr[y][x] != GRASS)
                map_field[y][x]->setEvent(eventFactory->createEvent());
        }
}

Player *Field::getPlayer() const
{
    return player;
}

Box *Field::isBox(int x, int y)
{
    for(std::vector<Box>::size_type index = 0; index < BoxList.size(); index++)
    {
        if(BoxList[index]->getPos(true) == x and
           BoxList[index]->getPos(false) == y)
            return BoxList[index];
    }
    return nullptr;
}

bool Field::boxMovement(Box *box, int &stepX, int &stepY)
{
    // Коробки на пути нет -------------------------------------------
    if(!box)
        return true;
    //----------------------------------------------------------------

    int x = box->getPos(true), y = box->getPos(false);

    // Две коробки на пути -------------------------------------------
    if(isBox(x + stepX, y + stepY))
    {
        notifySubscribers("box : other box is on the way", "warning");
        return false;
    }
    //----------------------------------------------------------------

    // Проходимость за коробкой
    if(!checkCell(x + stepX, y + stepY))
        return false;
    //----------------------------------------------------------------

    // Движение коробки
    box->setPos(x + stepX, y + stepY);
    changeEvent(map_field[y + stepY][x + stepX], RETURN_COLOR);
    changeEvent(map_field[y][x], COLOR_BOX);
    emit box->changePosSignal(stepX, stepY);
    return true;
    //----------------------------------------------------------------

}

bool Field::checkCell(int x, int y)
{
    bool var = map_field[y][x]->getIsPassable();
    if(!var)
        notifySubscribers("object : impassable cell", "warning");
    return var;
}

void Field::changeEvent(Cell *cell, CellEventType type)
{
    if(!cell->getEvent())
        return;
    cell->getEvent()->trigger();
    eventFactory->setCurrentType(type, cell);
    cell->setEvent(eventFactory->createEvent());
}

void Field::changePlayer(Cell *cell)
{
    TypeOfCell type = cell->getCell_type();
    if(type == CellSpace::END_CELL)
        cell->getEvent()->trigger();
}



