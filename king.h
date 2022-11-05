#pragma once
#include "Piece.h"
#include <iostream>
using namespace std;
class king :
    public Piece
{
public:
	king(Position p, Color c, Board* b) :Piece(p, c, b)
	{
		childtype = 'W';
	}
	bool isKing()
	{
		return true;
	}
	bool IsLegal(Position Des, Player P)
	{
		if(abs(this->Pos.ri - Des.ri) ==1 || abs(this->Pos.ci - Des.ci)==1)
			return __super::IsLegal(Des, P) && ( isVerticalMove(this->Pos, Des) || isHorizontalMove(this->Pos, Des) || isDiagonalMove(this->Pos, Des));
		return false;

	}
	void Print()
	{
		if (this->C == Black)
			cout << "W";
		else
			cout << "w";
	}
	~king()
	{

	}
};

