#include <iostream>
//this will need to include both piece lists from the players as parameters in order to add them to the board.
void drawBoard(int cols){
	if(cols % 4 != 0){
		std::cout << "Please enter a multiple of 4" << std::endl;
	}
	else{
		for(int i = 0; i < 8; i ++){
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
			for (int j = 0; j < cols; j++){
				if((j+i) % 2 == 0){
					std::cout << "\033[7;30m#######\033[0m";
				}
				else{
					std::cout << "#######";
				}
			}
			std::cout << "" << std::endl;
			for(int k = 0; k < 3; k++){
				for (int j = 0; j < cols; j++){
					if((j+i) % 2 == 0){
						std::cout << "\033[7;30m#     #\033[0m";
					}
					else{
						std::cout << "#     #";
					}
				}
				if(k == 1){
					std::cout << " " << i+1;
				}
				std::cout << "" << std::endl;
			}
			for (int j = 0; j < cols; j++){
				if((j+i) % 2 == 0){
					std::cout << "\033[7;30m#######\033[0m";
				}
				else{
					std::cout << "#######";
				}
			}
			std::cout << "" << std::endl;
		}
	}
}