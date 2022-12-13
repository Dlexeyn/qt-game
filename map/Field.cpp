#include "Field.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Ivents/CellEventFactory.h"
#include "map/Memento/Snapshot.h"

namespace map {

Field::~Field()
{
    map_field.clear();
    std::vector< std::vector< Cell* > >( map_field ).swap( map_field );
    delete eventFactory;
}

Memento *Field::save()
{
    return new Snapshot(map_field,
                        map_height,
                        map_width,
                        hidDoor,
                        *player,
                        BoxList,
                        condition,
                        victory);
}

void Field::restore(Memento *memento)
{
    auto rData = memento->GetState();
    map_height = rData["HEIGHT"][0];
    map_width = rData["WIDTH"][0];
    condition = rData["HIDDOR-CONDITION"][0];
    victory = rData["VICTORY-CONDITION"][0];

    player = new Player(rData["PLAYER-MAX-H"][0],
                        rData["PLAYER-CUR-H"][0],
                        rData["PLAYER-POINTS"][0],
                        rData["PLAYER-XY"][0],
                        rData["PLAYER-XY"][1]);

    hidDoor = new QPoint(rData["HIDDOR-XY"][0],
                         rData["HIDDOR-XY"][1]);

    if(hidDoor->rx() == 0 and hidDoor->ry() == 0)
    {
        delete hidDoor;
        hidDoor = nullptr;
    }

    int boxCount = rData["BOX-COUNT"][0];
    BoxList = std::vector<Box*>(boxCount, nullptr);
    for(int i = 0; i < boxCount; i++)
    {
        Box *cur = new Box(false);
        cur->setPos(rData["BOX_" + std::to_string(i)][0],
                    rData["BOX_" + std::to_string(i)][1]);
        BoxList[i] = cur;
    }

    map_field = std::vector<std::vector<Cell*>>
                (map_height, std::vector<Cell*>(map_width, nullptr));

    for(int y = 0; y < map_height; y++)
            for(int x = 0; x < map_width; x++)
            {
                TypeOfCell type = TypeOfCell(rData["MAP_" + std::to_string(y)][x]);
                bool var = (type == TypeOfCell::WALL or type == TypeOfCell::TEMP_WALL)
                        ? false : true;
                Cell *cell = new Cell(type, var);
                map_field[y][x] = cell;
            }

    updateMap();
}

void Field::updateMap()
{
    eventFactory = new CellEventFactory(CellEventType::COLOR_BOX, loggers, player);

    for(int y = 0; y < map_height; y++)
        for(int x = 0; x < map_width; x++)
        {
            Cell *cell = map_field[y][x];
            switch (cell->getCell_type()) {
            case CellSpace::TEMP_WALL:
                eventFactory->setCurrentType(CellEventType::HIDDEN_DOOR, cell);
                cell->setEvent(eventFactory->createEvent());
                break;
            case CellSpace::TARGET_BOX:
                eventFactory->setCurrentType(CellEventType::COLOR_BOX, cell);
                cell->setEvent(eventFactory->createEvent());
                break;
            case CellSpace::TARGET_WITH_BOX:
                eventFactory->setCurrentType(CellEventType::RETURN_COLOR, cell);
                cell->setEvent(eventFactory->createEvent());
                break;
            case CellSpace::END_CELL:
                eventFactory->setCurrentType(CellEventType::DESTROY_PLAYER, cell);
                cell->setEvent(eventFactory->createEvent());
                break;
            default:
                break;
            }
        }
}

void Field::subscribeInto(const std::vector<EventSubscriber *> &arr)
{
    subscribe(arr);
    player->subscribe(arr);
    for(auto box : BoxList)
        box->subscribe(arr);

    notifySubscribers("Field : the field was created with size ", "object",
                      new LogArgs(ArgsLog::SIZE_WH, map_width, map_height));

    notifySubscribers("Boxes : Boxes were created ", "object");

    notifySubscribers("Player : the player was created ", "object");
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
    notifySubscribers("Player changed position to ", "object",
                       new LogArgs(ArgsLog::XY, player->getPos(true), player->getPos(false)));
    changePlayer(map_field[y + stepY][x + stepX]);
    //-----------------------------------------------------------------------

    if(player->getVictoryPoints() >= condition and hidDoor)
    {
        map_field[hidDoor->y()][hidDoor->x()]->getEvent()->trigger();
        delete hidDoor;
        hidDoor = nullptr;
    }
}



Field::Field(const Field &field) : map_height(field.map_height), map_width(field.map_width) {
    std::copy(field.map_field.begin(), field.map_field.end(), std::back_inserter(map_field));

    BoxList = std::vector<Box*>(field.getBoxList().size(), nullptr);
    for(size_t index = 0; index < field.getBoxList().size(); index++)
        BoxList[index] = field.getBoxList().at(index);

    player = field.player;

    hidDoor = field.hidDoor;

    eventFactory = new CellEventFactory(*field.getEventFactory());

    condition = field.condition;
    victory = field.victory;
    isGenerated = field.isGenerated;
}

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

Player *Field::getPlayer() const
{
    return player;
}

void Field::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}

int Field::getMap_height() const
{
    return map_height;
}

void Field::setMap_height(int newMap_height)
{
    map_height = newMap_height;
}

int Field::getMap_width() const
{
    return map_width;
}

void Field::setMap_width(int newMap_width)
{
    map_width = newMap_width;
}

void Field::setMap_field(const std::vector<std::vector<CellSpace::Cell *> > &newMap_field)
{
    map_field = newMap_field;
}

void Field::setCellInField(int x, int y, Cell *cell)
{
    map_field[y][x] = cell;
}

const std::vector<std::vector<CellSpace::Cell *> > &Field::getMap_field() const
{
    return map_field;
}

CellEventFactory *Field::getEventFactory() const
{
    return eventFactory;
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

bool Field::getIsGenerated() const
{
    return isGenerated;
}

void Field::setIsGenerated(bool newIsGenerated)
{
    isGenerated = newIsGenerated;
}


void Field::setCondition(int newCondition)
{
    condition = newCondition;
}

int Field::getVictory() const
{
    return victory;
}

void Field::setVictory(int newVictory)
{
    victory = newVictory;
}

void Field::setHidDoor(QPoint *newHidDoor)
{
    hidDoor = newHidDoor;
}

void Field::setBoxList(const std::vector<Box *> &newBoxList)
{
    BoxList = newBoxList;
}

void Field::addBox(int index, Box *newBox)
{
    BoxList[index] = newBox;
}

const std::vector<Box *> &Field::getBoxList() const
{
    return BoxList;
}


void Field::setEventFactory(CellEventFactory *newEventFactory)
{
    eventFactory = newEventFactory;
}

}
