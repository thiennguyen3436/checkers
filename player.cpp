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
		//the moves should be stored as a piece with available moves stored as integers referring to specific squares
	}
	else{
		//show the moves that can be made and make the user pick one
	}
}		

// implementation of the default Panda destructor
Panda::~Panda()
{
}