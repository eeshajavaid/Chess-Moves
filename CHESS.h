#pragma once
#include <stdlib.h>
#include <iomanip>
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Header.h"
#include<conio.h>
#include <ctime>
#include <thread>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
using namespace std;
class CHESS
{
	Board B;
	Player Ps[2];
	int Turn;
public:
	int hrs = 0;
	int mins = 0;
	int sec = 0;
	void showClk() {
		gotoRowCol(15, 0);
		cout <<"\r" << "| " << setfill('0') << setw(2) << hrs << " Hours | " << setfill('0') << setw(2) << mins << " Minutes | " << setfill('0') << setw(2) << sec << " Seconds |" << endl;
	}
	void EndGame()
	{
		system("cls");
		cout << "Time's up" << endl;
	}
	void systemCallTimer() {
		int i = 0;
		showClk();
		{
			Sleep(10);
			i++;
		if (mins == 10)
			EndGame();
		sec++;
		if (sec == 60) {
			mins++;
			if (mins == 60) {
				hrs++;
				mins = 0;
			}
			sec = 0;
		}
	}
	}
	CHESS();
	~CHESS();
	void Init()
	{
		B.Init();
		cout << "Player 1 and Player 2" << endl;
		for (int i = 0; i < 2; i++)
		{
			string s;
			cin >> s;
			Ps[i].setName(s);
		}
	}
	void DisplayBoard()
	{
		system("cls");
		for (int ri = 0; ri < 8; ri++)
		{
			for (int ci = 0; ci < 8; ci++)
			{
				if (B.PieceAt(ri, ci) == nullptr)
				{
					cout << "-";
				}
				else
					B.PieceAt(ri, ci)->Print();
			}
			cout << endl;
		}
	}
	void getRowColbyLeftClick(int& rpos, int& cpos)
	{
		HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
		DWORD Events;
		INPUT_RECORD InputRecord;
		SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
		do
		{
			ReadConsoleInput(hInput, &InputRecord, 1, &Events);
			if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
				rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
				break;
			}
		} while (true);
	}
	void gotoRowCol(int rpos, int cpos)
	{
		COORD scrn;
		HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
		scrn.X = cpos;
		scrn.Y = rpos;
		SetConsoleCursorPosition(hOuput, scrn);
	}
	void TurnChange()
	{
		if (Turn == Black)
			Turn = White;
		else
			Turn = Black;
	}
	void Play()
	{
		Turn = Black;
		Ps[0].setColor(Black);
		Ps[1].setColor(White);
		Position Src, Dst;
		
		do
		{
			DisplayBoard();
			systemCallTimer();
			//TurnMsg(Ps[Turn].getName())
			cin >> Src.ri >> Src.ci;
			cin >> Dst.ri >> Dst.ci;
			if (B.PieceAt(Src.ri, Src.ci) == nullptr)
			{
				cout << "Select a Piece to move" << endl;
				_getch();
			}
			else if (B.PieceAt(Src.ri, Src.ci)->IsLegal(Dst, Ps[Turn]))
			{
				B.PieceAt(Src.ri, Src.ci)->Move(Dst, Ps[Turn]);
				B.checkPawn(Ps[Turn], Dst);
				TurnChange();
			}
			else
			{
				cout << "Illegal Move... Try Again";
				_getch();
			}
			
		} while (true);

	}
};

