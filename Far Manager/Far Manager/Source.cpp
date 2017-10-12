#include "FileManager.h"
#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>

using namespace std;
void setcursor(bool visible) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	GetConsoleCursorInfo(console, &lpCursor);
	lpCursor.bVisible = visible;
	SetConsoleCursorInfo(console, &lpCursor);
}

void main()
{
	//setcursor(false);
	string temp, mask, path , name;
	int buf = 0;
	FileManager fm("C:\\Users\\Dzaf_ow51\\Downloads\\*");
	Draw field;
	cin >> mask;
	if (mask[0] == '*')
		mask.erase(0, 1);
	field.DrawField();
	fm.showDirectory();
	field.Text(fm.GetList(), fm.GetAttr());
	while (true)
	{
		buf = field.Action(fm.getCount());
		if (field.getButton() == 3)
		{
			fm.findFiles(mask);
			fm.CoutFinds();
			//finds.setCoord(0, 55, 2);
			//finds.Text(fm.GetFindList(), )
		}
		else if (field.getButton() == 5)
		{
			cin >> name;
			fm.Rename(fm.getStr(buf), name);
			//fm.CoutFinds();
			//rename("2.jpg", "abcd.jpg")
		}
		else if (field.getButton() == 11)
		{
			cin >> path;
			fm.Copy(path, buf);
			//fm.CoutFinds();
			//rename("2.jpg", "abcd.jpg")
		}
		else if (field.getButton() == 109)
		{
			cin.ignore();
			char* str = new char[100];
			cin.getline(str, 100);
			path += str;
			//getline(cin, path);
			fm.Move(path, buf);
			//fm.CoutFinds();
			//rename("2.jpg", "abcd.jpg")
		}
		else if (field.getButton() == 18)
		{
			fm.Remove(path);
			path.erase(path.length() - 2, 2);
			rmdir(path.c_str());
		}
		else if (field.getButton() == 13)
		{
			if (fm.getStr(buf) != "..")
				fm.changeDirectory(buf, "0");
			else if (fm.getStr(buf) == "..")
			{
				temp = "..";
				fm.changeDirectory(buf, temp);
			}
			field.setCoord(0, 1, 2);
			fm.showDirectory();
		}
		field.Text(fm.GetList(), fm.GetAttr());
	}
}