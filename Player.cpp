/**
 * @class Player
 * @author Liu Junwei
 * @brief The base class of every player, including some attributes and functions that are versatile
 *        and a vitual function as an interface of calculating certain player's result
 */ 
#include "Player.h"
#include <assert.h>

/**
 * @brief Set the diceNum array
 * @param diceNum - The number that will be added to the array
 * @param index - Point out where to place the number in the array
 */ 
void Player::setDiceNum(int diceNum,int index){
    assert(diceNum >0 && diceNum < 7);
    assert(index >-1  && index < cap);
    this->diceNum[index] = diceNum;
}

/**
 * @brief Get the diceNum according to the index
 * @param index - Point out where the number is.
 */ 
int Player::getDiceNum(int index){
    assert(index >-1  && index < cap);
    return this->diceNum[index];
}


int Player::getResult(){
    return this->result;
}

string Player::getName(){
    return this->name;
}

void Player::calculateRes(){}