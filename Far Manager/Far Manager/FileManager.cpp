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
	string temp, buffer;
	int counter = 0;
	_finddata_t fileinfo;
	int handle = _findfirst(this->path.c_str(), &fileinfo);
	int find = handle;
	while (find != -1)
	{
		if ((fileinfo.attrib & _A_SUBDIR) && fileinfo.name[0] != '.')
		{
			buffer += "\\";
			buffer += fileinfo.name;
			openDirs.push_back(counter);
			this->path.insert(path.length() - 2, buffer);
			findFiles(mask);
			counter = openDirs.at(openDirs.size() - 1);
			openDirs.pop_back();
			setBack();
			handle = _findfirst(this->path.c_str(), &fileinfo);
			find = handle;
			buffer.clear();
			for (int i = 0; i < counter; i++)
				find = _findnext(handle, &fileinfo);
		}
		temp = fileinfo.name;
		if (temp.find(mask))
			findEl.push_back(fileinfo.name);
		find = _findnext(handle, &fileinfo);
		counter++;
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
		if (path.length() > 1)
			this->path.insert(path.length() - 2, temp.c_str());
		else
			this->path.insert(path.length() - 1, temp.c_str());
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
		if ((int)path[i] == 92)
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

void FileManager::CoutFinds()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	string temp;
	for (int j = 0; j < this->findEl.size(); j++)
	{
		SetConsoleCursorPosition(h, { 55, short(j) + 1});
		temp = this->findEl.at(j);
		cout << temp << endl;
	}
}


