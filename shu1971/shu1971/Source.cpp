#include <iostream>
using namespace std;


int main()
{
	int t;
	int a, b;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> a >> b;
			if (a & 1 && b & 1)
			{
				cout << "xyiyy\n";
			}
			else
				cout << "yaoge\n";
		}
	}
}