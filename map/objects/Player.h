#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "log/LogObject.h"
#include "map/objects/Object.h"


class Player: public Object, public LogObject
{
public:
    Player();
    Player(const Player& other);
    Player(int maxH, int curH, int points, int x, int y);

    void addPoint() { victoryPoints++; }
    void removePoint() { victoryPoints--; }

    const int &getVictoryPoints() const;

    const unsigned &getCurHealth() const;

    void setCurHealth(const unsigned &newCurHealth);

    friend std::ostream& operator<<(std::ostream& out, const Player& obj){
        out << "PLAYER:\n";
        out << obj.maxHealth << "\n";
        out << obj.curHealth << "\n";
        out << obj.victoryPoints << "\n";
        out << obj.pos.x() << "\n";
        out << obj.pos.y() << "\n";
        return out;
    }

    unsigned int getMaxHealth() const;

private:
    unsigned maxHealth;
    unsigned curHealth;
    int victoryPoints;
    bool isAlive;
};

#endif // PLAYER_H
