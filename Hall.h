/**
 * @class Hall
 * @author Liu Junwei
 * @brief This class is the abstraction of the game hall
 */
#include <string>
#include "DiceRolling.h"
#include <vector>

#ifndef Hall_H
#define Hall_H

using namespace std;

class Hall{
    private:
    vector<User> users;
    vector<DiceRolling> games;
    void printRegisterPromt();
    void printStartPromt();    
    DiceRolling currentGame;

    public:
    Hall();
    void signUp();
    void invite();
    DiceRolling startOneGame();
};

#endif