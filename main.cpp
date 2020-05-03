/**
 * @class main
 * @author Liu Junwei
 */  
#include <iostream>
#include "Hall.h"
#include "User.h"
#include "DiceRolling.h"

using namespace std;

int main(){
	// Initial game hall and two users
	Hall hall;
	User user1("User1"); 
	User user2("User2");

	// Create a diceRolling game(0 is the index of "DiceRolling", in case of more kind of games)
	DiceRolling diceRolling = hall.start(0);

	// user1 and user2 enter the game
	diceRolling.acceptPlayer(user1);
	diceRolling.acceptPlayer(user2);
	
	diceRolling.start();	
}