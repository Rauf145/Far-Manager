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
	string name, type;
	for (int i = 0; i < list.size(); i++)
	{
		Color(GREEN, BLUE);
		if (list[0][0] != '.')
			_Define(list[i], name, type);
		else if (list[0][0] == '.')
			name = list[i], type = "dir";
		if (type == "")
			type = "dir";
		Coord(1, (short)i + 2);
		cout << name;
		Coord(Type, (short)i + 2);
		cout << type;
		Coord(Attr, (short)i + 2);
		cout << attr[i];
	}
	Color(DEFAULT, BLACK);
}

int Draw::Action(int count)
{
	button = getch();
	if (button == PART)
	{
		button = getch();
		if (button == UP)
			if (y > 2)
				y--;
		if (button == DOWN)
			if (y < count + 1)
				y++;
	}
	Coord(x, y);
	return y - 2;
}

int Draw::getButton()
{
	return button;
}
