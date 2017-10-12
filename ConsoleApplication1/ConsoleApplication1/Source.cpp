#include <iostream>

using namespace std;

void main()
{
	int Endl = 1, Step = 2, n, count = 1, temp1 = 1, length = 2;
	cin >> n;
	for (int i = 0; i < length; i++)
	{	
		if (i == Endl)
		{
			if(count < n)
				cout << endl;
			Endl += Step;
			Step++;
			temp1++;
			if (count < n)
			{
				count++;
				length += temp1;
			}
		}
		if (temp1 != n + 1)
			cout << "*";
	}
}