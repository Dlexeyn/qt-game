#ifndef FIELD_H
#define FIELD_H

#include <vector>

#include "Cell.h"
#include "Ivents/CellEventFactory.h"
#include "map/ReadData.h"
#include "log/LogObject.h"
#include "map/objects/Player.h"
#include "map/objects/Box.h"
using namespace CellSpace;
class Field: public LogObject
{
public:
    Field(ReadData *readData, const std::vector<EventSubscriber *> &loggers);

    Field(const Field& otherfield);

    Field(Field&& field);

    Field &operator=(const Field &other);

    Field &operator=(Field &&other);

    ~Field();

    void movement(int stepX, int stepY);

    void setMap(std::vector<std::vector<CellSpace::TypeOfCell>> &arr);

    Player *getPlayer() const;

private:

    std::vector<std::vector<CellSpace::Cell*>> map_field;
    CellEventFactory *eventFactory = nullptr;
    int map_height, map_width;          // size in cells
    int step;                           // in px

    Player *player = nullptr;
    std::vector<Box*> BoxList;

    Box *isBox(int x, int y);
    bool boxMovement(Box *box, int &stepX, int &stepY);
    bool checkCell(int x, int y);
    void changeEvent(Cell *cell, CellEventType type);
    void changePlayer(Cell *cell);

    int condition;
    QPoint *hidDoor = nullptr;
    friend class FieldView;
};
#endif // FIELD_H
