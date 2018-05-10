#include "piece.h"

piece::piece(char team, int idno){
	team = team;
	canCap = false;
	id = idno;
}
void piece::setXpos(int xposition){
	xpos = xposition;
}
void piece::setYpos(int yposition){
	ypos = yposition;
}
piece::~piece(){

}