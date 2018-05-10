#ifndef PIECE_H
#define PIECE_H

class piece
{
protected:

public:
	piece(char team, int id);
	char team;
	int id;
	int name;
	int xpos;
	void setXpos(int xposition);
	void setYpos(int yposition);
	int ypos;
	bool canCap;
	~piece();
};
#endif //PIECE_H