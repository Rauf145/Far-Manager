#include "FileManager.h"
#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>

using namespace std;
void main()
{
	vector<string> selected[100];
	string temp;
	int buf = 0;
	FileManager fm("D:\\*");
	Draw field;
	field.DrawField();
	fm.showDirectory();
	while (true)
	{
		buf = field.Action(fm.getCount());
		if (field.getButton() == 13)
		{
			system("cls");
			if (buf != 1 || selected->size() == 0)
			{
				selected->push_back(fm.getStr(buf));
				fm.changeDirectory(buf, "0");
			}
			else if (buf == 1 && selected->size() != 0)
			{
				temp = selected->at(selected->size() - 1);
				fm.changeDirectory(buf, temp), selected->pop_back();
			}
			fm.showDirectory();
		}
	}
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