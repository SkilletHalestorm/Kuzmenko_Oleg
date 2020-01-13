#include <iostream>
#include <string.h>
#include <string>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
#include "GameOn.h"
#include "Menu.h"
using namespace std;

int main()
{
    /*GameStarts gameStarts;
    gameStarts.Start();*/

    Menu menuObject;
    menuObject.menu();

    /////////////////////
#pragma region MyRegion
    COORD position;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    position.X = 55;
    position.Y = 20;
    SetConsoleCursorPosition(hConsole, position);
    return 0;
#pragma endregion
}

