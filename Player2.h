#include "Player.h"
#ifndef Player2_H
#define Player2_H

class Player2: public Player{
    public:
    Player2();
    ~Player2();
    void setDiceNum(int diceNum,int index);
    int getDiceNum(int index);
    int getResult();
    void calculateRes();
};

#endif