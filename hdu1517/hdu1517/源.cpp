#include<iostream>
#include<Set>
using namespace std;

int main()
{
	double nn;
	while (cin >> nn)
	{
		if (nn != 1)
		{
			while (nn >= 18)
			{
				nn /= 18;
			}

			if (nn > 9)
			{
				cout << "Ollie wins.\n";
			}
			else
			{
				cout << "Stan wins.\n";
			}
		}
		else
		{
			cout<< "Ollie wins.\n";
		}
	}
}