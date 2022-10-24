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

void Player::sendCignal(int type)
{

}


int Player::changeStatus()
{
    isAlive = false;
    return isAlive;
}

int Player::getFirstAttribute() const
{
    return curHealth;
}

int Player::getSecondAttribute() const
{
    return victoryPoints;
}

void Player::setFirstAttribute(int newAttribute)
{
    curHealth = newAttribute;
}

void Player::setSecondAttribute(int newAttribute)
{
    victoryPoints = newAttribute;
}

void Player::setIsAlive(bool newIsAlive)
{
    isAlive = newIsAlive;
}

bool Player::getIsAlive() const
{
    return isAlive;
}

int Player::callAnObject()
{
    return 1;   // future
}

bool Player::checkState()
{
    return isAlive;
}

