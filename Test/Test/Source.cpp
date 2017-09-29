#include <iostream>
#include <direct.h>
#include <io.h>
using namespace std;

void main()
{
	_finddata_t fileinfo;
	int handle = _findfirst("*", &fileinfo);
	int find = handle;
	int count = 0;
	while (find != -1)
	{
		count++;
		cout << (fileinfo.attrib & _A_SUBDIR ? "dir " : "file") << '\t';
		cout << fileinfo.name << '\n';
		find = _findnext(handle, &fileinfo);
	}
}