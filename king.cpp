#include "piece.h"
#include "king.h"

king::king(char team, int currentx, int currenty){
	teams = team;
	canCap = false;
	xpos = currentx;
	ypos = currenty;
	ymovement = 0;
}
void king::setXpos(int xposition){
	xpos = xposition;
}
void king::setYpos(int yposition){
	ypos = yposition;
}
void king::setCap(bool captures){
	canCap == captures;
}
king::~king(){

}