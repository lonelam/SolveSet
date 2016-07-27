#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, b, n, m, res;
	while (cin >> n >> m)
	{
		res = 0;
		while (n--)
		{
			cin >> a >> b;
			res ^= abs(a - b) - 1;
		}
		if (res == 0)
		{
			cout << "BAD LUCK!\n";
		}
		else
		{
			cout << "I WIN!\n";
		}
	}
}