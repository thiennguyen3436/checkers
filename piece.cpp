#include "piece.h"

piece::piece(char team, int idno){
	team = team;
	canCap = false;
	id = idno;
	xpos = 1000;
	ypos = 1000;
}
void piece::setXpos(int xposition){
	xpos = xposition;
}
void piece::setYpos(int yposition){
	ypos = yposition;
}
piece::~piece(){

}