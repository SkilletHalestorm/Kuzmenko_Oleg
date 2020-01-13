#include <iostream>
#include <string.h>
#include <string>
#include "windows.h"
#include <stdio.h>
#include <conio.h>
#include "Tools.h"
using namespace std;


class Field : private Draw 
{
public:
	void Create()
	{
		DrawSquare('X', 4, 5, 5);
	}
};