#include "FileManager.h"
#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>

using namespace std;
void main()
{
	string temp, mask, path = "C:\\Users\\Dzaf_ow51\\Downloads\\ab\\*", name;
	int buf = 0;
	FileManager fm("C:\\*");
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
		else if (field.getButton() == 18)
		{
			fm.Remove(path);
			path.erase(path.length() - 2, 2);
			rmdir(path.c_str());
		}
		else if (field.getButton() == 13)
		{
			//system("cls");
			if (fm.getStr(buf) != "..")
				fm.changeDirectory(buf, "0");
			else if (fm.getStr(buf) == "..")
			{
				temp = "..";
				fm.changeDirectory(buf, temp);
			}
			fm.showDirectory();
		}
			field.Text(fm.GetList(), fm.GetAttr());
	}
	//"C:\\Users\\aidin\\Desktop\\ab\\*"
	//fm.find("*.txt");
	//fm.changeDirectory("Debug");

	//string str;
	//getline(cin, str);

	////rename("text.txt", str.c_str());
	////remove(str.c_str());

	////mkdir(str.c_str());
	////rmdir(str.c_str());

	//_finddata_t fileinfo;
	//int handle = _findfirst("*", &fileinfo);
	//int find = handle;
	//int count = 0;
	//while (find != -1)
	//{
	//	count++;
	//	cout << (fileinfo.attrib & _A_SUBDIR ? "dir " : "file") << '\t';
	//	cout << fileinfo.name << '\n';
	//	find = _findnext(handle, &fileinfo);
	//}
	//cout << "\nInformation: was found " << count;
	//cout << " file(s) in folder..." << str << "\n\n";
	//_findclose(handle);
}