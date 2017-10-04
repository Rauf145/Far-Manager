#include "Draw.h"

#define Color(fg, bg) SetConsoleTextAttribute(h, bg * 16 + fg)
#define Coord(x, y) SetConsoleCursorPosition(h, { x, y })

enum Movement
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	PART = 224
};

enum Positions
{
	Name = 1,
	Size = 15,
	Type = 31,
	Attr = 46,
};

enum Color
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKCYAN,
	DARKRED,
	DARKMAGENTA,
	BROWN,
	LIGHTGREY,
	DARKGREY,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE,
	DEFAULT = 7
};

void Draw::DrawField()
{
	system("cls");
	Coord(0, 0);
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 110; j++)
		{
			Color(DEFAULT, BLUE);
			if ((i == 0 || i == 26) && (j > 0 && j < 54 || j > 54 && j < 109))
				std::cout << char(205);
			else if ((j == 0 || j == 54 || j == 109) && i > 0 && i < 26)
				std::cout << char(186);
			else if (i == 0 && j == 0)
				std::cout << char(201);
			else if (i == 26 && j == 0)
				std::cout << char(200);
			else if (i == 0 && j == 109)
				std::cout << char(187);
			else if (i == 0 && j == 54)
				std::cout << char(203);
			else if (i == 26 && j == 54)
				std::cout << char(202);
			else if (i == 26 && j == 109)
				std::cout << char(188);
			else if (i == 1 && (j >= 1 && j < 50))
			{
				Color(GREEN, BLUE);
				std::cout << " Name:         Size:          Type:          Attr:";
				Color(DEFAULT, BLACK);
				j = 50;
			}
			else
			{
				Color(DEFAULT, BLUE);
				std::cout << " ";
				Color(DEFAULT, BLACK);
			}
		}
		std::cout << std::endl;
	}
	Coord(x, y);
}

void _Define(string text, string &name, string &type)
{
	int counter = 0, j = 0, c = 0;
	char temp[255], temp1[255];
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == '.')
			counter = 1;
		else if (counter == 0)
			temp[c++] = text[i];
		else
			temp1[j++] = text[i];
	}
	temp[c] = '\0';
	temp1[j] = '\0';
	name = temp;
	type = temp1;
}

void Draw::Text(vector<string> &list, vector<string> &attr)
{
	int length;
	string name, type;
	Color(DEFAULT, BLUE);
	for (int i = 2; i < 26; i++)
		for (int j = 1; j < 53; j++)
		{
			Coord((short)j, (short)i);
			cout << " ";
		}
	length = list.size();
	if (list.size() > 24)
		length = 24;
	for (int i = 0; i < length; i++)
	{
		Color(GREEN, BLUE);
		if (list[i][0] == '.')
			name = list[i], type = "dir";
		else
			_Define(list[i], name, type);
		if (type == "")
			type = "dir";
		Coord(1, (short)i + 2);
		cout << setw(10) << left << name.substr(0, 20);
		Coord(Type, (short)i + 2);
		cout << type;
		Coord(Attr, (short)i + 2);
		cout << attr[i];
		type.clear();
	}
	Color(DEFAULT, BLACK);
	this->y = 2;
}

int Draw::Action(int count)
{
	int length;
	length = count;
	if (count > 24)
		length = 24;
	Coord(x, y);
	button = getch();
	if (button == PART)
	{
		button = getch();
		if (button == UP)
			if (y > 2)
				y--;
		if (button == DOWN)
			if (y <= length)
				y++;
	}
	Coord(x, y);
	return y - 2;
}

int Draw::getButton()
{
	return button;
}
