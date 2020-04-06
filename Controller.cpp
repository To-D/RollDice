/**
 * @class Controller
 * @author Liu Junwei
 * @brief This class is used to handle some interactive logic in the game, such as parsing the user's input,
 *        print the help documentation.
 */

#include <iostream>
#include "Controller.h"
#include "Player.h"
#include "Dice.h"
#include <windows.h> //sleep()

using namespace std;

// Constructor
Controller::Controller(){}

// Destructo
Controller::~Controller(){}

// An auxiliary function used to print an empty line.
void Controller::newLine(){
    cout << endl;
}

// Quit the program when user input 'Q' or 'q'
void Controller::quit(){
    cout << "*********Game over. Hope you had a good time!*********";
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
 * @brief Accept the user's input and return only when the input is the expectedInstr or its lowercase
 * @param expectedInstr - The instruction which is expected of this process
 * @param promt - The prompt that will be printed to mention the user what to input
 */
void Controller::acceptInstr(char expectedInstr, char* promt){
    char instr;
	char uppercase = expectedInstr;
	char lowercase = expectedInstr+32;

	// Read instruction
	cout << promt;
	cin >> instr;

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
 * @brief It's used to handle a whole round of a player, including asking for an instruction, accept and
 * handle it etc.
 * @param player - The player of this round
 * @param dice - The dice object that will be rolled
 * @param roundNum - Index of the present round
 */ 
void Controller::handleOneRound(Player player, Dice dice, int roundNum){
    // Print prompt
	cout << "*********************Player";
	cout << roundNum;
	cout << "'s Round******************";

	// Accept user Input
	acceptInstr('R',"Input 'R/r' to roll:");

	// Response
	cout << "Rolling..."<< endl;
	int count = 0;
	while(count < 6){
		Sleep(500);
		cout << " *******";
	}
	newLine();

	// Roll the dice and record
	int diceNum = dice.roll();
	cout << "You get ";
	cout << diceNum;
	cout <<" !"<<endl;
	player.setDiceNum(diceNum, roundNum-1);
	newLine();
}

void Controller::determineSuccess(Player player1, Player player2){
    int res1 = player1.getResult();
    int res2 = player2.getResult();
    cout << "Player1's final goal is ";
    cout << res1 << endl;
    cout << "Player2's final goal is ";
    cout << res2 << endl;

    int diff = player1.getResult() - player2.getResult();
    if (diff == 0){
        cout << "It's a draw."<<endl;
    }else if(diff > 0){
        cout << "Player1 wins!"<< endl;
    }else{
        cout << "Player2 wins!"<< endl;
    }
}

