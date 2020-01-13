#pragma once
#include "Tools.h"
#include <iostream>
#include <string.h>
#include <string>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
using namespace std;

int destinationX, destinationY;
class Unit
{
public:
	virtual ~Unit() {};
	virtual void PlaceOnField(int x, int y) = 0;
	virtual void MoveRight() = 0;
	virtual void MoveDown() = 0;
	virtual void MoveLeft() = 0;
	virtual void MoveUp() = 0;
};

class Player : public Draw, public Unit
{
private:
	const int shift = 1;
public:
	int playerPositionX;
	int playerPositionY;
	void PlaceOnField(int x, int y)
	{
		DrawSymbol('O', x, y);
		playerPositionX = position.X;
		playerPositionY = position.Y;
	}
	void MoveRight()
	{
		if (PlayGround[(playerPositionX + shift)][playerPositionY] == '\0')
		{
			RemoveSymbol('\0', playerPositionX, playerPositionY);
			playerPositionX += shift;
			DrawSymbol('O', playerPositionX, playerPositionY);
			playerPositionX = position.X;
			playerPositionY = position.Y;
			destinationX = playerPositionX;
			destinationY = playerPositionY;
		}
	}
	void MoveDown()
	{
		if (PlayGround[playerPositionX][playerPositionY + shift] == '\0')
		{
			RemoveSymbol('\0', playerPositionX, playerPositionY);
			playerPositionY += shift;
			DrawSymbol('O', playerPositionX, playerPositionY);
			playerPositionX = position.X;
			playerPositionY = position.Y;
			destinationX = playerPositionX;
			destinationY = playerPositionY;
		}
	}
	void MoveLeft()
	{
		if (PlayGround[(playerPositionX - shift)][playerPositionY] == '\0')
		{
			RemoveSymbol('\0', playerPositionX, playerPositionY);
			playerPositionX -= shift;
			DrawSymbol('O', playerPositionX, playerPositionY);
			playerPositionX = position.X;
			playerPositionY = position.Y;
			destinationX = playerPositionX;
			destinationY = playerPositionY;
		}
	}
	void MoveUp()
	{
		if (PlayGround[playerPositionX][playerPositionY - shift] == '\0')
		{
			RemoveSymbol('\0', playerPositionX, playerPositionY);
			playerPositionY -= shift;
			DrawSymbol('O', playerPositionX, playerPositionY);
			playerPositionX = position.X;
			playerPositionY = position.Y;
			destinationX = playerPositionX;
			destinationY = playerPositionY;
		}
	}
};