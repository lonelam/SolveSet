#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-6;
ld f(ld x, ld y)
{
	ld x2 = x * 2;
	ld x6 = x2 * x2 * x2;
	return 6 * x6 * x + 8 * x6 + 7 * x * x2 + 5 * x2 - y * x;
}
ld df(ld x, ld y)
{
	ld x2 = x * x;
	ld x5 = x2 * x2 * x;
	ld x6 = x5 * x;
	return 42 * x6 + 48 * x5 + 21 * x2 + 10 * x - y;
}
int main()
{
	ld y;
	int t;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> y;
			ld l = 0, r = 100;
			if (y <= 0)
			{
				cout << f(0, y) << endl;
			}
			else
			{
				while (r - l > eps)
				{
					const ld mid = l + (r - l) / 2;
					if (df(mid, y) > 0)
					{
						r = mid - eps;
					}
					else
					{
						l = mid;
					}
				}
				cout << f(l, y) << endl;
			}
		}
	}
}