#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "piece.h"
class player
{
protected:

public:
	player(char team, int boardsize);
	std::vector<piece> List;
	//void moves(piece pieces[][], int location[][]);
	~player();
	char team;
};
#endif //PLAYER_H