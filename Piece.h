#include "Header.h"
#include "Player.h"
#include "Board.h"

#include <fstream>
#include <iostream>
class Queen;
class Pawn;
class Bishop;
class Knight;
using namespace std;
#pragma once

class Piece
{
protected:
	Position Pos;
	Color C;
	Board* B;
	char childtype;
	bool IsMyPiece(Player P, Piece* PC)
	{
		return PC != nullptr && P.getColor() == PC->C;
	}
	
	bool isHorizontalMove(Position S, Position D)
	{
		return S.ri == D.ri ;
	}
	bool isVerticalMove(Position S, Position D)
	{
		return  S.ci == D.ci;
	}
	bool isDiagonalMove(Position S, Position D)
	{
		int row = abs(S.ri - D.ri);
		row-= abs(S.ci - D.ci);
		if (row == 0)
			return true;
		return false;
	}
	bool isHorizontalPathclear(Position S, Position D)
	{
		int start;
		int end;
	
		if (S.ci < D.ci)
		{
			end = D.ci;
			start = S.ci;
		}
		else
		{
			end = S.ci;
			start = D.ci;
		}
		for (int i = start+1; i < end; i++)
			if (B->PieceAt(S.ri,i)!=nullptr)
				return false;
		return true;
	}
	bool isVerticalPathclear(Position S, Position D)
	{
		int start;
		int end;

		if (D.ri < S.ri)
		{
			start= D.ri;
			end = S.ri;
		}
		else
		{
			start = S.ri;
			end = D.ri;
		}
		for (int i = start + 1; i < end; i++)
			if (B->PieceAt(i,S.ci) != nullptr)
				return false;
		return true;
	}
	bool isDiagonalPathClear(Position S, Position D)
	{
		if (S.ri < D.ri) // down
		{
			if (S.ci < D.ci) //right
			{
				for (int i = 1; i < D.ri; i++)
					if (B->PieceAt(S.ri + i, S.ci + i) != nullptr)
						return false;
			}
			else //left
			{
				for (int i = 1; i < D.ri; i++)
					if (B->PieceAt(S.ri + i, S.ci - i) != nullptr)
						return false;
			}
		}
		else //up
		{
			if (S.ci < D.ci) //right
			{
				for (int i = 1; i < S.ri; i++)
					if (B->PieceAt(D.ri + i, D.ci - i) != nullptr)
						return false;
			}
			else //left
			{
				for (int i = 1; i < S.ri; i++)
					if (B->PieceAt(D.ri + i, D.ci + i) != nullptr)
						return false;
			}
		}
		return true;
	}
public:
	Piece()
	{

	}
	char getchildType()
	{
		return childtype;
	}
	Piece(Position P, Color C, Board* b);
	~Piece();
	virtual bool isKing() = 0
	{
		return false;
	}
	virtual bool IsLegal(Position Des, Player P) = 0
	{
		return P.getColor() == C && !IsMyPiece(P, B->PieceAt(Des.ri, Des.ci));
	}
	void Move(Position Des, Player P)
	{
		Pawn* p;
		B->SetPiece(Des.ri, Des.ci, this);
		B->Reset(this->Pos.ri, this->Pos.ci);
		this->Pos.ri = Des.ri;
		this->Pos.ci = Des.ci;
		
	}
	virtual void Print() = 0;

};