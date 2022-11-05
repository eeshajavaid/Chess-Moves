#pragma once
#include "Piece.h"
#include <iostream>
using namespace std;
class Pawn : public Piece
{
	bool firstmove = true;
public:
	Pawn(Position p, Color c, Board* b);
	~Pawn();
	void Print();
	bool IsLegal(Position Des, Player P)
	{
		
		if (isVerticalMove(this->Pos, Des))
		{	
			Position temp;
			temp.ci = Des.ci;
			temp.ri = -1;
			if (P.getColor() == Black)
			{
					
				if (firstmove && Des.ri == (this->Pos.ri + 2) || Des.ri == (this->Pos.ri + 1))
				{
					
					temp.ri = Des.ri + 1;
					firstmove = false;
				}
				else if ( Des.ri == (this->Pos.ri + 1))
				{
						temp.ri = Des.ri + 1;
		
				}	
				}
			else
			{

					if (firstmove && Des.ri == (this->Pos.ri - 2))
					{
						temp.ri = Des.ri - 1;;
						firstmove = false;
					}
					else if (firstmove || Des.ri == this->Pos.ri - 1)
					{
						temp.ri = Des.ri - 1;
					}

			}
			if(temp.ri !=-1)
				return isVerticalPathclear(this->Pos, temp) && __super::IsLegal(Des, P);
		}
		else if (isDiagonalMove(this->Pos, Des))
		{
			if (P.getColor()== Black)
			{
				cout << "black";
				if ((this->Pos.ri + 1) == Des.ri)
				{
					if (B->PieceAt(Des.ri, Des.ci) != nullptr)
						return __super::IsLegal(Des, P);
				}
			}
			else
			{
				if ((this->Pos.ri - 1) == Des.ri)
				{
					cout << "white";
					if (B->PieceAt(Des.ri, Des.ci) != nullptr)
						return __super::IsLegal(Des, P);
				}

			}
		}
		return false;
	}
	bool isKing()
	{
		return false;
	}
};