#include "Field.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>


Field::Field(unsigned map_height, unsigned map_width)
{
    map_field = std::vector<std::vector<Cell*>>(map_height, std::vector<Cell*>(map_width, nullptr));
    for(unsigned y = 0; y < map_height; y++)
        for(unsigned x = 0; x < map_width; x++)
            map_field[y][x] = new Cell(Cell::TypeOfCell::GRASS, true);

    for(unsigned x = 0; x < map_width/3; x++)
    {
        delete map_field[9][x];
        map_field[9][x] = new Cell(Cell::TypeOfCell::WALL, false);
    }

    for(unsigned x = map_width-1; x >= 4; x--)
    {
        delete map_field[4][x];
        map_field[4][x] = new Cell(Cell::TypeOfCell::WALL, false);
    }


    for(unsigned y = 0; y < map_height-3; y+=4)
        for(unsigned x = 2; x < map_width/3; x+=2)
        {
            delete map_field[y][x];
            map_field[y][x] = new Cell(Cell::TypeOfCell::TRAP, true);
        }

    player = new Player();
}

void Field::changeStatus()
{

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

Cell *Field::getCell(unsigned yIndex, unsigned xIndex)
{
    return map_field[yIndex][xIndex];
}

Cell::TypeOfCell Field::getCellType(unsigned yIndex, unsigned xIndex)
{
    return map_field[yIndex][xIndex]->getCell_type();
}

bool Field::getPassability(unsigned yIndex, unsigned xIndex)
{
    return map_field[yIndex][xIndex]->getIsPassable();
}

Player *Field::getPlayer() const
{
    return player;
}
