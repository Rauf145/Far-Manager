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
	vector<string> list;
	vector<string> attr;
	vector<string> findEl;
	vector<int> openDirs;
	string path;
	int count = 0;
public:
	FileManager(string path = "D:\\*");
	void FileManager::showDirectory();
	void findFiles(string mask);
	void changeDirectory(int counter, string selected);
	//void remove(string path);
	//void rename(string path, string name);
	void setBack();
	int getCount();
	string getStr(int index);
	void CoutFinds();
};

