#ifndef PLAYER_H
#define PLAYER_H

#include "map/MapObject.h"

class Player: public MapObject
{
public:
    Player(unsigned maxHealth = 100, unsigned maxAmmunition = 10, unsigned timeReload = 5);

    Player(const Player& other);

    void changeStatus();

    void takeDamage(int damage);
    void strike();
    void destruction();
    void regenHealth(int addHealth);

    const unsigned &getCurHealth() const;

private:
        unsigned maxHealth, maxAmmunition, timeReload;
        unsigned curHealth, curExp, curAmmunition;
};

#endif // PLAYER_H
