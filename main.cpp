#include <iostream>
#include "Player.h"
#include "Player1.h"
#include "Player2.h"
#include "Dice.h"
#include "Controller.h"

using namespace std;

int main(){
	//Initial game controller
	Controller controller;

	//Print game introduction
	controller.printIntro();
	
	// Start game
	controller.acceptInstr('S',"Input S/s to Start:");	

	// Initial two players and the dice objects
	Player1 player1;
	Player1 player2;
	Dice dice;

	cout << "******************************************************" << endl;
	cout << "*                     Game Begins!                   *" << endl;
	cout << "******************************************************" << endl;

	// Game Process
	controller.handleOneRound(player1,dice,1);
	controller.handleOneRound(player2,dice,1);
	controller.handleOneRound(player1,dice,2);
	controller.handleOneRound(player2,dice,2);

	// Announce the result
	player1.calculateRes();
	player2.calculateRes();
	controller.determineSuccess(player1,player2);

	cout << "Thank you for playing! Input 'S/s' to play again or 'Q/q' to quit:";
  	controller.acceptInstr('S',"Input S/s to Start:");	
}

/*void newLine(){
	cout<<endl;
}

void printIntro(){
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

void quit(){
	cout << "*********Game over. Hope you had a good time!*********";
	exit(0);
}

void acceptInstr(char expectedInstr, char* promt){
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

void handleOneRound(Player player,Dice dice,int roundNum){
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
}*/