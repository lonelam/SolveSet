#include<iostream>
#include<cmath>
using namespace std;
int main()
{

	int t;
	int k;
	double n;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n;

			int n0 = floor(sqrt(2 * n - 2));
			int n1 = n0 + 1;
			if (abs(n0 * n1 - 2 * n + 2) < 1e-6)
			{
				cout << 2 << endl;
			}
			else
			{
				cout << 3 << endl;
			}
		}
	}
}