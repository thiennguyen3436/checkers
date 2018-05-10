#include <iostream>

extern void drawBoard(int cols);

int main(){
	drawBoard(8);
	/*
	plan for main program:
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
				break out of while loop
			else
				end turn
		black:
			repeat what white did

		should have functions for everything that is possible/repeated to eliminate mess. We could even have a Turn function that takes a player object as a parameter.
	*/
	return 0;
}