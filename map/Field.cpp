#include "Field.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Ivents/ObjectEventFactory.h"


Field::Field(unsigned map_height, unsigned map_width, const std::vector<std::vector<CellSpace::TypeOfCell> > &arr, int numBox)
{
    map_field = std::vector<std::vector<CellSpace::Cell*>>(map_height, std::vector<CellSpace::Cell*>(map_width, nullptr));
    this->map_height = map_height;
    this->map_width = map_width;
    eventFactory = new ObjectEventFactory(ObjectEventFactory::COLOR_BOX);
    setMap(arr);
    setBoxList(numBox);
    delete eventFactory;
    eventFactory = nullptr;
}

//Field::Field(const Field &field) : map_height(field.map_height), map_width(field.map_width) {
//    map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));

//    for(int y = 0; y < map_height; y++)
//        for(int x = 0; x < map_width; x++)
//        {
//            map_field[y][x] = new Cell(Cell::TypeOfCell::GRASS, true);
//            *map_field[y][x] = *field.map_field[y][x];
//        }
//    player = field.player;
//}

//Field::Field(Field &&field) : map_height(field.map_height), map_width(field.map_width) {
//    map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));

//    for(int y = 0; y < map_height; y++)
//        for(int x = 0; x < map_width; x++)
//            std::swap(map_field[x][y], field.map_field[x][y]);

//    std::swap(player, field.player);
//}

//Field &Field::operator=(Field &&other)
//{
//    if(this != &other)
//    {
//        for(int y = 0; y < map_height; y++)
//            for(int x = 0; x < map_width; x++)
//                delete map_field[y][x];
//    }
//    map_height = other.map_height;
//    map_width = other.map_width;
//    player = other.player;

//    map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));
//    for(int y = 0; y < map_height; y++)
//        for(int x = 0; x < map_width; x++)
//            std::swap(map_field[y][x], other.map_field[y][x]);

//    return *this;
//}

//Field &Field::operator=(const Field &other)
//{
//    if(this != &other)
//    {
//        for(int y = 0; y < map_height; y++)
//            for(int x = 0; x < map_width; x++)
//                delete map_field[y][x];
//    }
//    map_height = other.map_height;
//    map_width = other.map_width;
//    player = other.player;

//    map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));
//    for(int y = 0; y < map_height; y++)
//        for(int x = 0; x < map_width; x++)
//        {
//            map_field[y][x] = new Cell(Cell::TypeOfCell::GRASS, true);
//            *map_field[y][x] = *other.map_field[y][x];
//        }
//    return *this;
//}

void Field::changeStatus()
{

}

void Field::sendCignal(int type)
{

}

void Field::setEventMediator(Mediator *newEventMediator)
{
    eventMediator = newEventMediator;
    for(int y = 0; y < map_height; y++)
        for(int x = 0; x < map_width; x++)
            map_field[y][x]->setEventMediator(newEventMediator);
    for(auto box : list_box)
        box->setEventMediator(newEventMediator);
}

void Field::setMap(const std::vector<std::vector<CellSpace::TypeOfCell>> &arr)
{
    for(int y = 0; y < map_height; y++)
        for(int x = 0; x < map_width; x++)
        {
            map_field[y][x] = new CellSpace::Cell(arr[y][x],(arr[y][x] == CellSpace::WALL) ? false : true);
            if(arr[y][x] == CellSpace::TARGET_BOX)
                eventFactory->setCurrentType(ObjectEventFactory::COLOR_BOX, map_field[y][x]);
            if(arr[y][x] == CellSpace::TEMP_WALL)
                eventFactory->setCurrentType(ObjectEventFactory::HIDDEN_DOOR, map_field[y][x]);
            map_field[y][x]->setEvent(eventFactory->createEvent());
        }
}

void Field::setBoxList(int num)
{
    list_box = std::vector<Box*>(num, nullptr);
    for(int index = 0; index < num; index++)
    {
        list_box[index] = new Box(false);
    }
}

int Field::getFirstAttribute() const
{
    return map_height;
}

int Field::getSecondAttribute() const
{
    return map_height;
}

void Field::setFirstAttribute(int newAttribute)
{
    map_height = newAttribute;
}

void Field::setSecondAttribute(int newAttribute)
{
    map_width = newAttribute;
}

const unsigned &Field::getMap_height() const
{
    return map_height;
}

void Field::setMap_height(const unsigned &newMap_height)
{
    map_height = newMap_height;
}

const unsigned &Field::getMap_width() const
{
    return map_width;
}

void Field::setMap_width(const unsigned &newMap_width)
{
    map_width = newMap_width;
}

CellSpace::Cell *Field::getCell(unsigned yIndex, unsigned xIndex)
{
    return map_field[yIndex][xIndex];
}

CellSpace::TypeOfCell Field::getCellType(unsigned yIndex, unsigned xIndex)
{
    return map_field[yIndex][xIndex]->getCell_type();
}

Box *Field::getBox(unsigned index)
{
    return list_box[index];
}

bool Field::getPassability(unsigned yIndex, unsigned xIndex)
{
    return map_field[yIndex][xIndex]->getIsPassable();
}

//Player *Field::getPlayer() const
//{
//    return player;
//}
