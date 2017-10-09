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
		setBack(this->path), showDirectory();
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
			setBack(this->path);
			handle = _findfirst(this->path.c_str(), &fileinfo);
			find = handle;
			buffer.clear();
			for (int i = 0; i < counter; i++)
				find = _findnext(handle, &fileinfo);
		}
		temp = fileinfo.name;
		if (temp.find(mask) != 4294967295)
			findEl.push_back(fileinfo.name);
		else if (mask[0] == '.' && mask[1] == '*' && !(fileinfo.attrib & _A_SUBDIR))
			findEl.push_back(fileinfo.name);
		else if (mask.c_str()[0] == '?')
		{
			for (int j = 0; j < mask.length(); j++)
				if (mask[j] != '?')
					buffer.push_back(mask.c_str()[j]);
			if (temp.find(buffer) != 4294967295 && temp.length() == mask.length())
				findEl.push_back(fileinfo.name);
			buffer.clear();
		}
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
		setBack(this->path);
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

void FileManager::Remove(string path)
{
	string temp, buffer;
	int counter = 0, code = 0;
	_finddata_t fileinfo;
	int handle = _findfirst(path.c_str(), &fileinfo);
	int find = handle;
	//while (find != -1)
	//{
	//	if ((fileinfo.attrib & _A_SUBDIR) && fileinfo.name[0] != '.')
	//	{
	//		buffer += "\\";
	//		buffer += fileinfo.name;
	//		openDirs.push_back(counter );
	//		path.insert(path.length() - 2, buffer);
	//		Remove(path);
	//		_findclose(handle);
	//		counter = openDirs.at(openDirs.size() - 1);
	//		openDirs.pop_back();
	//		temp = path;
	//		temp.erase(temp.length() - 2, 2);
	//		code = rmdir(temp.c_str());
	//		setBack(path);
	//		handle = _findfirst(path.c_str(), &fileinfo);
	//		find = handle;
	//		buffer.clear();
	//		for (int i = 0; i < counter; i++)
	//			find = _findnext(handle, &fileinfo);
	//		cout << code;
	//	}
	//	temp.clear();
	//	temp += path;
	//	temp.erase(temp.length() - 1, 1);
	//	temp += fileinfo.name;
	//	if (fileinfo.name[0] != '.' && !(fileinfo.attrib & _A_SUBDIR))
	//		remove(temp.c_str()) != 0;
	//	find = _findnext(handle, &fileinfo);
	//	counter++;
	//	temp.clear();
	//}
	while (find != -1)
	{
			if ((fileinfo.attrib & _A_SUBDIR) && fileinfo.name[0] != '.')
			{
				buffer += "\\";
				buffer += fileinfo.name;
				openDirs.push_back(counter );
				path.insert(path.length() - 2, buffer);
				Remove(path);
				counter = openDirs.at(openDirs.size() - 1);
				openDirs.pop_back();
				setBack(path);
				handle = _findfirst(path.c_str(), &fileinfo);
				find = handle;
				buffer.clear();
				for (int i = 0; i < counter; i++)
					find = _findnext(handle, &fileinfo);
				cout << code;
			}
			temp.clear();
			temp += path;
			temp.erase(temp.length() - 1, 1);
			temp += fileinfo.name;
			if (fileinfo.name[0] != '.' && !(fileinfo.attrib & _A_SUBDIR))
				remove(temp.c_str()) != 0;
			find = _findnext(handle, &fileinfo);
			counter++;
	}
	temp = path;
	temp.erase(temp.length() - 2, 2);
	code = rmdir(temp.c_str());
	cout << code;
}

void FileManager::Rename(string path, string name)
{
	string tempForPath, tempForNewName;
	tempForPath = this->path;
	tempForPath.erase(tempForPath.length() - 1, 1);
	tempForNewName = tempForPath;
	tempForNewName += name;
	tempForPath += path;
	rename(tempForPath.c_str(), tempForNewName.c_str());
}

int FileManager::getCount()
{
	return this->count;
}

void FileManager::setBack(string &path)
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

void FileManager::Copy(string path2, int index)
{
	string buffer, temp, temp1;
	temp1 = path2;
	temp1 += list[index];
	//if (attr[index] == "dir")
	//{
	//	mkdir(temp1.c_str());
	//	temp += this->path;
	//	temp += "\\";
	//	temp += list[index];
	//	openDirs.push_back(counter);
	//	path.insert(path.length() - 2, buffer);

	//}
	//else
	//{
		temp += this->path;
		temp.erase(temp.length() - 1, 1);
		temp += list[index];
		ifstream fin(temp, ios::binary);
		ofstream fout(path2 += list[index], ios::binary);
		while (!fin.eof())
		{
			getline(fin, buffer);
			fout << buffer << endl;
		}
		fin.close();
		fout.close();
	//}
	temp1.clear();
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
		SetConsoleCursorPosition(h, { 55, short(j) + 1 });
		temp = this->findEl.at(j);
		cout << temp << endl;
	}
}


