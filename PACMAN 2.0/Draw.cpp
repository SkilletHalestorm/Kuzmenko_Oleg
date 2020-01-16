#include <iostream>
#include "windows.h"
#include "Draw.h"
using namespace std;

	void Draw::Fill(int x, int y)
	{
		PlayGround[x][y] = 'X';
	}
	void Draw::UnFill(int x, int y)
	{
		PlayGround[x][y] = '\0';
	}
	void Draw::DrawSymbol(char SymbolToPlace, int x, int y)
	{
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hConsole, position);
		cout << SymbolToPlace;
		Fill(x, y);
	}
	void Draw::RemoveSymbol(char SymbolToPlace, int x, int y)
	{
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hConsole, position);
		cout << SymbolToPlace;
		UnFill(x, y);
	}
	void Draw::DrawLine(char SymbolToPlace, int length, int x, int y)
	{
		for (int i = 0; i <= length; i++)
		{
			DrawSymbol(SymbolToPlace, x, y);
			x++;
		}
	}
	void Draw::DrawPillar(char SymbolToPlace, int length, int x, int y)
	{
		for (int i = 0; i <= length; i++)
		{
			DrawSymbol(SymbolToPlace, x, y);
			y++;
		}
	}
