/**
 * @class Hall
 * @author Liu Junwei
 * @brief This class is the abstraction of the game hall, it can start a game
 */

#include "Hall.h"
#include "DiceRolling.h"
#include <iostream>
#include <windows.h> //Sleep()

// Creator
Hall::Hall(){
    cout << endl;
    cout << "Welcome to the Game Hall!" << endl;
    cout << endl;
    cout << "There is only one game \" DiceRolling\" in our list, We will start it for you now." << endl;
    cout << endl;
    Sleep(4000);
}

// Destructor
Hall::~Hall(){}

// Since only one game exists, return the implement of the game by default now.
DiceRolling Hall::start(int index){
    switch(index){
        default:
        DiceRolling diceRolling(2,2);
        return diceRolling;
    }    
}