#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Draw.h"

class Player : protected Draw
{
	const int shift = 1;
public:
	int playerPositionX;
	int playerPositionY;
	void PlaceOnField(int x, int y);
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
};

#endif