#ifndef PLAYER_H
#define PLAYER_H

#include "log/LogObject.h"
#include "map/objects/Object.h"


class Player: public Object, public LogObject
{
public:
    Player();
    Player(const Player& other);

    void addPoint() { victoryPoints++; }
    void removePoint() { victoryPoints--; }

    const int &getVictoryPoints() const;

    const unsigned &getCurHealth() const;

    void setCurHealth(const unsigned &newCurHealth);

private:
    unsigned maxHealth;
    unsigned curHealth;
    int victoryPoints;
    bool isAlive;
};

#endif // PLAYER_H
