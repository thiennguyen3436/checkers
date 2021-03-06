#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "piece.h"
#include "king.h"
#include "player.h"
#include <utility>

extern int* ptr;
void checkCaps(player &player1, int* Board){
	for(int l = 0; l < player1.List.size(); l++){
		piece a = player1.List[l];
		int j = a.xpos;
		int i = a.ypos;
		if(a.teams == 'w'){
			if(((*(Board + (j+1)*8 + i+1) == 2) && (*(Board + (j+2)*8 + i+2) == 0)) || ((*(Board + (j-1)*8 + i+1) == 2) && (*(Board + (j-2)*8 + i+2) == 0))){
				a.canCap = true;
			}
			else{
				a.canCap = false;
			}
		}
		else if(a.teams == 'b'){
			if(((*(Board + (j+1)*8 + i-1) == 1) && (*(Board + (j+2)*8 + i-2) == 0)) || ((*(Board + (j-1)*8 + i-1) == 1) && (*(Board + (j-2)*8 + i-2) == 0))){
				a.canCap = true;
			}
			else{
				a.canCap = false;
			}
		}
		std::swap(player1.List[l], a);
	}
}

void capture(player* altPlayer, int xloc, int yloc){
	for(int i = 0; i < altPlayer->List.size(); i++){
		if(altPlayer->List[i].xpos == xloc && altPlayer->List[i].ypos == yloc){
			altPlayer->List.erase(altPlayer->List.begin() + i);

			break;
		}
	}
}

