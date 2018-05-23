#include <iostream>
#include <vector>
#include "piece.h"
#include "player.h"
#include <utility>

extern int* ptr;
void checkCaps(player player1, int* Board){
	for(int i = 0; i < player1.List.size(); i++){
		piece a = player1.List[i];
		int j = a.xpos;
		int i = a.ypos;
		if(a.teams == 'w'){
			if(((*(Board + (j+1)*8 + i+1) == 1) && (*(Board + (j+2)*8 + i+2) == 0)) || ((*(Board + (j-1)*8 + i+1) == 1) && (*(Board + (j-2)*8 + i+2) == 0))){
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
	}
}



bool canIcap(player player){
	checkCaps(player, player.board);
	bool capturing = false;
	for(int i = 0; i < player.List.size(); i++){
		piece a = player.List[i];
		if(a.canCap == true){
			capturing = true;
			break;
		}
	}
	return capturing;
}
player::player(char team1, int cols, int* boards)
{
	board = boards;
	team = team1;
	int initpieces = (cols*6)/4;
	for(int i = 0; i < initpieces; i++){
		piece a = piece(team1, i+1);
		List.push_back(a);
	}
	int counter = 0;
	if(team == 'w'){
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
void player::move(){
	bool yeah = canIcap(*this);
	std::cout << yeah << std::endl;
}

// implementation of the default Player destructor
player::~player()
{
}