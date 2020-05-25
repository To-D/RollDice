/**
 * @class Hall
 * @author Liu Junwei
 * @brief This class is the abstraction of the game hall, it can start a game
 */

#include "Hall.h"
#include "DiceRolling.h"
#include "User.h"
#include <iostream>
#include <windows.h> //Sleep()
#include <string>

// Creator
Hall::Hall(){
    cout << endl;
    cout << "Welcome to the Game Hall!" << endl;
    cout << endl;
    Sleep(1000);
}

void Hall::printRegisterPromt(){
    cout << endl;
    cout << "******************************************************" << endl;
    cout << "                      Register                        " << endl;
    cout << "         [1] Register a new account                   " << endl;
    cout << "         [2] Quit and enter the hall                  " << endl;
    cout << "******************************************************" << endl;
    cout << endl;
}

void Hall::signUp(){
    char instr;
    printRegisterPromt();
    cin >> instr;
    while(1){
        switch(instr){
            case '1':               
            {
                cin.get(); // clear the 'enter' in the cache
                string name;
                cout << "Enter your name:" ;
                getline(cin,name);
                User user(name,5);
                users.push_back(user);
                break;
            }
            case '2':
                if(users.size() > 0){
                    return;
                }
                cout << endl;
                cout << "There's no users in the hall. Please register first!";
                cout << endl;
                break;
        }
        printRegisterPromt();
        cin >> instr;
    }    
}

void Hall::printStartPromt(){
    cout << "******************************************************" << endl;
    cout << "            [1] Start a new game                      " << endl;
    cout << "            [2] Quit                                  " << endl;
    cout << "******************************************************" << endl;
}

// Invite all the users whose credit are more than 1
void Hall::invite(){
    int len = users.size();
    for(int i = 0; i < len ; i++){
        User user = users[i];
        if(user.getCredit()>=1){            
            cout << endl;
            cout << "Dear "<< user.getName() << ", would you like to join the game?  [Y/N]" << endl;
            char instr;
            cin >> instr;
            switch(instr){
                case 'y':
                case 'Y':
                    currentGame.acceptPlayer(user);
                    break;
                case 'n':
                case 'N':
                    continue;
                default: 
                    cout << "Dear "<< user.getName() << ", would you like to join the game?  [Y/N]" << endl;
                    cin >> instr;               
            }
        }        
    }
}

// Start a diceRolling game
DiceRolling Hall::startOneGame(){
    printStartPromt();
    char instr;
    cin >> instr;
    while(1){
        switch(instr){
            case '1':
            {
                DiceRolling diceRolling(2,2);
                games.push_back(diceRolling);
                currentGame = diceRolling;
                invite();
                currentGame.start();
                return diceRolling;
            }
            case '2':
                cout << "******************************************************" << endl;
                cout << "*        Game over. Hope you had a good time!        *" << endl;
                cout << "******************************************************" << endl;
                exit(0);
        }
        printStartPromt();
        cin >> instr;
    }
    
}

