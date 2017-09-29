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
		//cout << (fileinfo.attrib & _A_SUBDIR ? "dir " : "file") << '\t';
		cout << "  " << fileinfo.name << '\n';
		find = _findnext(handle, &fileinfo);
	}
}

