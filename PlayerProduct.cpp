/**
 * @class PlayerProduct
 * @author Liu Junwei
 * @brief This class is the abstraction of the player using "product-deviding" strategy in DiceRolling
 */
#include "PlayerProduct.h"
#include <iostream>

// Constructor
PlayerProduct::PlayerProduct(string name){
    this->name = name;
};

// Destuctor
PlayerProduct::~PlayerProduct(){};

// The player2's way of calculating the result
void PlayerProduct::calculateRes(){
    this->result =(diceNum[0]*diceNum[1])%6;
}
