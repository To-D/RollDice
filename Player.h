#ifndef Player_H
#define Player_H

class Player{
    protected:
    int diceNum[2];
    int cap = 2;
    int result;

    public:
    // Set function
    void setDiceNum(int,int){};
    void setResult(int);
    // Get function 
    int getDiceNum(int);
    int getResult();

    virtual int calculateRes();
};

#endif