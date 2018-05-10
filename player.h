#ifndef PLAYER_H
#define PLAYER_H

class player
{
protected:

public:
	player(char team);
	piece pieces[][];
	void moves(piece pieces[][], int location[][]);
	~player();
};
#endif //PLAYER_H