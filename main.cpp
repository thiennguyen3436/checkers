#include <iostream>
#include <sstream>
#include <string>
#include "player.h"

extern void drawBoard(int cols, player player1);

//this is for a debugging option
int main(){//int argc, char* argv[]){

	/*for (int i = 0; i < argc; i++) {
		std::cout << i << ": " << argv[i] << std::endl;
		if (argv[i] == "usesimple") {
			board.simplePrint();
		}
	}*/

//negative numbers
//non integers


	// https://stackoverflow.com/questions/13212043/integer-input-validation-how
	//this was how I validated user input to ensure it was an integer in the correct range
	int x;
	std::string input;
	std::cout << "Please input your desired width: ";
	while(std::getline(std::cin, input)){
		std::stringstream uinput(input);

		if(!(uinput >> x)){
			std::cout << "Please input an integer: ";
			continue;
		}
		if((x <= 0) || (x % 4 != 0)){
			std::cout << "Please input a multiple of 4 greater than 0: ";
			continue;
		}
		char extras;
		if(uinput >> extras){
			std::cout << "Only integers please :)" << std::endl;
		}
		break;
	}
	player player1 = player('w', x);
	//draw the initial board
	drawBoard(x, player1);
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