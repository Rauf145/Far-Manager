#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

class Draw
{
	int button;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	void DrawField();
};

