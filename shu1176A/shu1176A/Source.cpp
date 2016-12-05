#include<iostream>
using namespace std;
int main()
{
	int a, b;
	int t;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> a >> b;
			if (b == 0)
			{
				cout << a << endl;
				continue;
			}
			if (a == 2)
			{
				if (b & 1)
					cout << 1 << endl;
				else
				{
					cout << 2 << endl;
				}
			}
			else if (b & 1)
			{
				cout << 2 << endl;
			}
			else
			{
				cout << 1 << endl;
			}
		}
	}
}