#ifndef KING_H
#define KING_H

#include <string>

class king : piece
{
protected:
	
public:
	king(char team, int currentx, int currenty);
	char teams;
	int name;
	int xpos;
	int ypos;
	void setXpos(int xposition);
	void setYpos(int yposition);
	void setCap(bool captures);
	bool canCap;
	int ymovement;
	~king();
};
#endif //KING_H