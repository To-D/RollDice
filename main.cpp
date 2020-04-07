/**
 * @class main
 * @author Liu Junwei
 */  
#include <iostream>
#include "Player.h"
#include "Player1.h"
#include "Player2.h"
#include "Dice.h"
#include "Controller.h"

using namespace std;

int main(){
	//Initialize game controller: 2 player,2 rounds
	Controller controller( 2, 2 );

	//Print game introduction
	controller.printIntro();
	
	//Accept user's input
	controller.acceptInstr('S',"Input S/s to Start:");	

	while(1){
		// Start game.
		// Initial two players
		Player1 player1;
		Player2 player2;

		// Game Process
		controller.gameProcess(player1,player2);
		
		// Calculate and announce the result
		player1.calculateRes();
		player2.calculateRes();
		int res1 = Player(player1).getResult();
		int res2 = Player(player2).getResult();
		controller.determineSuccess(res1,res2);

		cout << "Thank you for playing!" << endl;
		controller.acceptInstr('S',"Input 'S/s' to play again or 'Q/q' to quit:");	
	}
}