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



