#include "windows.h"
#include "GameLoop.h"

int main()
{
    GameLoop gameloop;
    gameloop.Start();
    
    ////////////////////
#pragma region MyRegion
    COORD position;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    position.X = 55;
    position.Y = 20;
    SetConsoleCursorPosition(hConsole, position);
    return 0;
#pragma endregion
}