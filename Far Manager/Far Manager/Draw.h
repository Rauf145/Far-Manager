#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <vector>
#include <iomanip>

using namespace std;

class Draw
{
	int button;
	short x = 1, y = 2, EndPlusOne = 0;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	void DrawField();
	void Text(vector<string> &list, vector<string> &attr);
	int Action(int count = 0);
	int Draw::getButton();
	friend class FileManager;
	void setCoord(int EndPlusOne, short x = 0, short y = 0);
};

