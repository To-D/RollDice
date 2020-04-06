#include "Player2.h"

// Constructor
Player2::Player2(){};

// Destuctor
Player2::~Player2(){};

// Implement the calculateRes function
int Player2::calculateRes(){
    return (diceNum1*diceNum2)%6;
}
