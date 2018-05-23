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
	int width;
	int* board;
	void move(player* altPlayer);
	~player();
	char team;
	int intTeam;
};
#endif //PLAYER_H