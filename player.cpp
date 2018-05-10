#include <player.h>
#include <iostream>

extern bool canICap(player player);
player::player()
{
}

void player::moves(piece pieces[][], int location[][])
{
	if(canIcap(*this)){
		//show the captures that are available
	}
	else{
		//show the moves that can be made and make the user pick one
	}
}		

// implementation of the default Panda destructor
Panda::~Panda()
{
}