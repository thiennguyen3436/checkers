#include <iostream>
#include <vector>
#include "piece.h"
#include "player.h"
#include <utility>

extern bool canICap(player player);
player::player(char team1, int cols)
{
	team = team1;
	int initpieces = (cols*6)/4;
	for(int i = 0; i < initpieces; i++){
		piece a = piece(team1, i+1);
		List.push_back(a);
	}
	int counter = 0;
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
				else if(team == 'b'){
					test.setXpos(i);
					test.setYpos(7-j); 
					counter++;
				}

			}
		}
	}

}
//we have to use vectors so we cna have different types
/*void player::moves(piece pieces[][], int location[][])
{
	if(canIcap(*this)){
		//show the captures that are available
		
		//possible moves can be stored in pairs with a letter denoting the move and move as the second option of the pair
		//the move itself can be a pair with a piece and a location
		
		//the moves should be stored as a piece with available moves stored as integers referring to specific squares
	}
	else{
		//show the moves that can be made and make the user pick one
	}
}*/		

// implementation of the default Player destructor
player::~player()
{
}