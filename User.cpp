/**
 * @class User
 * @author Liu Junwei
 * @brief This class is the abstraction of the user of the hall, when it joins a game, it becomes the player of the game.
 */ 
#include "User.h"
#include "time.h"
#include<string>

// Creator
User::User(string name, double credit){
    this->name = name;
    this->credit = credit;
    creditLog("Sign Up +5");
}

// Destructor
User::~User(){}

// Increase the credit
void User::addCredit(double variable,string way){
    this->credit += variable;    
    creditLog(way+" +"+to_string(variable));
}

// Reduce the credit
void User::reduceCredit(double variable, string way){
    this->credit -= variable;
    creditLog(way+" -"+to_string(variable));
}

// Get credit
double User::getCredit(){
    return this->credit;
}

// Get the user name
string User::getName(){
    return this->name;
}

// Record credit change
void User::creditLog(string operation){
    string record = "";
    record += getTime();
    record += operation;
    this->creditRecords.push_back(record);
}

// Get the present time
string User::getTime(){
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y/%m/%d %H:%M:%S",localtime(&timep));
    return tmp;
}
