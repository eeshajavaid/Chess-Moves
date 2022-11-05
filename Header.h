#pragma once
enum Color { Black, White };
struct Position
{
	int ri, ci;
	Position()
	{

	}
	Position(int r, int c)
	{
		ri = r;
		ci = c;
	}
};