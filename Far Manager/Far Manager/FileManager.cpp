#include "FileManager.h"

FileManager::FileManager(string path)
{
	this->path = path;
}

void FileManager::showDirectory()
{
	_finddata_t fileinfo;
	int handle = _findfirst(this->path.c_str(), &fileinfo);
	int find = handle;
	int count = 0;
	while (find != -1)
	{
		count++;
		text.Text(fileinfo.name,(fileinfo.attrib & _A_SUBDIR ? "dir " : "file"), count + 1);
		find = _findnext(handle, &fileinfo);
	}
}

