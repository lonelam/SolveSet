#include<iostream>
#include<cmath>
using namespace std;
int px[5], py[5];
double dist(double x1, double y1, double x2, double y2)
{
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}
int main()
{
	int t;
	while (cin >> t)
	{
		while (t--)
		{
			for (int i = 0; i < 3; i++)
			{
				cin >> px[i] >> py[i];
			}
			bool ok = true;
			for (int i = 0; i < 3; i++)
			{
				int a = i, b = (i + 1) % 3, c = (i + 2) % 3;
				if (dist(px[a], py[a], px[b], py[b]) + dist(px[c], py[c], px[b], py[b]) <= dist(px[a], py[a], px[c], py[c]))
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				cout << "Yes\n";
			}
			else
			{
				cout << "No\n";
			}
		}
	}
}