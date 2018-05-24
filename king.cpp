#include "piece.h"
#include "king.h"

king::king(char team, int currentx, int currenty){
	teams = team;
	canCap = false;
	xpos = currentx;
	ypos = currenty;
	ymovement = 0; //can move either forward or backwards
}
king::~king(){

}