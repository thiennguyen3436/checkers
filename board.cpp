#include <iostream>
#include <vector>
#include "piece.h"
#include "player.h"
//this will need to include both piece lists from the players as parameters in order to add them to the board.
void drawBoard(int cols, player player1, player player2){//, player player1, player player2){
	//std::vector<piece> blues = player1.pieces;
	//std::vector<piece> greens = player2.pieces;
	std::vector<piece> blues = player2.List;
	std::vector<piece> greens = player1.List;
	//use erase to remove a piece
	//greens.erase(greens.begin());


	if(cols % 4 != 0){
		std::cout << "Please enter a multiple of 4" << std::endl;
	}
	else{
		for(int i = 0; i < 8; i ++){
			//this is for the numbers along the top
			if(i == 0){
				for (int j = 0; j < cols; j++){
					if(j<9){
						std::cout << "   " << j+1 << "   ";
					}
					else{
						std::cout << "  " << j+1 << "   ";
					}
				}
			std::cout << "" << std::endl;
			}
			//this is where the board actually starts
			for (int j = 0; j < cols; j++){
				if((j+i) % 2 == 0){
					std::cout << "\033[7;30m       \033[0m";
				}
				else{
					std::cout << "       ";
				}
			}
			std::cout << "" << std::endl;

			//printing out the middle three rows of each row
			for(int k = 0; k < 3; k++){
				for (int j = 0; j < cols; j++){
					if((j+i) % 2 == 0 && k != 1){
						std::cout << "\033[7;30m       \033[0m";
					}
					else if((j+i) % 2 == 0 && k == 1){
						int bigL;
						if(greens.size() >= blues.size()){
							bigL = greens.size();
						}
						else{
							bigL = blues.size();
						}
						//this is what checks if theres a piece in the current square and if there is it adds it to the screen.
						//it needs to be modified because it shouldn't depend on the size of one of the vectors but it needs to check both of them concurrently
						//need to ensure it works with different sized vectors otherwise I don't think it will print properly
						for(int l = 0; l < bigL; l++){
							if(greens[l].xpos == j && greens[l].ypos == i){
								if(greens[l].id > 9){
									std::cout << "\033[7;30m   \033[32;1;40m" << greens[l].id << "\033[0m" <<"\033[7;30m  \033[0m";
								}
								else{
									std::cout << "\033[7;30m   \033[32;1;40m" << greens[l].id << "\033[0m" <<"\033[7;30m   \033[0m";
								}
								break;
							}
							else if(blues[l].xpos == j && blues[l].ypos == i){
								if(greens[l].id > 9){
									std::cout << "\033[7;30m   \033[36;1;40m" << blues[l].id << "\033[0m" << "\033[7;30m  \033[0m";
								}
								else{
									std::cout << "\033[7;30m   \033[36;1;40m" << blues[l].id << "\033[0m" << "\033[7;30m   \033[0m";
								}
								break;
							}
							else if(l == (bigL-1)) {
								std::cout << "\033[7;30m       \033[0m";
							}
							
						}
						
					}
					else{
						for(int l = 0; l < greens.size(); l++){
							if(greens[l].xpos == j && greens[l].ypos == i && k == 1){
								std::cout << "   \033[0;32m" << greens[l].id << "\033[0m   ";
								break;
							}
							else if(l == (greens.size()-1)) {
								std::cout << "       ";
							}
						}
					}
				}
				if(k == 1){
					std::cout << " " << i+1;
				}
				std::cout << "" << std::endl;
			}
			for (int j = 0; j < cols; j++){
				if((j+i) % 2 == 0){
					std::cout << "\033[7;30m       \033[0m";
				}
				else{
					std::cout << "       ";
				}
			}
			std::cout << "" << std::endl;
			//this is the end of the board
		}
	}
}