#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 350;
double a[maxn];
double b[maxn];
double c[maxn];

int main()
{
	int n;
	double x1, x2, y1, y2;
	while (cin >> x1 >> y1 >> x2 >> y2 >> n)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		if ((a[i] * x1 + b[i] * y1 + c[i]) * (a[i] * x2 + b[i] * y2 + c[i]) <= 0)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}