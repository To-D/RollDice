#include "Dice.h"
#include <stdlib.h>//rand()
#include <time.h>//srand()

// Constructor
Dice::Dice(){};

// Desrtuctor
Dice::~Dice(){};

int Dice::roll(){
    srand((unsigned)time(NULL));
    return (rand()%5)+1;
}