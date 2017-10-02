#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

class Draw
{
	int button;
	short x = 1, y = 2;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	void DrawField();
	void Text(string text, string attribute, short y);
	void Action();
	friend class FileManager;
};

