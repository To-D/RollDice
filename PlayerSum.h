#include "Player.h"
#ifndef PlayerSum_H
#define PlayerSum_H

class PlayerSum: public Player{
    public:
    PlayerSum(string name);
    ~PlayerSum();
    void setDiceNum(int diceNum,int index);
    int getDiceNum(int index);
    int getResult();
    void calculateRes();
};

#endif