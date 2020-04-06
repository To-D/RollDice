#include "Player.h"
#include <assert.h>

void Player::setDiceNum(int diceNum,int index){
    assert(diceNum >0 && diceNum < 7);
    assert(index >-1  && index < cap);
    this->diceNum[index] = diceNum;
}

void Player::setResult(int result){
    assert(result > -1 && result < 6);
    this->result = result;
}

int Player::getDiceNum(int index){
    assert(index >-1  && index < cap);
    return this->diceNum[index];
}

int Player::getResult(){
    return this->result;
}