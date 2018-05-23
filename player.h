#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "piece.h"
class player
{
protected:

public:
	player(char team, int boardsize, int* board);
	std::vector<piece> List;
	int* board;
	void move();
	~player();
	char team;
};
#endif //PLAYER_H