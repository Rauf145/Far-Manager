#pragma once
#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>

using namespace std;

class FileManager
{
	string path;
public:
	FileManager(string path = "C:\\");
	//void showDirectory();
	//void findFiles(string mask);
	//void changeDirectory(string dir);
	//void remove(string path);
	//void rename(string path, string name);
};

