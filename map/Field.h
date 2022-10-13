#ifndef FIELD_H
#define FIELD_H

#include <vector>

#include "Cell.h"
#include "Box.h"
#include "objects/Player.h"

#include "MapObject.h"
#include "map/MapComponent.h"
#include "game/Mediator.h"

class Field: public MapComponent
{
public:

    Field(unsigned map_height, unsigned map_width,
          const std::vector<std::vector<CellSpace::TypeOfCell>> & arr, int numBox);

    Field(const Field& field);

    Field(Field&& field);

    Field &operator=(const Field &other);

    Field &operator=(Field &&other);

    void changeStatus(); //

    void sendCignal(int type);

    void setMediator(Mediator *mediator);

    void setMap(const std::vector<std::vector<CellSpace::TypeOfCell> > &arr);

    void setBoxList(int num);

    const unsigned &getMap_height() const;
    void setMap_height(const unsigned &newMap_height);

    const unsigned &getMap_width() const;
    void setMap_width(const unsigned &newMap_width);

    CellSpace::Cell *getCell(unsigned yIndex, unsigned xIndex);

    CellSpace::TypeOfCell getCellType(unsigned yIndex, unsigned xIndex);

    Box *getBox(unsigned index);

    bool getPassability(unsigned yIndex, unsigned xIndex);

    //Player *getPlayer() const;

private:
    Player *player = nullptr;
    std::vector<std::vector<CellSpace::Cell*>> map_field;
    std::vector<Box*> list_box;
    int map_height, map_width; // size in cells
};
#endif // FIELD_H
