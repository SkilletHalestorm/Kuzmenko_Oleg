#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
using namespace std;

char PlayGround[50][50];

class FillPlayground
{
public:
	void Fill(int x, int y)
	{
		PlayGround[x][y] = 'X';
	}
	void UnFill(int x, int y)
	{
		PlayGround[x][y] = '\0';
	}
};