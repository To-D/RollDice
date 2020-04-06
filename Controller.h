#ifndef Controller_H
#define Controller_H

class Controller{
    public:
    Controller();
    ~Controller();
    void printIntro();
    void acceptInstr(char, char*);
    void handleOneRound(Player,Dice,int);
    void determineSuccess(Player,Player);

    private:
    void newLine();
    void quit();
};

#endif