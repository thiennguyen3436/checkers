#ifndef PIECE_H
#define PIECE_H

class piece
{
protected:

public:
	piece(char team);
	int xpos;
	char team;
	int ypos;
	bool canCap;
	void move(bool canCap);
	~piece();
};
#endif //PIECE_H