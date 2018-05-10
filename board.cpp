#include <iostream>
#include <vector>
#include "piece.h"
//this will need to include both piece lists from the players as parameters in order to add them to the board.
void drawBoard(int cols){//, player player1, player player2){
	//std::vector<piece> blues = player1.pieces;
	//std::vector<piece> greens = player2.pieces;
	std::vector<piece> greens;
	piece a = piece('w', 1);
	a.setXpos(1);
	a.setYpos(0);
	greens.push_back(a);
	piece b = piece('w', 2);
	b.setXpos(2);
	b.setYpos(0);
	greens.push_back(b);
	piece c = piece('w', 3);
	c.setXpos(3);
	c.setYpos(0);
	greens.push_back(c);
	piece d = piece('w', 4);
	d.setXpos(4);
	d.setYpos(0);
	greens.push_back(d);
	piece e = piece('w', 5);
	e.setXpos(5);
	e.setYpos(0);
	greens.push_back(e);
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

			
			for(int k = 0; k < 3; k++){
				for (int j = 0; j < cols; j++){
					if((j+i) % 2 == 0 && k != 1){
						std::cout << "\033[7;30m       \033[0m";
					}
					else if((j+i) % 2 == 0 && k == 1){
						//this was me testing but it should woke now
						for(int l = 0; l < greens.size(); l++){
							if(greens[l].xpos == j && greens[l].ypos == i){
								std::cout << "\033[7;30m   \033[0;32m" << greens[l].id << "\033[7;30m   \033[0m";
								break;
							}
							else if(l == (greens.size()-1)) {
								std::cout << "\033[7;30m       \033[0m";
							}
						}
						//
						
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