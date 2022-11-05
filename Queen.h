#pragma once
#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"
#include<iostream>
using namespace std;
class Queen :
    public Piece//public Bishop, public Rook
{
public:
	Queen(Position p, Color c, Board* b) :Piece(p, c, b)
	{
		this->childtype = 'Q';
	}
	bool isKing()
	{
		return false;
	}
	bool IsLegal(Position Des, Player P)
	{
		//return (Bishop::IsLegal(Des, P) || Rook::IsLegal(Des, P));
		return (__super::IsLegal(Des, P) && (
			(isDiagonalMove(this->Pos, Des) && isDiagonalPathClear(this->Pos, Des))
			|| (isVerticalMove(this->Pos, Des) && isVerticalPathclear(this->Pos, Des))
			|| (isHorizontalMove(this->Pos, Des) && isHorizontalPathclear(this->Pos, Des))));
	}
	void Print()
	{
		if (this->C == Black)
			cout << "Q";
		else
			cout << "q";
	}
	~Queen()
	{

	}
};

