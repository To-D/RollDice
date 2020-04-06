#include "Player.h"
#ifndef Player1_H
#define Player1_H

class Player1: public Player{
    public:
    Player1();
    ~Player1();
    void setDiceNum(int,int){};
    void setResult(int);
    int getDiceNum(int);
    int getResult();
    int calculateRes();
};

#endif