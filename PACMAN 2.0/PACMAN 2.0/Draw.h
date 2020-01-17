#pragma once
#ifndef DRAW_H
#define DRAW_H
#include "windows.h"
#include "GameLoop.h"

class Draw : protected GameLoop
{
public:
	Draw();
static	char PlayGround[50][50];
	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	void Fill(int x, int y);
	void UnFill(int x, int y);
	void DrawSymbol(char SymbolToPlace, int x, int y);
	void RemoveSymbol(char SymbolToPlace, int x, int y);
	void DrawLine(char SymbolToPlace, int length, int x, int y);
	void DrawPillar(char SymbolToPlace, int length, int x, int y);
};


#endif