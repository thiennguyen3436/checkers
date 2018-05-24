#ifndef KING_H
#define KING_H

#include <string>

class king : public piece
{
protected:
	
public:
	king(char team, int currentx, int currenty);
	~king();
};
#endif //KING_H