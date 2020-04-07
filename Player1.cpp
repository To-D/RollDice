/**
 * @class Player1
 * @author Liu Junwei
 * @brief This class is the abstraction of the first player
 */ 
#include "Player1.h"
#include <iostream>

// Constructor
Player1::Player1(){
    this -> name = "Player1";
};

// Destuctor
Player1::~Player1(){};

// The player1's way of calculating the result
void Player1::calculateRes(){
    this->result = (diceNum[0]+diceNum[1])%6;
}
