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
		attr.push_back(fileinfo.attrib & _A_SUBDIR ? "dir " : "file");
		list.push_back(fileinfo.name);
		find = _findnext(handle, &fileinfo);
	}
	if (handle != -1)
		text.Text(list, attr);
	else
		setBack(), showDirectory();
}

void FileManager::findFiles(string mask)
{
	string temp;
	_finddata_t fileinfo;
	int handle = _findfirst(this->path.c_str(), &fileinfo);
	int find = handle;
	while (find != -1)
	{
		if((fileinfo.attrib & _A_SUBDIR) && fileinfo.name[0] != '.') this->path.insert(), findFiles(mask);
		temp = fileinfo.name;
		if (temp.find(mask) && mask[0] == '*' && mask[1] == '.' && mask[2] != '*')
			findEl.push_back(fileinfo.name);
		find = _findnext(handle, &fileinfo);
	}
}

void FileManager::changeDirectory(int counter, string selected)
{
	string temp;
	int pos = 0;
	if (selected == "0")
	{
		temp += list.at(counter);
		temp.insert(0, "\\");
		if(path.length() > 1)
			this->path.insert(path.length() - 2, temp.c_str());
		else
			this->path.insert(path.length()-1, temp.c_str());
	}
	else if (selected[0] == '.')
		setBack();
	else
	{
		selected.insert(selected.length(), "\\");
		pos = this->path.find(selected);
		this->path.erase(pos, selected.length());
	}
	this->count = 0;
	list.clear();
	attr.clear();
}

int FileManager::getCount()
{
	return this->count;
}

void FileManager::setBack()
{
	int counter = 0, j = 0;
	for (int i = path.length() - 1; i > 0; i--)
	{
		if ((int)path[i] == 92 )
			counter++;
		if (counter == 2)
		{
			j = (path.length() - 1) - i, counter = (path.length() - 1) - j;
			break;
		}
	}
	path.erase(counter + 1, j - 1);
}

string FileManager::getStr(int index)
{
	string temp;
	temp = list.at(index);
	return temp;
}


