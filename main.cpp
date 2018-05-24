#include <iostream>
#include <sstream>
#include <string>
#include "player.h"
#include <utility>

extern void drawBoard(int* Board, int cols);

//stores the initial position of the pieces;
void update_pieces(int* Board, int cols, player player1, player player2){
	std::vector<piece> A = player1.List;
	std::vector<piece> B = player2.List;


	for(int i = 0; i < 8; i++){
		for(int j = 0; j < cols; j ++){
			*(Board + j*8 + i) = 0;
		}
	}


	int bigL;
	if(A.size() >= B.size()){
		bigL = A.size();
	}		
	else{
		bigL = B.size();
	}
	//x = y[a][b] is equivalent to x = *((int *)y + a * NUMBER_OF_COLUMNS + b);
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
int main(){

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
	int board[x][8];
	for(int i = 0; i < x; i ++){
		for(int j = 0; j < 8; j ++){
			board[i][j] = 0;
		}
	}
	int* ptr = &board[0][0];
	player player1 = player('w', x, ptr);
	player player2 = player('b', x, ptr);

	int pieceCountA = player1.List.size();
	int pieceCountB = player2.List.size();

	player* play1 = &player1; //used for captures made by the opposite player
	player* play2 = &player2;
	//draw the initial board
	
	update_pieces(ptr, x, player1, player2);
	drawBoard(ptr, x);

	bool gameOver = false; //checks whether or not someone won or the game was a draw
	int moveCounter = 0; // tallies number of moves without a capture
	int total_moves = 0; // tallies total number of moves
	int draw; // checks whether or not a draw has been agreed upon

	while(gameOver == false){
		std::cout << "player 1's turn:" << std::endl;
		player1.move(play2);
		update_pieces(ptr, x, player1, player2);
		drawBoard(ptr,x);
		if(player2.List.size() != pieceCountB){
			pieceCountB = player2.List.size();
		}
		if(pieceCountB == 0){
			gameOver = true;
			std::cout << "Player 1 won!" << std::endl;
			continue;
		}

		std::cout << "player 2's turn:" << std::endl;
		player2.move(play1);
		update_pieces(ptr, x, player1, player2);
		drawBoard(ptr,x);

		if(player1.List.size() != pieceCountA){
			pieceCountA = player1.List.size();
		}

		//checks whether or not the other player has any pieces left, if not you win
		if(pieceCountA == 0){
			gameOver = true;
			std::cout << "Player 2 won!" << std::endl;
			continue; //immediately ends the game
		}

		if(pieceCountA == player1.List.size() && pieceCountB == player2.List.size()){
			moveCounter++;
			if(moveCounter == 50){
				std::cout << "You drew by the 50 move rule:" << std::endl;
				gameOver = true;
				continue;
			}
		}
		total_moves++;
		std::cout << total_moves << "  " << x*2 << std::endl;
		if(total_moves > x){
			//validating user input for a draw
			std::string inputd;
			std::cout << "Do both players agree to a draw? (1 for yes / 2 for no): ";
			while(std::getline(std::cin, inputd)){
				std::stringstream uinput(inputd);

				if(!(uinput >> draw)){
					std::cout << "Please input 1 or 2: ";
					continue;
				}
				if((draw < 1) || draw > 2){
					std::cout << "Please input 1 or 2: ";
					continue;
				}
				char extras;
				if(uinput >> extras){
					std::cout << "Only 1 or 2 please :)" << std::endl;
				}
				break;
			}
		}
		//if both players agree to a draw end the game
		if(draw == 1){
			std::cout << "You agreed to a draw" << std::endl;
			gameOver = true;
		}
	}
	return 0;
}

