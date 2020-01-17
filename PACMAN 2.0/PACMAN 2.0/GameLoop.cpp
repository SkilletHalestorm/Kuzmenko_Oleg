#include "GameLoop.h"
#include "Player.h"
#include <conio.h>
#include "Field.h"

void GameLoop::Start()
{
	Player player;
	player.PlaceOnField(1, 1);
	Field field;
	field.CreateField();
	while (true)
	{
		if (_kbhit())
		{
			keyButton = _getch();
			switch (keyButton)
			{
			case 'd':
			{
				player.MoveRight();
				break;
			}
			case 's':
			{
				player.MoveDown();
				break;
			}
			case 'a':
			{
				player.MoveLeft();
				break;
			}
			case 'w':
			{
				player.MoveUp();
				break;
			}
			}
		}
	}
}