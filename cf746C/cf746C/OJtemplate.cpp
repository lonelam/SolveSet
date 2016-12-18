#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	int s, x1, x2;
	int t1, t2;
	int p, d;
	while (cin >> s >> x1 >> x2)
	{
		cin >> t1 >> t2;
		cin >> p >> d;
		int ans = abs(x2 - x1) * t2;
		if ((x2 - x1) * d > 0 && (x1 - p) * d >= 0)
		{
			ans = min(ans, abs(x2 - p) * t1);
		}
		else if ((x2 - x1) * d < 0)
		{
			if (d == -1)
			{
				ans = min(ans, (p + x2) * t1);
			}
			else
			{
				ans = min(ans, (s * 2 - x2 - p) * t1);
			}
		}
		else if ((x2 - x1) * d > 0 && (x1 - p) * d < 0)
		{
			if (d == -1)
			{
				ans = min(ans, t1 * (s + p + s - x2));
			}
			else
			{
				ans = min(ans, t1 * (s - p + s + x2));
			}
		}
		cout << ans << endl;
	}

	return 0;
}