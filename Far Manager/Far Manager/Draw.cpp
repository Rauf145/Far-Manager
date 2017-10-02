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
	Type = 30,
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
			if (i == 0 || j == 0 || i == 26 || j == 109 || j == 54)
				std::cout << char(219);
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
	int counter = 0, j = 0;
	char temp[20], temp1[20];
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == '.')
			counter = 1;
		else if (counter == 0)
			temp[i] = text[i];
		else
			temp1[j++] = text[i];
	}
	name = temp;
	//name[name.length()] = '\0';
	name += '\0';
	type = temp1;
	//type[type.length()] = '\0';
	type += '\0';
}

void Draw::Text(string text, string attribute, short y)
{
	string name, type;
	if (text[0] != '.')
		_Define(text, name, type);
	if (text[0] == '.')
		name = text, type = "dir";
	Coord(1, y);
	Color(GREEN, BLUE);
	std::cout << name;
	Coord(Type, y);
	cout << type;
	Coord(Attr, y);
	cout << attribute;
	Color(DEFAULT, BLACK);
}

void Draw::Action()
{
	button = getch();
	if (button == PART)
	{
		button = getch();
		if (button == UP)
			if (y > 2)
				y--;
		if (button == DOWN)
			if (y < 25)
				y++;
	}
	Coord(x, y);
}
