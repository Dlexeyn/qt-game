#include "Player.h"

Player::Player()
{
    this->maxHealth = 100;
    this->curHealth = 100;
    this->victoryPoints = 0;
    isAlive = true;
}

Player::Player(const Player &other)
{
    maxHealth = other.maxHealth;
    curHealth = other.curHealth;
    victoryPoints = other.victoryPoints;
    isAlive = other.isAlive;
    pos = other.pos;
}

Player::Player(int maxH, int curH, int points, int x, int y)
    : maxHealth(maxH), curHealth(curH), victoryPoints(points)
{
    pos.setX(x);
    pos.setY(y);
}

const int &Player::getVictoryPoints() const
{
    return victoryPoints;
}

const unsigned &Player::getCurHealth() const
{
    return curHealth;
}

void Player::setCurHealth(const unsigned &newCurHealth)
{
    curHealth = newCurHealth;
}

unsigned int Player::getMaxHealth() const
{
    return maxHealth;
}



