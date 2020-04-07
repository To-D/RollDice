#include <string>

#ifndef Player_H
#define Player_H

using namespace std;

class Player{
    protected:
    int diceNum[2];
    int cap = 2;
    int result;
    string name;

    public:
    // Set function
    void setDiceNum(int diceNum,int index);
    void setName();
    
    // Get function 
    int getDiceNum(int index);
    int getResult();
    string getName();

    virtual void calculateRes();
};

#endif