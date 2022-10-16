#ifndef PLAYER_H
#define PLAYER_H

#include "map/MapObject.h"
#include "map/MapComponent.h"
#include "game/Mediator.h"

class Player: public MapComponent
{
public:
    Player(unsigned maxHealth = 100);

    Player(const Player& other);

    void sendCignal(int type);

    void changeStatus();

    int getFirstAttribute() const;
    int getSecondAttribute() const;

    void setFirstAttribute(int newAttribute);
    void setSecondAttribute(int newAttribute);

    void takeDamage(int damage);
    void destruction();
    void regenHealth(int addHealth);

    const unsigned &getCurHealth() const;

    void addVictoryPoint();
    void deleteVictoryPoint();
    const unsigned &getVictoryPoints() const;

    void setIsAlive(bool newIsAlive);

    bool getIsAlive() const;

private:
        unsigned maxHealth;
        unsigned curHealth;
        unsigned victoryPoints;
        bool isAlive;
};

#endif // PLAYER_H
