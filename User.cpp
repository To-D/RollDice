/**
 * @class User
 * @author Liu Junwei
 * @brief This class is the abstraction of the user of the hall, when it joins a game, it becomes the player of the game.
 */ 
#include "User.h"

// Creator
User::User(string name){
    this->name = name;
}

// Destructor
User::~User(){}

// Get the user name
string User::getName(){
    return this->name;
}