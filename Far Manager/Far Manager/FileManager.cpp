#include "FileManager.h"

FileManager::FileManager(string path)
{
	this->path = path;
}

void FileManager::showDirectory()
{
	string temp;
	_finddata_t fileinfo;
	int handle = _findfirst(this->path.c_str(), &fileinfo);
	int find = handle;
	while (find != -1)
	{
		count++;
		attr->push_back(fileinfo.attrib & _A_SUBDIR ? "dir " : "file");
		list->push_back(fileinfo.name);
		find = _findnext(handle, &fileinfo);
	}
	text.Text(*list, *attr);
}

void FileManager::changeDirectory(int counter, string selected)
{
	string temp;
	int pos = 0;
	if (selected == "0")
	{
		temp += list->at(counter);
		temp.insert(0, "\\");
		this->path.insert(path.length() - 2, temp.c_str());
	}
	else
	{
		selected.insert(selected.length(), "\\");
		pos = this->path.find(selected);
		this->path.erase(pos, selected.length());
	}
	this->count = 0;
	list->clear();
	attr->clear();
}

int FileManager::getCount()
{
	return this->count;
}

string FileManager::getStr(int index)
{
	string temp;
	temp = list->at(index);
	return temp;
}


