#include "Pawn.h"
#include<iostream>
using namespace std;
Pawn::Pawn(Position p, Color c, Board* b) :Piece(p, c, b)
{
	childtype = 'P';
}

void Pawn::Print()
{
	if (this->C == Black)
		cout << "P";
	else
		cout << "p";
}
Pawn::~Pawn()
{

}