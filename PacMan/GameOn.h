#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
#include "Field.h"

class GameStarts
{
	char keyButton;
	int betterWayInMain;
public:
	void Start()
	{
		Field GetStarted;
		GetStarted.Create();
		while (true)
		{
			if (_kbhit())
			{
				keyButton = _getch();
				switch (keyButton)
				{
				case 'd':
				{
					GetStarted.player.MoveRight();
					break;
				}
				case 's':
				{
					GetStarted.player.MoveDown();
					break;
				}
				case 'a':
				{
					GetStarted.player.MoveLeft();
					break;
				}
				case 'w':
				{
					GetStarted.player.MoveUp();
					break;
				}
				}
			}			
						GetStarted.redGuy.Chase();
				Sleep(300);
		}
	}
};