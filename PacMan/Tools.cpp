#include <iostream>
#include <string.h>
#include <string>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
using namespace std;

class Draw
{
public:
	void DrawSymbol(char SymbolToPlace, int x, int y)
	{
		COORD position;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hConsole, position);
		cout << SymbolToPlace;
	}
	void DrawSquare(char SymbolToPlace, int length, int x, int y)
	{
		for (int i = x; i < (length); i++)
		{
			DrawSymbol(SymbolToPlace, x, y);
		}

	}
};