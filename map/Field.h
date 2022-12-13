#ifndef FIELD_H
#define FIELD_H


#include <vector>
#include "Cell.h"
#include "Ivents/CellEventFactory.h"
#include "log/LogObject.h"
#include "map/Memento/Originator.hpp"
#include "map/objects/Player.h"
#include "map/objects/Box.h"

using namespace CellSpace;
namespace map {

enum class level{
    FIRST = 1,
    SECOND = 2
};

class Field: public LogObject, public Originator
{
public:
    Field() {}

    Field(const Field& otherfield);

    Field(Field&& field);

    Field &operator=(const Field &other);

    Field &operator=(Field &&other);

    ~Field();

    Memento *save();
    void restore(Memento* memento);

    void updateMap();

    void subscribeInto(const std::vector<EventSubscriber*> &arr);

    void movement(int stepX, int stepY);

    Player *getPlayer() const;

    void setPlayer(Player *newPlayer);

    int getMap_height() const;
    void setMap_height(int newMap_height);

    int getMap_width() const;
    void setMap_width(int newMap_width);


    void setMap_field(const std::vector<std::vector<CellSpace::Cell *> > &newMap_field);
    void setCellInField(int x, int y, Cell *cell);
    const std::vector<std::vector<CellSpace::Cell *> > &getMap_field() const;

    CellEventFactory *getEventFactory() const;

    void setHidDoor(QPoint *newHidDoor);

    void setBoxList(const std::vector<Box *> &newBoxList);
    void addBox(int index, Box *newBox);

    const std::vector<Box *> &getBoxList() const;

    void setEventFactory(CellEventFactory *newEventFactory);

    int getVictory() const;
    void setVictory(int newVictory);

    void setCondition(int newCondition);

    bool getIsGenerated() const;
    void setIsGenerated(bool newIsGenerated);


private:

    std::vector<std::vector<CellSpace::Cell*>> map_field;
    CellEventFactory *eventFactory = nullptr;
    int map_height, map_width;          // size in cells

    //int step;                           // in px

    Player *player = nullptr;
    std::vector<Box*> BoxList;

    Box *isBox(int x, int y);
    bool boxMovement(Box *box, int &stepX, int &stepY);
    bool checkCell(int x, int y);
    void changeEvent(Cell *cell, CellEventType type);
    void changePlayer(Cell *cell);

    int condition;
    int victory;

    QPoint *hidDoor = nullptr;
    bool isGenerated = true;

};

}

#endif // FIELD_H
