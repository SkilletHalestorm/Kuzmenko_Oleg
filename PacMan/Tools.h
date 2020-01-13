#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
#include "FillPlayfground.h"
using namespace std;

FillPlayground fillWithSymbol;
COORD position;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Draw : public FillPlayground
{
public:
	void DrawSymbol(char SymbolToPlace, int x, int y)
	{
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hConsole, position);
		cout << SymbolToPlace;
		fillWithSymbol.Fill(x, y);
	}
	void RemoveSymbol(char SymbolToPlace, int x, int y)
	{
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hConsole, position);
		cout << SymbolToPlace;
		fillWithSymbol.UnFill(x, y);
	}
	void DrawLine(char SymbolToPlace, int length, int x, int y)
	{
		for (int i = 0; i <= length; i++)
		{
			DrawSymbol(SymbolToPlace, x, y);
			x++;
		}
	}
	void DrawPillar(char SymbolToPlace, int length, int x, int y)
	{
		for (int i = 0; i <= length; i++)
		{
			DrawSymbol(SymbolToPlace, x, y);
			y++;
		}
	}
};