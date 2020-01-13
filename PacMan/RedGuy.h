#pragma once
#include "Tools.h"
#include <iostream>
#include <string.h>
#include <string>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
#include "Characters.h"
using namespace std;

int betterWay = 0;
class RedGuy : public Player
{
	const int shift = 1;
	int redGuyPositionX;
	int redGuyPositionY;

public:
	void PlaceRedOnField(int x, int y)
	{
		DrawSymbol('R', x, y);
		redGuyPositionX = position.X;
		redGuyPositionY = position.Y;
	}
	int ChooseDirection()
	{		
		int choice = 0;
		if(destinationX > redGuyPositionX && destinationY > redGuyPositionY)
			choice = 1;
		if (destinationX > redGuyPositionX && destinationY < redGuyPositionY)
			choice = 2;
		if (destinationX < redGuyPositionX && destinationY < redGuyPositionY)
			choice = 3;
		if (destinationX < redGuyPositionX && destinationY > redGuyPositionY)
			choice = 4;
		if (destinationX == redGuyPositionX && destinationY > redGuyPositionY)
			choice = 5;
		if (destinationX == redGuyPositionX && destinationY < redGuyPositionY)
			choice = 6;
		if (destinationX > redGuyPositionX && destinationY == redGuyPositionY)
			choice = 7;
		if (destinationX < redGuyPositionX && destinationY == redGuyPositionY)
			choice = 8;
		return choice;
	}
	void Chase()
	{
		int direction = ChooseDirection();
		switch (direction)
		{
		case(1):
			{
			if (PlayGround[redGuyPositionX + 1][redGuyPositionY] == '\0')
				MoveRight();
			else
			AroundWayRight();
			break;
			}
		case(2):
		{
			if (PlayGround[redGuyPositionX + 1][redGuyPositionY] == '\0')
				MoveRight();
			else
			AroundWayRight();
			break;
		}
		case(3):
		{
			if (PlayGround[redGuyPositionX - 1][redGuyPositionY] == '\0')
				MoveLeft();
			else
			AroundWayLeft();
			break;
		}
		case(4):
		{
			if (PlayGround[redGuyPositionX - 1][redGuyPositionY] == '\0')
				MoveLeft();
			else
				AroundWayLeft();
			break;
		}
		case(5):
		{
			if (PlayGround[redGuyPositionX][redGuyPositionY + 1] == '\0')
				MoveDown();
			else
				AroundWayDown();
			break;
		}
		case(6):
		{
			if (PlayGround[redGuyPositionX][redGuyPositionY - 1] == '\0')
				MoveUp();
			else
				AroundWayUp();
			break;
		}
		case(7):
		{
			if (PlayGround[redGuyPositionX + 1][redGuyPositionY] == '\0')
				MoveRight();
			else
				AroundWayRight();
			break;
		}
		case(8):
		{
			if (PlayGround[redGuyPositionX - 1][redGuyPositionY] == '\0')
				MoveLeft();
			else
				AroundWayLeft();
			break;
		}
		default:
		{}
		}
	}
	void MoveDown()
	{
		if (PlayGround[redGuyPositionX][redGuyPositionY + shift] == '\0')
		{
			RemoveSymbol('\0', redGuyPositionX, redGuyPositionY);
			redGuyPositionY += shift;
			DrawSymbol('R', redGuyPositionX, redGuyPositionY);
			redGuyPositionX = position.X;
			redGuyPositionY = position.Y;
		}
		else
		{			
				AroundWayDown();
		}
	}
	void MoveRight()
	{
		if (PlayGround[(redGuyPositionX + shift)][redGuyPositionY] == '\0')
		{
			RemoveSymbol('\0', redGuyPositionX, redGuyPositionY);
			redGuyPositionX += shift;
			DrawSymbol('R', redGuyPositionX, redGuyPositionY);
			redGuyPositionX = position.X;
			redGuyPositionY = position.Y;
		}
		else
		{
			AroundWayRight();
		}
	}
	void MoveLeft()
	{
		if (PlayGround[(redGuyPositionX - shift)][redGuyPositionY] == '\0')
		{
			RemoveSymbol('\0', redGuyPositionX, redGuyPositionY);
			redGuyPositionX -= shift;
			DrawSymbol('R', redGuyPositionX, redGuyPositionY);
			redGuyPositionX = position.X;
			redGuyPositionY = position.Y;
		}
		else
		{
			AroundWayLeft();
		}
	}
	void MoveUp()
	{
		if (PlayGround[redGuyPositionX][redGuyPositionY - shift] == '\0')
		{
			RemoveSymbol('\0', redGuyPositionX, redGuyPositionY);
			redGuyPositionY -= shift;
			DrawSymbol('R', redGuyPositionX, redGuyPositionY);
			redGuyPositionX = position.X;
			redGuyPositionY = position.Y;
		}
		else
		{
			AroundWayUp();
		}
	}
	void AroundWayDown()
	{
		int XoutflankRight = redGuyPositionX; // X-point we need to get around barricade
		int XoutflankLeft = redGuyPositionX;
		int lengthRight, lengthLeft; // lengthes of the way we move to outflank barrier
		while (PlayGround[XoutflankRight][redGuyPositionY + 1] != '\0') // in this cycle we move in right direction
		{
			XoutflankRight++;
		}
		lengthRight = XoutflankRight - redGuyPositionX; // will find how long will it take to get around if we move right side
		while (PlayGround[XoutflankLeft][redGuyPositionY + 1] != '\0') // in this cycle we move in left direction
		{
			XoutflankLeft--;
		}
		lengthLeft = redGuyPositionX - XoutflankLeft; // will have to find a difference since we move to 'zero' and 'X' decreases
		if (lengthRight > lengthLeft)
		{
			betterWay = lengthLeft;
			for (int i = 0; i < betterWay; i++)
			{
				MoveLeft();
			}
			MoveDown();
		}
		else if (lengthRight < lengthLeft)
		{
			betterWay = lengthRight;
			for (int i = 0;  i < betterWay; i++)
			{
				MoveRight();
			}
			MoveDown();
		}
		else
		{
			int go;
			go = rand() % 2 + 1;
			if (go == 1)
				MoveLeft();
			else
				MoveRight();
		}
	}
	void AroundWayUp()
	{
		int XoutflankRight = redGuyPositionX; // X-point we need to get around barricade
		int XoutflankLeft = redGuyPositionX;
		int lengthRight, lengthLeft; // lengthes of the way we move to outflank barrier
		while (PlayGround[XoutflankRight][redGuyPositionY - 1] != '\0') // in this cycle we move in right direction
		{
			XoutflankRight++;
		}
		lengthRight = XoutflankRight - redGuyPositionX; // will find how long will it take to get around if we move right side
		while (PlayGround[XoutflankLeft][redGuyPositionY - 1] != '\0') // in this cycle we move in left direction
		{
			XoutflankLeft--;
		}
		lengthLeft = redGuyPositionX - XoutflankLeft; // will have to find a difference since we move to 'zero' and 'X' decreases
		if (lengthRight > lengthLeft)
		{
			betterWay = lengthLeft;
			for (int i = 0; i < betterWay; i++)
			{
				MoveLeft();
			}
			MoveUp();
		}
		else if (lengthRight < lengthLeft)
		{
			betterWay = lengthRight;
			for (int i = 0; i < betterWay; i++)
			{
				MoveRight();
			}
			MoveUp();
		}
		else
		{
			if (playerPositionX > redGuyPositionX&& playerPositionY < redGuyPositionY)
				MoveRight();
			else if (playerPositionX == redGuyPositionX && playerPositionY < redGuyPositionY)
				MoveRight();
			else if (playerPositionX < redGuyPositionX && playerPositionY < redGuyPositionY)
				MoveLeft();
		}
	}
	void AroundWayRight()
	{
		int YoutlflankUp = redGuyPositionY;
		int YoutflankDown = redGuyPositionY;
		int lengthUp, lengthDown;
		while (PlayGround[redGuyPositionX + 1][YoutlflankUp] != '\0')
		{
			YoutlflankUp++;
		}
		lengthUp = YoutlflankUp - redGuyPositionY;
		while (PlayGround[redGuyPositionX + 1][YoutflankDown] != '\0')
		{
			YoutflankDown--;
		}
		lengthDown = redGuyPositionY - YoutflankDown;
		if (lengthUp > lengthDown)
		{
			for(int i = 0; i < lengthDown; i++)
			{ 
				MoveUp();			
			}
			MoveRight();
		}
		else if (lengthUp < lengthDown)
		{
			for (int i = 0; i < lengthUp; i++)
			{
				MoveDown();
			}
			MoveRight();
		}
		else
		{
			if (destinationX > redGuyPositionX&& destinationY > redGuyPositionY)
			{
				MoveDown();
			}
			else if (destinationX > redGuyPositionX&& destinationY < redGuyPositionY)
			{
				MoveUp();
			}
			else if (destinationX > redGuyPositionX&& destinationY == redGuyPositionY)
			{
				MoveUp();
				MoveRight();
			}
		}
	}
	void AroundWayLeft()
	{
		int YoutflankUp = redGuyPositionY;
		int YoutflankDown = redGuyPositionY;
		int lengthUp, lengthDown;
		while (PlayGround[redGuyPositionX - 1][YoutflankUp] != '\0')
		{
			YoutflankUp++;
		}
		lengthUp = YoutflankUp - redGuyPositionY;
		while (PlayGround[redGuyPositionX - 1][YoutflankDown] != '\0')
		{
			YoutflankDown--;
		}
		lengthDown = redGuyPositionY - YoutflankDown;
		if (lengthUp > lengthDown)
		{
			for (int i = 0; i < lengthDown; i++)
			{
				MoveUp();
			}
			MoveLeft();
		}
		else if (lengthUp < lengthDown)
		{
			for (int i = 0; i < lengthUp; i++)
			{
				MoveDown();
			}
			MoveLeft();
		}
		else
		{
			for (int i = 0; i < lengthUp; i++)
			{
				MoveDown();
			}
			MoveLeft();
		}
	}
};
