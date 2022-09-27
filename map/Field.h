#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include "Cell.h"
#include "objects/Player.h"
#include "MapObject.h"

class Field: public MapObject
{
public:
    enum CellSignals{
        PlayerOnCell,
        EnemyOnCell
        //...
    };

    Field(unsigned map_height, unsigned map_width);

    Field(const Field& field) : map_height(field.map_height), map_width(field.map_width) {
        map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));

        for(int y = 0; y < map_height; y++)
            for(int x = 0; x < map_width; x++)
            {
                map_field[y][x] = new Cell(Cell::TypeOfCell::GRASS, true);
                *map_field[y][x] = *field.map_field[y][x];
            }
        player = field.player;
    }

    Field(Field&& field) : map_height(field.map_height), map_width(field.map_width) {
        map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));

        for(int y = 0; y < map_height; y++)
            for(int x = 0; x < map_width; x++)
                std::swap(map_field[x][y], field.map_field[x][y]);

        std::swap(player, field.player);
    }

    Field& operator=(const Field &other)
    {
        if(this != &other)
        {
            for(int y = 0; y < map_height; y++)
                for(int x = 0; x < map_width; x++)
                    delete map_field[y][x];
        }
        map_height = other.map_height;
        map_width = other.map_width;
        player = other.player;

        map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));
        for(int y = 0; y < map_height; y++)
            for(int x = 0; x < map_width; x++)
            {
                map_field[y][x] = new Cell(Cell::TypeOfCell::GRASS, true);
                *map_field[y][x] = *other.map_field[y][x];
            }
        return *this;
    }

    Field& operator=(Field &&other)
    {
        if(this != &other)
        {
            for(int y = 0; y < map_height; y++)
                for(int x = 0; x < map_width; x++)
                    delete map_field[y][x];
        }
        map_height = other.map_height;
        map_width = other.map_width;
        player = other.player;

        map_field = std::vector<std::vector<Cell*>> (map_height, std::vector<Cell*>(map_width, nullptr));
        for(int y = 0; y < map_height; y++)
            for(int x = 0; x < map_width; x++)
                std::swap(map_field[y][x], other.map_field[y][x]);

        return *this;
    }

    void changeStatus();

    const unsigned &getMap_height() const;
    void setMap_height(const unsigned &newMap_height);

    const unsigned &getMap_width() const;
    void setMap_width(const unsigned &newMap_width);

    Cell* getCell(unsigned yIndex, unsigned xIndex);

    Cell::TypeOfCell getCellType(unsigned yIndex, unsigned xIndex);

    void signalForCell(CellSignals signal, unsigned xIndex, unsigned yIndex);

    bool getPassability(unsigned yIndex, unsigned xIndex);

    Player *getPlayer() const;

private:
    Player *player = nullptr;
    std::vector<std::vector<Cell*>> map_field;
    int map_height, map_width; // size in cells
};
#endif // FIELD_H
