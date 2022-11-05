class Piece;

#include "Player.h"

using namespace std;

#pragma once
class Board {
	Piece* Ps[8][8];

public:
	Board();
	~Board();
   
	
	void Init();
	Piece* PieceAt(int ri, int ci)
	{
		return Ps[ri][ci];
	}
	void Reset(int ri, int ci)
	{
		Ps[ri][ci] = nullptr;
	}
	void SetPiece(int ri, int ci, Piece* P)
	{
		Ps[ri][ci] = P;
	}
	void checkPawn(Player P, Position Des);
};