#include "piece.h"

piece::piece(){

}
piece::piece(char team, int idno, int ymov){
	teams = team;
	canCap = false;
	id = idno;
	xpos = 1000;
	ypos = 1000;
	ymovement = ymov;
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