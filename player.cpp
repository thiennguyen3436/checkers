#include <player.h>
#include <iostream>

extern bool canICap(player player);
player::player()
{
}
//we have to use vectors so we cna have different types
void player::moves(piece pieces[][], int location[][])
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
}		

// implementation of the default Panda destructor
player::~player()
{
}