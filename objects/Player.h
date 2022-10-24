#ifndef PLAYER_H
#define PLAYER_H

#include "map/MapObject.h"
#include "map/MapComponent.h"
#include "game/Mediator.h"

class Player: public MapComponent
{
public:
    enum signalType{
        DESTROYING = 1,
        POINTS_FOR_DOOR = 3
    };

    Player();

    Player(const Player& other);

    void sendCignal(int type);

    int changeStatus();

    int getFirstAttribute() const;
    int getSecondAttribute() const;

    void setFirstAttribute(int newAttribute);
    void setSecondAttribute(int newAttribute);

    void setIsAlive(bool newIsAlive);

    bool getIsAlive() const;

    int callAnObject();

    bool checkState();

private:
        unsigned maxHealth;
        unsigned curHealth;
        unsigned victoryPoints;
        bool isAlive;
};

#endif // PLAYER_H
