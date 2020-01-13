#pragma once
#include "Tools.h"
#include <iostream>
#include <string.h>
#include <string>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
#include "Characters.h"
#include "RedGuy.h"
using namespace std;

class Field : public Draw
{
public:
	Player player;
	RedGuy redGuy;
	
	void Create()
	{		
		DrawLine(30, 40, 3, 3);
		DrawLine(30, 40, 3, 25);
		DrawPillar(30, 22, 3, 3);
		DrawPillar(30, 22, 44, 3); // playground 

		DrawLine(23, 5, 20, 12);
		DrawLine(23, 5, 20, 13);
		DrawLine(23, 5, 20, 14); // middle square

		DrawLine(23, 7, 8, 8);
		DrawLine(23, 7, 31, 8);

		DrawLine(23, 7, 8, 18);
		DrawLine(23, 7, 31, 17);

		destinationX = 23;
		destinationY = 5;
		player.PlaceOnField(destinationX, destinationY);
		redGuy.PlaceRedOnField(24,22);

	}
};