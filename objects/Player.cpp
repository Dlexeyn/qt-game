#include "Player.h"

Player::Player(const std::vector<EventSubscriber *> &loggers)
{
    this->maxHealth = 100;
    this->curHealth = 100;
    this->victoryPoints = 0;
    isAlive = true;
    subscribe(loggers);
    notifySubscribers("Player : the player was created", "object");
}

Player::Player(const Player &other)
{
    maxHealth = other.maxHealth;
    curHealth = other.curHealth;
    victoryPoints = other.victoryPoints;
    isAlive = other.isAlive;
}

void Player::sendCignal()
{

}


int Player::changeStatus()
{
    isAlive = false;
    return isAlive;
}

int Player::getAttribute(ObjectAttribute at) const
{
    switch (at) {
    case ObjectAttribute::HEALTH:
        return curHealth;
    case ObjectAttribute::POINTS:
        return victoryPoints;
    default:
        return 0;
    }
}

void Player::setAttribute(ObjectAttribute at, int arg)
{
    switch (at) {
    case ObjectAttribute::HEALTH:
        curHealth = arg;
        break;
    case ObjectAttribute::POINTS:
        victoryPoints = arg;
        break;
    default:
        break;
    }
}

void Player::setIsAlive(bool newIsAlive)
{
    isAlive = newIsAlive;
}

bool Player::getIsAlive() const
{
    return isAlive;
}

void Player::callAnObject()
{
}

bool Player::checkState()
{
    return isAlive;
}

