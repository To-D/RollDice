#include "Player.h"
#include "User.h"
#include "Dice.h"
#include <vector>

#ifndef DiceRolling_H
#define DiceRolling_H

using namespace std;

class DiceRolling{
    public:
    DiceRolling(int playerTotal, int timesEachRound);
    ~DiceRolling();
    void acceptPlayer(User user);
    void start();

    private:
    int capacity;
    int currentNum;
    int timesEachRound;
    int roundIndex;
    vector<string>winner;
    Player* player1;
    Player* player2;
    Dice dice;
    void startOneRound();
    void rollOneTime(Player* player,int roundNum);
    void acceptInstr(char expectedInstr, string prompt);
    void announceWinner(string winnerName,int roundIndex);
    void determineSuccess(int res1, int res2);
    void addWinner(string winnerName);
    void printAllRoundsResult();
    void printIntro();    
    void newLine();
    void quit();
};

#endif