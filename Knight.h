#pragma once
#include "Piece.h"
#include <iostream>
using namespace std;
class Knight :
    public Piece
{
public:
	Knight(Position p, Color c, Board* b);
	~Knight();
	void Print();
	bool isKing()
	{
		return false;
	}
	bool IsLegal(Position Des, Player P)
	{
		if (abs(this->Pos.ri - Des.ri) == 2)		{

			if(abs(this->Pos.ci - Des.ci)==1)
				return __super::IsLegal(Des, P);
		}
		else if (abs(this->Pos.ci - Des.ci) == 2)
		{
			if (abs(this->Pos.ri - Des.ri) == 1)
				return __super::IsLegal(Des, P);
		}
		return false;
	}

};

