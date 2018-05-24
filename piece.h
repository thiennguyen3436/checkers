#ifndef PIECE_H
#define PIECE_H

class piece
{
public:
	piece();
	piece(char team, int id, int ymov);
	char teams;
	int id;
	int name;
	int xpos;
	int ypos;
	int ymovement;
	void setXpos(int xposition);
	void setYpos(int yposition);
	void setCap(bool captures);
	bool canCap;
	~piece();
};
#endif //PIECE_H