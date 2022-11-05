#pragma once
#include "Piece.h"
#include <iostream>
using namespace std;
class Rook :
    virtual public Piece
{
public:
	Rook(Position p, Color c, Board* b) :Piece(p, c, b)
	{
		childtype = 'R';
	}
	Rook()
	{

	}
	bool isKing()
	{
		return false;
	}
	bool IsLegal(Position Des, Player P)
	{
		bool flag = __super::IsLegal(Des, P);
		return flag &&( (isVerticalMove(this->Pos, Des) && isVerticalPathclear(this->Pos, Des)) || (isHorizontalMove(this->Pos, Des) && isHorizontalPathclear(this->Pos, Des)));
	}

	void Print()
	{
		if (this->C == Black)
			cout << "R";
		else
			cout << "r";
	}
	~Rook()
	{

	}
};

