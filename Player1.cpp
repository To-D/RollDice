#include "Player1.h"

// Constructor
Player1::Player1(){};

// Destuctor
Player1::~Player1(){};

// Implement the calculateRes function
int Player1::calculateRes(){
    return (diceNum1+diceNum2)%6;
}
