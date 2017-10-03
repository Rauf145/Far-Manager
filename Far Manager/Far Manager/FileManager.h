#pragma once
#include <iostream>
#include <string>
#include <direct.h>
#include "Draw.h"
#include <vector>
#include <io.h>

using namespace std;

class FileManager
{
	Draw text;
	vector<string> list[100];
	vector<string> attr[100];
	string path;
	int count = 0;
public:
	FileManager(string path = "D:\\*");
	void FileManager::showDirectory();
	//void findFiles(string mask);
	void changeDirectory(int counter, string selected);
	//void remove(string path);
	//void rename(string path, string name);
	int getCount();
	string getStr(int index);
};

