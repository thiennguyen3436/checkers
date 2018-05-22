#include <iostream>
#include <sstream>
#include <string>
#include "player.h"

extern void drawBoard(int cols, player player1, player player2);
//stores the initial position of the pieces;
void check_pieces(int* Board, int cols, player player1, player player2){
	std::vector<piece> A = player1.List;
	std::vector<piece> B = player2.List;

	int bigL;
	if(A.size() >= B.size()){
		bigL = A.size();
	}		
	else{
		bigL = B.size();
	}
	//If you have a multidimensional array defined as int [][], then x = y[a][b] is equivalent to x = *((int *)y + a * NUMBER_OF_COLUMNS + b);
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < cols; j ++){
			for(int l = 0; l < A.size(); l++){
				if(A[l].xpos == j && A[l].ypos == i){
					if(A[l].teams == 'w'){
						*(Board + j*8 + i) = 1;
					}
					else if(A[l].teams == 'b'){
						*(Board + j*8 + i) = 2;
					}
				}
			}
			for(int l = 0; l < B.size(); l ++){
				if(B[l].xpos == j && B[l].ypos == i){
					if(B[l].teams == 'w'){
						*(Board + j*8 + i) = 1;
					}
					else if(B[l].teams == 'b'){
						*(Board + j*8 + i) = 2;
					} 
				}
			}
		}
	}
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < cols; j ++){
			if(*(Board + j*8 + i) != 0){

			}
			else{
				*(Board + j*8 + i) = 0;
			}
		}
	}
}
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
	player player2 = player('b', x);
	//draw the initial board
	int board[x][8];
	for(int i = 0; i < x; i ++){
		for(int j = 0; j < 8; j ++){
			board[i][j] = 0;
		}
	}
	int* ptr = &board[0][0];
	check_pieces(ptr, x, player1, player2);
	drawBoard(x, player1, player2);
	for(int i = 0; i < 8; i ++){
		for(int j = 0; j < x; j ++){
			std::cout << i << " + " << j << " = " << board[j][i] << std::endl;
		}
	}
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

