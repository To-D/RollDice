#include <iostream>
#include <stdlib.h>//rand()
#include <time.h>//srand()
#include <windows.h> //sleep()



using namespace std;

int main(){
	char instr;
	int first,second,total;

	cout << "Welcome to the dice rolling game!"<<endl;
	cout << endl;
	cout << "****************************************************" <<endl;
	cout << "It's an easy game: you will have two chance to roll. "<<endl;
	cout << "If the total is 7, you win!"<<endl;
	cout << "During the game, you can always input Q/q to quit the game!" << endl;
	cout << endl;
	cout << "If You want to start, please input 'S/s' : ";
	cin >> instr;
	cout << endl;

	// Start game
	while(1){
		if( instr == 'S' || instr == 's'){
			cout << "Game start! you have a dice now. "<<endl;
			cout << endl;
			cout << "Input 'R/r' to roll it:";
			cin >> instr;
			cout << endl;

			// First roll
			while(1){
				if(instr == 'R' || instr =='r'){
					srand((unsigned)time(NULL));
					first = (rand()%5)+1;
					cout << "Rolling..."<< endl;
					Sleep(1000);
					cout << "Guess what you'll get ..."<<endl; 
					Sleep(1000); 
					cout << endl;
					cout << "You get ";
					cout << first;
					cout <<" !"<<endl;
					cout << endl;
					cout << "Input 'R/r' to roll again:";
					cin >> instr;
					cout << endl;

					// Second roll
					while(1){
						if(instr == 'R' || instr == 'r'){
							srand((unsigned)time(NULL));
							second = (rand()%5)+1;
							cout << "Rolling..."<< endl;
							Sleep(1000);
							cout << "Guess what you'll get..."<<endl; 
							Sleep(1000);
							cout<<endl;
							cout << "You get ";
							cout <<second;
							cout <<" !"<<endl;
							total = first +second;
							cout<< endl;
							cout<< "You get ";
							cout<<total;
							cout<< " in total!"<< endl;
							cout << endl;
							if(total != 7){
								cout<< "Sorry,you lose.Good luck next time.";
							}else{
								cout << "Congralations! You win the game.";
							}
							Sleep(3000) ;
							return 0;
						}else if(instr == 'Q' || instr == 'q'){
							cout << "Quit the game. Wish you have a good time here!";
							return 0;
						}else{
							cout <<  "Input 'R/r' to roll again:";
							cin >> instr;
							cout << endl;
						}
					}
				}else if( instr == 'Q' || instr == 'q'){
					cout << "Quit the game. Wish you have a good time here!";
					return 0;
				}else{
					cout << "Input 'R/r' to roll it:" ;
					cin >> instr;
					cout << endl;
				}
			}
		}else if( instr == 'Q' || instr == 'q'){
			cout << "Quit the game. Wish you have a good time here!";
			return 0;
		}else{
			cout  << "Input 'S/s' to start:";
			cin >> instr;
			cout << endl;
		}
	}
}
