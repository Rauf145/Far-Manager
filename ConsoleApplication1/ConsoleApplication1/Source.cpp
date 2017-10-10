#include <iostream>

using namespace std;

void main()
{
	int count = 1, j = 2, n, size = 3;
	cin >> n;
	for (int i = 0; i < 10; i++)
	{	
		if (i == count)
		{
			cout << endl;
			count += j;
			j++;
		}
		cout << "*";
	}
	cout << endl;
}