#include "Player.h"

Player::Player(unsigned maxHealth, unsigned maxAmmunition, unsigned timeReload)
{
    this->maxHealth = maxHealth;
    this->curHealth = maxHealth;
    this->timeReload = timeReload;
    this->maxAmmunition = maxAmmunition;
    this->curAmmunition = maxAmmunition;
    this->curExp = 0;
}

Player::Player(const Player &other)
{
    maxHealth = other.maxHealth;
    curHealth = other.maxHealth;
    timeReload = other.timeReload;
    maxAmmunition = other.maxAmmunition;
    curAmmunition = other.maxAmmunition;
    curExp = other.curExp;
}

void Player::changeStatus()
{

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

void Player::destruction()
{

}
