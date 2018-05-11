#include <iostream>
#include <vector>
#include "piece.h"
//this will need to include both piece lists from the players as parameters in order to add them to the board.
void drawBoard(int cols){//, player player1, player player2){
	//std::vector<piece> blues = player1.pieces;
	//std::vector<piece> greens = player2.pieces;
	std::vector<piece> blues;
	std::vector<piece> greens;
	piece a = piece('w', 1);
	a.setXpos(0);
	a.setYpos(0);
	greens.push_back(a);
	piece b = piece('w', 2);
	b.setXpos(2);
	b.setYpos(0);
	greens.push_back(b);
	piece c = piece('w', 3);
	c.setXpos(1);
	c.setYpos(1);
	greens.push_back(c);
	piece d = piece('w', 4);
	d.setXpos(0);
	d.setYpos(2);
	greens.push_back(d);
	piece e = piece('w', 5);
	e.setXpos(2);
	e.setYpos(2);
	greens.push_back(e);
	piece f = piece('b', 1);
	f.setXpos(0);
	f.setYpos(6);
	blues.push_back(f);
	piece g = piece('b', 2);
	g.setXpos(1);
	g.setYpos(7);
	blues.push_back(g);
	piece h = piece('b', 3);
	h.setXpos(1);
	h.setYpos(5);
	blues.push_back(h);
	piece i = piece('b', 4);
	i.setXpos(2);
	i.setYpos(6);
	blues.push_back(i);
	piece j = piece('b', 5);
	j.setXpos(3);
	j.setYpos(7);
	blues.push_back(j);

	greens.erase(greens.begin());


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
								std::cout << "\033[7;30m   \033[0;32m" << greens[l].id << "\033[7;30m   \033[0m";
								break;
							}
							else if(blues[l].xpos == j && blues[l].ypos == i){
								std::cout << "\033[7;30m   \033[0;34m" << blues[l].id << "\033[7;30m   \033[0m";
								break;
							}
							else if(l == (bigL-1)) {
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