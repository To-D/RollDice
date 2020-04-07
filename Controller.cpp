/**
 * @class Controller
 * @author Liu Junwei
 * @brief This class is used to handle some interactive logic in the game, such as parsing the user's input,
 *        print the help documentation etc.
 */

#include <iostream>
#include <windows.h> //sleep()
#include "Controller.h"
#include "Player.h"
#include "Dice.h"

using namespace std;

// Constructor
Controller::Controller(int playerTotal, int roundTotal){
	this->playerTotal = playerTotal;
	this->roundTotal = roundTotal;
}

// Destructo
Controller::~Controller(){}

// An auxiliary function used to print an empty line.
void Controller::newLine(){
    cout << endl;
}

// Quit the program when user input 'Q' or 'q'
void Controller::quit(){
    newLine();
    cout << "******************************************************" << endl;
    cout << "*        Game over. Hope you had a good time!        *" << endl;
    cout << "******************************************************" << endl;
	exit(0);
}

// Print the introduction of the game when necessary
void Controller::printIntro(){
    newLine();
	cout << "******************************************************" << endl;
	cout << "*        Welcome to the dice rolling game!           *" << endl;
	cout << "******************************************************" << endl;
	cout << "*                    Rules                           *" << endl;
	cout << "* 1. Two players participated and roll alternately.  *" << endl;
	cout << "* 2. Each one roll two times.                        *" << endl;
	cout << "* 3. The goal is calculated by (k%6) where k is the  *" << endl;
	cout << "*    sum of the two roll for Player1 but the product *" << endl;
	cout << "*    for Player2.                                    *" << endl;
	cout << "******************************************************" << endl;
	cout << "*                 Instruction                        *" << endl;
	cout << "* S/s  Start the game        R/r  Roll the dice      *" << endl;
	cout << "* Q/q  Quit the game         I/i  See this page      *" << endl;
	cout << "******************************************************" << endl;
	newLine();
}

/**
 * @brief Accept the user's input and handle it, it returns only when the input is the expectedInstr or its lowercase
 * @param expectedInstr - The instruction which is expected.
 * @param promt - The prompt that will be printed to mention the user what to input
 */
void Controller::acceptInstr(char expectedInstr, string promt){
    string input;
    char instr;
	char uppercase = expectedInstr;
	char lowercase = expectedInstr+32;

	// Read instruction
	cout << promt;
	cin >> input;
    instr = input[0];

	// Handle instruction
	while(1){
		if(instr == uppercase || instr == lowercase){
			newLine();
			return;// Return only when geting the expected instructions
		}

		if(instr == 'Q' || instr == 'q'){
			quit();
		}

		if(instr == 'I' || instr == 'i'){
			printIntro();
		}

		// Unexpected instruction. Read again.
		cout << promt;
		cin >> instr;
	}
}

/**
 * @brief It's used to handle cetarin player's certain round, including asking for an instruction, accept and
 * 		  handle it etc.
 * @param player - The player of this round
 * @param roundNum - Index of the present round
 */ 
void Controller::handleOneRound(Player& player,int roundNum){
    // Print prompt
    cout << "******************************************************" << endl;
	cout << " *               ";
    cout << player.getName();
    cout << "'s Round ";
    cout << roundNum+1;
    cout << "                  *" <<endl;
    cout << "******************************************************" << endl;
    newLine();

	// Accept user Input
	acceptInstr('R',"Input 'R/r' to roll:");

	// Response
	cout << "Rolling..."<< endl;
	int count = 0;
	while(count < 6){
		Sleep(500);
		cout << " *******";
        count++;
	}
	newLine();

	// Roll the dice and record
	int diceNum = this-> dice.roll();
	cout << "You get ";
	cout << diceNum;
	cout <<" !"<<endl;
	player.setDiceNum(diceNum, roundNum);
	newLine();
	newLine();
	
    Sleep(1000);
}

/**
 * @brief It's used to control the main process of the game, without announcing the result
 * @param Params are the players paticipated.Can be replaced by a set of players.
 */ 
void Controller::gameProcess(Player& player1, Player& player2){
	cout << "******************************************************" << endl;
	cout << " *                Game Begins!                      * " << endl;
	cout << "******************************************************" << endl;
	// Players roll alternately every round
	for(int i = 0 ; i < roundTotal; i++){
			handleOneRound(player1,i);
			handleOneRound(player2,i);
	}
}

/**
 * @brief It's used to announce the goal of each player and the final result
 * @param res1 - The goal of the player1
 * @param res2 - The goal of the player2
 */ 
void Controller::determineSuccess(int res1, int res2){
	cout << "******************************************************" << endl;
	newLine();
	cout << " Player1's final goal is ";
	cout << res1 << endl;
	newLine();
	cout << " Player2's final goal is ";
	cout << res2 << endl;
	newLine();
	cout << "******************************************************" << endl;
    int diff = res1 - res2;
    if (diff == 0){
		cout << " *                   It's a draw.                   *"<< endl;
    }else if(diff > 0){
		cout << " *                  Player1 wins!                   *"<< endl;
    }else{
		cout << " *                   Player2 wins!                  *"<< endl;
    }	
	cout << "******************************************************" << endl;
}

