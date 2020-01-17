#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Draw.h"
#include "GameLoop.h"

class Player : protected Draw
{
	const int shift = 1;
public:
	Draw draw;
	int playerPositionX;
	int playerPositionY;
	void PlaceOnField(int x, int y);
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
};

#endif