#ifndef PLAYER_H
#define PLAYER_H

#include "map/MapObject.h"
#include "map/MapComponent.h"

class Player: public MapComponent
{
public:
    enum signalType{
        DESTROYING = 1,
        POINTS_FOR_DOOR = 3
    };

    Player(const std::vector<EventSubscriber *> &loggers);

    Player(const Player& other);

    void sendCignal();

    int changeStatus();

    int getAttribute(ObjectAttribute at) const;

    void setAttribute(ObjectAttribute at, int arg);

    void setIsAlive(bool newIsAlive);

    bool getIsAlive() const;

    void callAnObject();

    bool checkState();

private:
    unsigned maxHealth;
    unsigned curHealth;
    unsigned victoryPoints;
    bool isAlive;
};

#endif // PLAYER_H
