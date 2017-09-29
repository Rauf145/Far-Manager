#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

class Draw
{
	int button;
	short x = 1, y = 2;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	void DrawField();
	void Action();
};

