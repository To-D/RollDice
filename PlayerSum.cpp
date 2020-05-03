/**
 * @class SumPlayer
 * @author Liu Junwei
 * @brief This class is the abstraction of the player using "sum-deviding" strategy in DiceRolling
 */ 
#include "PlayerSum.h"
#include <iostream>

// Constructor
PlayerSum::PlayerSum(string name){
    this -> name = name;
};

// Destuctor
PlayerSum::~PlayerSum(){};

// The player1's way of calculating the result
void PlayerSum::calculateRes(){
    this->result = (diceNum[0]+diceNum[1])%6;
}
