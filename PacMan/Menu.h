#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
#include "GameOn.h"
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};
class Menu
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
public:
	void menu()
	{
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD menuPosition;

            menuPosition.X = 25;
            menuPosition.Y = 10;
            SetConsoleCursorPosition(hConsole, menuPosition);
            cout << "START";
            menuPosition.X = 25;
            menuPosition.Y = 15;
            SetConsoleCursorPosition(hConsole, menuPosition);
            cout << "EXIT";
            char key;
            int actionToDo = 1;
            ChangeTextAttr(25, 10, White, Cyan, 30);
            ChangeTextAttr(25, 15, White, Black, 30);
            while (true)
            {
                key = _getch();
                if (key == 's') // scroll down
                {
                    ChangeTextAttr(25, 15, White, Cyan, 30);
                    ChangeTextAttr(25, 10, White, Black, 30);
                    actionToDo = 2;
                }
                else if (key == 'w') // scroll up
                {
                    ChangeTextAttr(25, 10, White, Cyan, 30);
                    ChangeTextAttr(25, 15, White, Black, 30);
                    actionToDo = 1;
                }
                else if (key == 13 && actionToDo == 1)
                {
                    system("cls");
                    GameStarts gameStarts;
                    gameStarts.Start();
                }
                else if (key == 13 && actionToDo == 2)
                {
                    return;
                }
            }
        
	}
    void ShowCursor(bool visible)
    {
        CONSOLE_CURSOR_INFO cci = { sizeof(cci), visible };
        SetConsoleCursorInfo(hStdOut, &cci);
    }
    void SetColor(ConsoleColor text, ConsoleColor background) // Устанавливает цвет символов и фона
    {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    void ChangeTextAttr(int X, int Y, ConsoleColor text, ConsoleColor background, unsigned Len) // Меняет текстовые атрибуты, начиная с заданной позиции
    {
        COORD coord = { (SHORT)X, (SHORT)Y };
        DWORD dwDummy;
        FillConsoleOutputAttribute(hStdOut, (WORD)((background << 4) | text), Len, coord, &dwDummy);
    }
};