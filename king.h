#ifndef KING_H
#define KING_H

#include <string>

class king : public piece
{
protected:
	
public:
	king(int xpos, int ypos);
	int xpos;
	int ypos;
	bool canCap;
	void move(bool canCap);
	~king();
};
#endif //KING_H