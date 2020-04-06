#include "Player.h"
#ifndef Player2_H
#define Player2_H

class Player2: public Player{
    public:
    Player2();
    ~Player2();
    void setDiceNum(int,int){};
    void setResult(int);
    int getDiceNum(int);
    int getResult();
    int calculateRes();
};

#endif