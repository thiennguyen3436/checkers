#include "piece.h"

piece::piece(){

}
piece::piece(char team, int idno){
	teams = team;
	canCap = false;
	id = idno;
	xpos = 1000;
	ypos = 1000;
	if(team = 'w'){
		ymovement = 1;
	}
	else if(team = 'b'){
		ymovement = -1;
	}
}
void piece::setXpos(int xposition){
	xpos = xposition;
}
void piece::setYpos(int yposition){
	ypos = yposition;
}
void piece::setCap(bool captures){
	canCap == captures;
}
piece::~piece(){

}