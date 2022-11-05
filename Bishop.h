#pragma once
#include "Piece.h"
#include <iostream>
using namespace std;
class Bishop :
   virtual public Piece
  {
  public:
	  Bishop(Position p, Color c, Board* b) :Piece(p, c, b)
	  {
		  childtype = 'B';
	  }
	  Bishop()
	  {

	  }
	  bool IsLegal(Position Des, Player P)
	  {
		  return (__super::IsLegal(Des, P) && isDiagonalMove(this->Pos, Des)&& isDiagonalPathClear(this->Pos, Des));

	  }
	  bool isKing() 
	  {
		  return false;
	  }

	  void Print()
	  {
		  if (this->C == Black)
			  cout << "B";
		  else
			  cout << "b";
	  }
	  ~Bishop()
	  {

	  }
};

