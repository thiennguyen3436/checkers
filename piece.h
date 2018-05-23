#ifndef PIECE_H
#define PIECE_H

class piece
{
protected:

public:
	piece(char team, int id);
	char teams;
	int id;
	int name;
	int xpos;
	int ypos;
	void setXpos(int xposition);
	void setYpos(int yposition);
	void setCap(bool captures);
	bool canCap;
	~piece();
};
#endif //PIECE_H