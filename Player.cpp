
#include "Player.h"

Player::Player(const std::string& name, int maxHP, int force){
    this->m_name = std::string(name);
    this->m_maxHP = maxHP;
    this->m_HP = maxHP;
    this->m_force = force;
    this->m_level = NEW_PLAYER_LEVEL;
    this->m_coins = MIN_COINS;
}

Player::Player(const Player& player){
    this->m_name =  std::string(player.m_name);
    this->m_maxHP = player.m_maxHP;
    this->m_HP = player.m_maxHP;
    this->m_force = player.m_force;
    this->m_level = NEW_PLAYER_LEVEL;
    this->m_coins = MIN_COINS;
}

Player& Player::operator=(const Player& player){
    if (this == &player){
        return *this;
    }
    this->m_name = std::string(player.m_name);
    this->m_HP = player.m_HP;
    this->m_level = player.m_level;
    this->m_coins = player.m_coins;
    this->m_force = player.m_force;
    this->m_maxHP = player.m_maxHP;
    return *this;
}
/*
 * setters methods:
 * sets the value of the object, using the given parameter.
 */
void Player::setLevel(int level){
    this->m_level = level;
}
void Player::setForce(int force){
    this->m_force = force;
}
void Player::setMaxHP(int maxHP){
    this->m_maxHP = maxHP;
}
void Player::setCoins(int coins){
    this->m_coins = coins;
}

int Player::getHP() const{
    return this->m_HP;
}
void Player::printInfo() const{
    char* cTypeStringName = new char[this->m_name.length()+1];
    std::strcpy(cTypeStringName,this->m_name.c_str());
    printPlayerInfo(cTypeStringName, this->m_level, this->m_force, this->m_HP, this->m_coins);
}

bool Player::levelUp(){
    if (this->m_level < MAX_LEVEL){
        this->m_level++;
        return true;
    }
    return false;
}

int Player::getLevel() const{
    return this->m_level;
}

void Player::buff(int buffPoints){
    this->m_force += buffPoints;
}

void Player::heal(int healPoints){
    if (healPoints < 0){
        return;
    }
    this->m_HP = (this->m_HP + healPoints > this->m_maxHP) ? this->m_maxHP : this->m_HP + healPoints;
}


void Player::damage(int damage){
    this->m_HP = (this->m_HP > damage) ? this->m_HP - damage : MIN_HP;
}

bool Player::isKnockedOut() const{
    return (this->m_HP == MIN_HP);
}

void Player::addCoins(int coinsToAdd){
    this->m_coins += coinsToAdd;
}

bool Player::pay(int price){
    if (this->m_coins < price){
        return false;
    }
    this->m_coins -= price;
    return true;
}

int Player::getAttackStrength() const{
    return this->m_level + this->m_force;
}

