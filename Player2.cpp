/**
 * @class Player2
 * @author Liu Junwei
 * @brief This class is the abstraction of the second player
 */
#include "Player2.h"

// Constructor
Player2::Player2(){
    this->name = "Player2";
};

// Destuctor
Player2::~Player2(){};

// The player2's way of calculating the result
void Player2::calculateRes(){
    this->result =(diceNum[0]*diceNum[1])%6;
}
