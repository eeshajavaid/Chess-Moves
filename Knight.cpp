#include "Knight.h"

Knight::Knight(Position p, Color c, Board* b):Piece(p, c, b)
{
}


Knight::~Knight()
{
}

void Knight::Print()
{
	
		if (this->C == Black)
			cout << "K";
		else
			cout << "k";
	
}
