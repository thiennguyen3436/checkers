#include <iostream>

extern void drawBoard(int cols);
//this is for a debugging option

int main(int argc, char* argv[]){

	for (int i = 0; i < argc; i++) {
		std::cout << i << ": " << argv[i] << std::endl;
		if (argv[i] == "usesimple") {
			board.simplePrint();
		}
	}


	int x = 1;
	int counter = 0;
	while(x % 4 != 0){
		if(counter < 1){
			std::cout << "Please input your desired width: ";
			counter = 1;
		}
	std::cin >> x;
		if(x % 4 != 0){
			std::cout << "Please input a multiple of 4: ";
		}
	}
	drawBoard(x);
	/*
	plan for main program
	make players
	get user input for player names
	start game
	while loop encapsulating everything in order to finish a game
	alternate between black and white
		white:
			check available captures
			if none
				provide possible moves
				pick a move
			else
				provide possible moves
				pick a move
			check if opponnent has no pieces or if the game is a draw
			if game is won
				
			else
				end turn
		black:
			repeat what white did


		should have functions for everything that is possible/repeated to eliminate mess. We could even have a Turn function that takes a player object as a parameter.
	*/
	return 0;
}