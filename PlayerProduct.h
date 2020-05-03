#include "Player.h"
#ifndef PlayerProduct_H
#define PlayerProduct_H

class PlayerProduct: public Player{
    public:
    PlayerProduct(string name);
    ~PlayerProduct();
    void setDiceNum(int diceNum,int index);
    int getDiceNum(int index);
    int getResult();
    void calculateRes();
};

#endif