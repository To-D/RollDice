#include "Player.h"
#include "Dice.h"

#ifndef Controller_H
#define Controller_H

using namespace std;

class Controller{
    public:
    Controller(int playerTotal, int roundTotal);
    ~Controller();
    void printIntro();
    void acceptInstr(char expectedInstr, string prompt);
    void handleOneRound(Player& player,int roundNum);
    void determineSuccess(int res1, int res2);
    void gameProcess(Player& player1,Player& player2);

    private:
    int playerTotal;
    int roundTotal;
    void newLine();
    void quit();
    Dice dice;
};

#endif