bool canIcap(player player1){
	checkCaps(player1, player1.board);
	bool capturing = false;
	for(int i = 0; i < player1.List.size(); i++){
		piece a = player1.List[i];
		if(a.canCap == true){
			capturing = true;
		}
		
	}
	return capturing;
}
player::player(char team1, int cols, int* boards)
{
	board = boards;
	width = cols;
	team = team1;
	int initpieces = (cols*6)/4;
	
	int counter = 0;
	if(team == 'w'){
		for(int i = 0; i < initpieces; i++){
			piece a = piece(team1, i+1, 1);
			List.push_back(a);
		}
		intTeam = 1;
		for(int i = 0; i < cols; i++){
			for(int j = 0; j < 3; j++){
				if ((i+j) % 2 == 0){
					piece test = List[counter];
					if(test.teams == 'w'){

						test.setXpos(i);
						test.setYpos(j);
						std::swap(List[counter], test);
						counter++;
					}
				}
			}
		}
	}
	else if(team == 'b'){
		for(int i = 0; i < initpieces; i++){
			piece a = piece(team1, i+1, -1);
			List.push_back(a);
		}
		intTeam = 2;
		for(int i = 0; i < cols; i++){
			for(int j = 7; j >4; j--){
				if ((i+j) % 2 == 0){
					piece test = List[counter];
					if(test.teams == 'b'){
						test.setXpos(i);
						test.setYpos(j);
						std::swap(List[counter], test);
						counter++;
					}
				}
			}
		}
	}

}
void player::move(player* otherPlayer){
	checkCaps((*this), (*this).board);
	bool captures = canIcap(*this);
	bool your_piece = false; //checks whether you're selecting your own valid piece
	bool valid_move = false; //checks whether you've made a valid move
	int xcoor;
	int xdest;
	int ydest;
	int ycoor;
	std::string input1; //xcoor input
	std::string input2; //ycoor input
	std::string input3; //xdest input
	std::string input4; //ydest input
		while(your_piece == false){
			std::cout << "Please input the X coordinate for your piece: ";
			while(std::getline(std::cin, input1)){
				std::stringstream uinput(input1);

				if(!(uinput >> xcoor)){
					std::cout << "Please input an integer: ";
					continue;
				}
				if((xcoor > (*this).width) || (xcoor < 0)){
					std::cout << "Please input a value within the board dimensions: ";
					continue;
				}
				char extras;
				if(uinput >> extras){
					std::cout << "Only integers please :)" << std::endl;
				}
				break;
			}
			std::cout << "Please input the Y coordinate for your piece: ";
			while(std::getline(std::cin, input2)){
				std::stringstream uinput(input2);

				if(!(uinput >> ycoor)){
					std::cout << "Please input an integer: ";
					continue;
				}
				if((ycoor > 8) || (ycoor < 0)){
					std::cout << "Please input a value within the board dimensions: ";
					continue;
				}
				char extras;
				if(uinput >> extras){
					std::cout << "Only integers please :)" << std::endl;
				}
				break;
			}
			//verifies that the player is moving their own valid piece
			if(*((*this).board + xcoor*8 + ycoor) == (*this).intTeam){
				if(captures == true){
					for(int i = 0; i < (*this).List.size(); i++){
						if((*this).List[i].xpos == xcoor && (*this).List[i].ypos == ycoor){
							if((*this).List[i].canCap == true){
								your_piece = true;
							}
							else{
								std::cout << "You have a capture available!" << std::endl;
								break;
							}
						}
						else{
						}
					}

				}
				else if((*this).team == 'b'){
					if(xcoor == 0 && *((*this).board + (xcoor+1)*8 + (ycoor-1)) == (*this).intTeam){
						std::cout << "You can't move that piece!" << std::endl;
					}
					else if(xcoor == (*this).width - 1 && *((*this).board + (xcoor-1)*8 + (ycoor-1)) == (*this).intTeam){
						std::cout << "You can't move that piece!" << std::endl;
					}
					else if(*((*this).board + (xcoor+1)*8 + (ycoor-1)) == (*this).intTeam && *((*this).board + (xcoor-1)*8 + (ycoor-1)) == (*this).intTeam){
						std::cout << "You can't move that piece!" << std::endl;
					}
					else{
						your_piece = true;
					}
				}
				else if((*this).team == 'w'){
					if(xcoor == 0 && *((*this).board + (xcoor+1)*8 + (ycoor+1)) == (*this).intTeam){
						std::cout << "You can't move that piece!" << std::endl;
					}
					else if(xcoor == (*this).width - 1 && *((*this).board + (xcoor-1)*8 + (ycoor+1)) == (*this).intTeam){
						std::cout << "You can't move that piece!" << std::endl;
					}
					else if(*((*this).board + (xcoor+1)*8 + (ycoor+1)) == (*this).intTeam && *((*this).board + (xcoor-1)*8 + (ycoor+1)) == (*this).intTeam){
						std::cout << "You can't move that piece!" << std::endl;
					}
					else{
						your_piece = true;
					}
				}
			}
			else{
				std::cout << "That's not your piece!" << std::endl;
			}
		}
		piece a;
		while(valid_move == false){
			for(int i = 0; i < (*this).List.size(); i++){
				if((*this).List[i].xpos == xcoor && (*this).List[i].ypos == ycoor){
					a = (*this).List[i];
					break;
				}
			}
			if(a.ymovement == -1){ // this is movement for blue pieces
				if (captures == true){
					std::cout << "Please input the X coordinate for your destination: ";
					while(std::getline(std::cin, input3)){
						std::stringstream uinput(input3);

						if(!(uinput >> xdest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if((((xdest < xcoor - 2 ) || (xdest > xcoor + 2)) || (xdest == xdest+1) )&& (xdest < 0)){
							std::cout << "Please input a valid capture value ("<< xcoor-2 << " or " << xcoor+2 << "):";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					std::cout << "Please input the Y coordinate for your destination: ";
					while(std::getline(std::cin, input4)){
						std::stringstream uinput(input4);

						if(!(uinput >> ydest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if((ydest != ycoor - 2)){
							std::cout << "Please input a valid capture value: ";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					if(*((*this).board + xdest*8 + ydest) == 0){
						valid_move = true;
						int deltaX = (xdest-xcoor)/2;
						int deltaY = (ydest-ycoor)/2;
						for(int i = 0; i < (*this).List.size(); i++){
							if((*this).List[i].xpos == xcoor && (*this).List[i].ypos == ycoor){
								(*this).List[i].xpos = xdest;
								(*this).List[i].ypos = ydest;
								if( (*this).List[i].ypos == 0){
									piece a = king('b', (*this).List[i].xpos, 0);
									std::swap((*this).List[i], a);
								}
							}
						}
						capture(otherPlayer, xcoor+deltaX, ycoor+deltaY);
					}
				}
				//this checks whether or not you've made a valid move choice
				else{
					std::cout << "Please input the X coordinate for your destination: ";
					while(std::getline(std::cin, input3)){
						std::stringstream uinput(input3);

						if(!(uinput >> xdest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if(((xdest < xcoor - 1 ) || (xdest > xcoor + 1)) && (xdest < 0)){
							std::cout << "Please input a valid x value: ";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					std::cout << "Please input the Y coordinate for your destination: ";
					while(std::getline(std::cin, input4)){
						std::stringstream uinput(input4);

						if(!(uinput >> ydest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if((ydest != ycoor - 1)){
							std::cout << "Please input a valid y value: ";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					if(*((*this).board + xdest*8 + ydest) == 0){
						valid_move = true;
						for(int i = 0; i < (*this).List.size(); i++){
							if((*this).List[i].xpos == xcoor && (*this).List[i].ypos == ycoor){
								(*this).List[i].xpos = xdest;
								(*this).List[i].ypos = ydest;
								if( (*this).List[i].ypos == 0){
									piece a = king('b', (*this).List[i].xpos, 0);
									std::swap((*this).List[i], a);
								}
							}
						}
					}
				}
			}
			else if(a.ymovement == 1){ //this is movement for green pieces
				if (captures == true){
					std::cout << "Please input the X coordinate for your destination: ";
					while(std::getline(std::cin, input3)){
						std::stringstream uinput(input3);

						if(!(uinput >> xdest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if((((xdest < xcoor - 2 ) || (xdest > xcoor + 2)) || (xdest == xdest+1) )&& (xdest < 0)){
							std::cout << "Please input a valid capture value ("<< xcoor-2 << " or " << xcoor+2 << "):";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					std::cout << "Please input the Y coordinate for your destination: ";
					while(std::getline(std::cin, input4)){
						std::stringstream uinput(input4);

						if(!(uinput >> ydest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if((ydest != ycoor + 2)){
							std::cout << "Please input a valid capture value: ";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					if(*((*this).board + xdest*8 + ydest) == 0){
						valid_move = true;
						int deltaX = (xdest-xcoor)/2;
						int deltaY = (ydest-ycoor)/2;
						for(int i = 0; i < (*this).List.size(); i++){
							if((*this).List[i].xpos == xcoor && (*this).List[i].ypos == ycoor){
								(*this).List[i].xpos = xdest;
								(*this).List[i].ypos = ydest;
								if( (*this).List[i].ypos == 7){
									piece a = king('b', (*this).List[i].xpos, 7);
									std::cout << "This piece is now a king!" << std::endl;
									std::swap((*this).List[i], a);
								}
							}
						}
						capture(otherPlayer, xcoor+deltaX, ycoor+deltaY);
					}
				}
				//they need verification in order to say they were valid moves
				else{
					std::cout << "Please input the X coordinate for your destination: ";
					while(std::getline(std::cin, input3)){
						std::stringstream uinput(input3);

						if(!(uinput >> xdest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if(((xdest < xcoor - 2 ) || (xdest > xcoor + 2)) && (xdest < 0)){
							std::cout << "Please input a valid x value: ";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					std::cout << "Please input the Y coordinate for your destination: ";
					while(std::getline(std::cin, input4)){
						std::stringstream uinput(input4);

						if(!(uinput >> ydest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if((ydest != ycoor + 1)){
							std::cout << "Please input a valid y value: ";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					if(*((*this).board + xdest*8 + ydest) == 0){
						valid_move = true;
						for(int i = 0; i < (*this).List.size(); i++){
							if((*this).List[i].xpos == xcoor && (*this).List[i].ypos == ycoor){
								(*this).List[i].xpos = xdest;
								(*this).List[i].ypos = ydest;
								if( (*this).List[i].ypos == 7){
									piece a = king('w', (*this).List[i].xpos, 7);
									std::cout << "This piece is now a king!" << std::endl;
									std::swap((*this).List[i], a);
								}
							}
						}
					}
				}
			}
			else if(a.ymovement == 0){ //this is movement for kings
				if (captures == true){
					std::cout << "Please input the X coordinate for your destination: ";
					while(std::getline(std::cin, input3)){
						std::stringstream uinput(input3);

						if(!(uinput >> xdest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if((((xdest < xcoor - 2 ) || (xdest > xcoor + 2)) || (xdest == xdest+1)) && (xdest < 0)){
							std::cout << "Please input a valid capture value ("<< xcoor-2 << " or " << xcoor+2 << "):";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					std::cout << "Please input the Y coordinate for your destination: ";
					while(std::getline(std::cin, input4)){
						std::stringstream uinput(input4);

						if(!(uinput >> ydest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if((ydest > ycoor + 2) || (ydest < ycoor - 2) ){
							std::cout << "Please input a valid capture value: ";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					if(*((*this).board + xdest*8 + ydest) == 0){
						valid_move = true;
						int deltaX = (xdest-xcoor)/2;
						int deltaY = (ydest-ycoor)/2;
						for(int i = 0; i < (*this).List.size(); i++){
							if((*this).List[i].xpos == xcoor && (*this).List[i].ypos == ycoor){
								(*this).List[i].xpos = xdest;
								(*this).List[i].ypos = ydest;
							}
						}
						capture(otherPlayer, xcoor+deltaX, ycoor+deltaY);
					}
				}
				//they need verification in order to say they were valid moves
				else{
					std::cout << "Please input the X coordinate for your destination: ";
					while(std::getline(std::cin, input3)){
						std::stringstream uinput(input3);

						if(!(uinput >> xdest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if(((xdest < xcoor - 2 ) || (xdest > xcoor + 2)) && (xdest < 0)){
							std::cout << "Please input a valid x value: ";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					std::cout << "Please input the Y coordinate for your destination: ";
					while(std::getline(std::cin, input4)){
						std::stringstream uinput(input4);

						if(!(uinput >> ydest)){
							std::cout << "Please input an integer: ";
							continue;
						}
						if((ydest > ycoor + 1) || (ydest < ycoor - 1)){
							std::cout << "Please input a valid y value blah1: ";
							continue;
						}
						char extras;
						if(uinput >> extras){
							std::cout << "Only integers please :)" << std::endl;
						}
						break;
					}
					if(*((*this).board + xdest*8 + ydest) == 0){
						valid_move = true;
						for(int i = 0; i < (*this).List.size(); i++){
							if((*this).List[i].xpos == xcoor && (*this).List[i].ypos == ycoor){
								(*this).List[i].xpos = xdest;
								(*this).List[i].ypos = ydest;
							}
						}
					}
				}
			}
		}

	}
player::~player()
{
}