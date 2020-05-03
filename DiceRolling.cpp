/**
 * @class DiceRolling
 * @author Liu Junwei
 * @brief This class is used to handle some interactive logic in the DiceRolling game。
 */

#include <iostream>
#include <windows.h> //sleep()
#include <assert.h>
#include "DiceRolling.h"
#include "Player.h"
#include "PlayerSum.h"
#include "PlayerProduct.h"
#include "Dice.h"

using namespace std;

// Constructor
DiceRolling::DiceRolling(int playerTotal, int timesEachRound){
	this -> capacity = playerTotal;
	this -> timesEachRound = timesEachRound;
	this -> roundIndex = 0;
	this -> currentNum = 0;
	this -> winner.push_back(""); // Don't use the first space for using index conveniently
	this -> dice = Dice();
	printIntro();
}

// Destructor
DiceRolling::~DiceRolling(){}

/**
 * @brief Accept a user and initial a player's information
 * @param user - the user that joins the game
 */ 
void DiceRolling::acceptPlayer(User user){
	assert(currentNum < 3);
	string name = user.getName();
	newLine();
	cout << name + " joins the game." << endl;
	newLine();
	cout << "******************************************************" << endl;
	cout << "*     Please choose the way you want to be marked.   *" << endl;
	cout << "*     1.The remainder of the sum divided by six      *" << endl;
	cout << "*     2.The remainder of the product divided by six  *" << endl;
	cout << "******************************************************" << endl;
	char instr;
	cin >> instr;
	while(1){
		switch(instr){
			case '1':
			currentNum ? player2 = new PlayerSum(name) : player1 = new PlayerSum(name);
			currentNum++;
			if(currentNum == 2){
				newLine();
				cout << "Players have been ready, our game is about to start" << endl;
				newLine();
			}
			return;
			
			case '2':
			currentNum ? player2 = new PlayerProduct(name) : player1 = new PlayerProduct(name);
			currentNum++;
			if(currentNum == 2){
				newLine();
				cout << "Players have been ready, our game is about to start" << endl;
				newLine();
			}
			return;
		}
		cin >> instr;
	}
}

// Start the process of the DiceRolling game
void DiceRolling::start(){
	//Accept user's start instruction
	acceptInstr('S',"Input S/s to Start:");	

	while(1){
		// start a game round
		startOneRound();		
		acceptInstr('S',"Input 'S/s' to start a new round or 'Q/q' to quit:");
		// Before a new round, print the result before
		printAllRoundsResult();
		}
}

/**
 * @brief Accept the user's input and handle it, it returns only when the input is the expectedInstr or its lowercase
 * @param expectedInstr - The instruction which is expected.
 * @param promt - The prompt that will be printed to mention the user what to input
 */
void DiceRolling::acceptInstr(char expectedInstr, string promt){
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

// Start a new game round.
void DiceRolling::startOneRound(){
	roundIndex++;
	cout << "******************************************************" << endl;
	cout << "                      Round  ";
	cout << roundIndex << endl;
	cout << "******************************************************" << endl;

	// Players roll alternately every round
	for(int i = 0 ; i < timesEachRound; i++){
			rollOneTime(player1,i);
			rollOneTime(player2,i);
	}

	// Calculate results and determine success
	player1->calculateRes();
	player2->calculateRes();
	int res1 = player1->getResult();
	int res2 = player2->getResult();
	determineSuccess(res1,res2);
}

/**
 * @brief Handle a rolling
 * @param player - The player of this rolling
 * @param roundNum - Index of the present round
 */ 
void DiceRolling::rollOneTime(Player* player,int roundNum){
    // Print prompt
    cout << "******************************************************" << endl;
	cout << "                   ";
    cout << player->getName();
    cout << "'s Trun ";
    cout << roundNum+1 <<endl;
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
	cout << "You got ";
	cout << diceNum;
	cout <<" !"<<endl;
	player->setDiceNum(diceNum, roundNum);
	newLine();
	newLine();	
    Sleep(1000);
}

/**
 * @brief It's used to announce the goal of each player and the final result
 * @param res1 - The goal of the player1
 * @param res2 - The goal of the player2
 */ 
void DiceRolling::determineSuccess(int res1, int res2){
	cout << "******************************************************" << endl;
	newLine();
	cout << player1->getName();
	cout << "'s final goal is ";
	cout << res1 << endl;
	newLine();
	cout << player2->getName();
	cout <<"'s final goal is ";
	cout << res2 << endl;
	newLine();
	cout << "******************************************************" << endl;
    int diff = res1 - res2;
	string winnerName = "";
	if(diff > 0){
		winnerName = player1->getName();
    }
	if(diff < 0){
		winnerName = player2->getName();
    }	
	
	// Announce winner
	announceWinner(winnerName,roundIndex);

	// Record winner's name
	winner.push_back(winnerName);
}

/**
 * @brief Print the winner of the present round
 * @param name - the winner's name
 * 		  roundIndex - index of the present round
 */
void DiceRolling::announceWinner(string name,int roundIndex){
	cout << "******************************************************" << endl;
	cout << "                      Round  ";
	cout << roundIndex << endl;
	
	if(name == ""){
		cout << "                     It's a draw.                    "<< endl;
	}else{
		cout << "                     ";
		cout << name;
		cout<<" wins!                    "<< endl;
	}
	cout << "******************************************************" << endl;
}

// Print all results of the before rounds
void DiceRolling::printAllRoundsResult(){
	int len = winner.size();
	newLine();
	if(len > 0){
	cout << "           ---Results of Previous Rounds---           " << endl;
	}
	for(int i = 1; i < len; i++){
		announceWinner(winner[i],i);
	}
	newLine();
	newLine();
	Sleep(1000);
};

// Quit the program when user input 'Q' or 'q'
void DiceRolling::quit(){
	newLine();
	printAllRoundsResult();
    cout << "******************************************************" << endl;
    cout << "*        Game over. Hope you had a good time!        *" << endl;
    cout << "******************************************************" << endl;
	delete player1;
	delete player2;
	exit(0);
}

// Print the introduction of the game when necessary
void DiceRolling::printIntro(){
    newLine();
	cout << "******************************************************" << endl;
	cout << "*        Welcome to the dice rolling game!           *" << endl;
	cout << "******************************************************" << endl;
	cout << "*                    Rules                           *" << endl;
	cout << "* 1. Two players participated and roll alternately.  *" << endl;
	cout << "* 2. Each can roll two times in a round, there are   *" << endl;
	cout << "*    infinite rounds unless you choose to exit.      *" << endl;
	cout << "* 3. Two ways to calculate your goal in a round:     *" << endl;
	cout << "*    a> The remainder of the sum divided by six      *" << endl;
	cout << "*    b> The remainder of the product divided by six  *" << endl;
	cout << "*    You can choose one when you enter.              *" << endl;
	cout << "* 4. When game starts, you can using the instructions*" << endl;
	cout << "*     below to control.                              *" << endl;
	cout << "******************************************************" << endl;
	cout << "*                 Instruction                        *" << endl;
	cout << "* S/s  Start the game        R/r  Roll the dice      *" << endl;
	cout << "* Q/q  Quit the game         I/i  See this page      *" << endl;
	cout << "******************************************************" << endl;
	newLine();
	Sleep(2000);
}

// An auxiliary function used to print an empty line.
void DiceRolling::newLine(){
    cout << endl;
}