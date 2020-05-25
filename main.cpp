/**
 * @class main
 * @author Liu Junwei
 */  
#include <iostream>
#include "Hall.h"
#include "User.h"
#include "DiceRolling.h"
#include "CalculateStrategy.h"

using namespace std;

int main(){
	Hall hall;

	hall.signUp();
	
	hall.startOneGame();
		
	// User user1("User1"); 
	// User user2("User2");

	// // Create a diceRolling game(0 is the index of "DiceRolling", in case of more kind of games)
	// DiceRolling diceRolling = hall.start(0);

	// // user1 and user2 enter the game
	// diceRolling.acceptPlayer(user1);
	// diceRolling.acceptPlayer(user2);
	
	// diceRolling.start();	

	// CalculateStrategy* CalculateStrategy1 = new SumAndDivide();
	// CalculateStrategy* CalculateStrategy2 = new ProductAndDivide();
	// CalculateStrategy* CalculateStrategy3 = new Average();
	// int res1 = 3;
	// int res2 = 4;
	// cout << CalculateStrategy1->calculateResult(res1,res2) << endl;
	// cout << CalculateStrategy2->calculateResult(res1,res2) << endl;
	// cout << CalculateStrategy3->calculateResult(res1,res2) << endl;
}
