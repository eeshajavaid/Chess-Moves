#include "Board.h"
#include <fstream>
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "king.h"
#include "Queen.h"
#include <typeinfo>

using namespace std;
Board::Board()
{
}

Board::~Board()
{

}

void Board::Init()
{
	ifstream Rdr("Text.txt");
	char ch;
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			Rdr >> ch;
			if (ch == '-')
			{
				Ps[ri][ci] = nullptr;
			}
			else if (ch == 'P')
			{
				Ps[ri][ci] = new Pawn(Position(ri, ci), Black, this);
			}
			else if (ch == 'p')
			{
				Ps[ri][ci] = new Pawn(Position(ri, ci), White, this);
			}
			else if(ch== 'K')
			{
				Ps[ri][ci] = new Knight(Position(ri, ci), Black, this);
			}
			else if(ch == 'k')
			{
				Ps[ri][ci] = new Knight(Position(ri, ci), White, this);
			}
			else if (ch == 'B')
			{
				Ps[ri][ci] = new Bishop(Position(ri, ci), Black, this);
			}
			else if (ch == 'b')
			{
				Ps[ri][ci] = new Bishop(Position(ri, ci), White, this);
			}
			else if (ch == 'R')
			{
				Ps[ri][ci] = new Rook(Position(ri, ci), Black, this);
			}
			else if (ch == 'r')
			{
				Ps[ri][ci] = new Rook(Position(ri, ci), White, this);
			}
			else if (ch == 'W')
			{
				Ps[ri][ci] = new king(Position(ri, ci), Black, this);
			}
			else if (ch == 'w')
			{
				Ps[ri][ci] = new king(Position(ri, ci), White, this);
			}
			else if (ch == 'Q')
			{
				Ps[ri][ci] = new Queen(Position(ri, ci), Black, this);
			}
			else if (ch == 'q')
			{
				Ps[ri][ci] = new Queen(Position(ri, ci), White, this);
			}
		}
	}
}

void Board::checkPawn(Player P, Position Des)
{
	
	if ( this->PieceAt(Des.ri, Des.ci)->getchildType() =='P' && (Des.ri == 7 || Des.ri == 0))//pawn promotion
	{
		Color c;
		if (P.getColor() == Black)
			c = Black;
		else
			c = White;
		cout << "For pawn promotion enter Q for queen, R for Rook, K for knight, B for Bishop" << endl;
		char ch;
		cin >> ch;
		switch (ch)
		{
		case 'Q':
			this->SetPiece(Des.ri, Des.ci, new Queen(Des, c, this));
			break;
		case 'K':
			this->SetPiece(Des.ri, Des.ci, new Knight(Des, c, this));
			break;
		case 'B':
			this->SetPiece(Des.ri, Des.ci, new Bishop(Des, c, this));
			break;
		case 'R':
			this->SetPiece(Des.ri, Des.ci, new Rook(Des, c, this));
			break;
		}

	}
}
