#include "Player.h"

Player::Player(unsigned maxHealth)
{
    this->maxHealth = maxHealth;
    this->curHealth = maxHealth;
    this->victoryPoints = 0;
    isAlive = true;
}

void Player::sendCignal(int type)
{

}

//Player::Player(const Player &other)
//{
//    maxHealth = other.maxHealth;
//    curHealth = other.maxHealth;
//    timeReload = other.timeReload;
//    maxAmmunition = other.maxAmmunition;
//    curAmmunition = other.maxAmmunition;
//    curExp = other.curExp;
//}

void Player::changeStatus()
{
    isAlive = false;
}

void Player::takeDamage(int damage)
{
    curHealth -= damage;
    if(curHealth <= 0)
        destruction();
}

void Player::regenHealth(int addHealth)
{
    if(curHealth != maxHealth)
    {
        curHealth += addHealth;
        if(curHealth > maxHealth)
            curHealth = maxHealth;
    }
}

const unsigned &Player::getCurHealth() const
{
    return curHealth;
}

void Player::addVictoryPoint()
{
    victoryPoints++;
}

void Player::deleteVictoryPoint()
{
    victoryPoints--;
}

const unsigned &Player::getVictoryPoints() const
{
    return victoryPoints;
}

void Player::setIsAlive(bool newIsAlive)
{
    isAlive = newIsAlive;
}

bool Player::getIsAlive() const
{
    return isAlive;
}

void Player::destruction()
{

}
