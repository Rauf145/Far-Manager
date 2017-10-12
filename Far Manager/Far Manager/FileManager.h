#pragma once
#include <iostream>
#include <string>
#include <direct.h>
#include "Draw.h"
#include <vector>
#include <io.h>
#include <sstream>
#include <fstream>

using namespace std;

class FileManager
{
	//Draw text;
	vector<string> list;
	vector<string> attr;
	vector<string> findEl;
	string path;
	int count = 0;
public:
	FileManager(string path = "D:\\*");
	void showDirectory();
	void findFiles(string mask);
	void changeDirectory(int counter, string selected);
	void Remove(string path);
	void Rename(string path, string name);
	void Copy(string path2, int index);
	void Move(string path2, int index);
	void setBack(string &path);
	int getCount();
	void CoutFinds();
	string getStr(int index);
	vector<string> GetList();
	vector<string> GetAttr();
};

