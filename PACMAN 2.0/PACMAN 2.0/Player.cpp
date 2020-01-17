#include "Draw.h"
#include "Player.h"
#include "GameLoop.h"

void Player::MoveRight()
{
	if (draw.PlayGround[(playerPositionX + shift)][playerPositionY] == '\0')
	{
		RemoveSymbol('\0', playerPositionX, playerPositionY);
		playerPositionX += shift;
		DrawSymbol('O', playerPositionX, playerPositionY);
		playerPositionX = position.X;
		playerPositionY = position.Y;
	}
}
void Player::MoveLeft()
{
	if (draw.PlayGround[(playerPositionX - shift)][playerPositionY] == '\0')
	{
		RemoveSymbol('\0', playerPositionX, playerPositionY);
		playerPositionX -= shift;
		DrawSymbol('O', playerPositionX, playerPositionY);
		playerPositionX = position.X;
		playerPositionY = position.Y;
	}
}
void Player::MoveUp()
{
	if (draw.PlayGround[playerPositionX][playerPositionY - shift] == '\0')
	{
		RemoveSymbol('\0', playerPositionX, playerPositionY);
		playerPositionY -= shift;
		DrawSymbol('O', playerPositionX, playerPositionY);
		playerPositionX = position.X;
		playerPositionY = position.Y;
	}
}
void Player::MoveDown()
{
	if (draw.PlayGround[playerPositionX][playerPositionY + shift] == '\0')
	{
		RemoveSymbol('\0', playerPositionX, playerPositionY);
		playerPositionY += shift;
		DrawSymbol('O', playerPositionX, playerPositionY);
		playerPositionX = position.X;
		playerPositionY = position.Y;
	}
}
void Player::PlaceOnField(int x, int y)
{
	DrawSymbol('O', x, y);
	playerPositionX = position.X;
	playerPositionY = position.Y;
}