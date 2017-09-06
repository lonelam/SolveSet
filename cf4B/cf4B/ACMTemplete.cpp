#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
int ans[100];
int main()
{
	int d, sum;
	cin >> d >> sum;
	int mint = 0, maxt = 0;
	int a[100], b[100];
	for (int i = 0; i < d; i++)
	{
		cin >> a[i] >> b[i];
		mint += a[i];
		maxt += b[i];
	}
	if (sum >= mint && sum <= maxt)
	{
		cout << "YES\n";
		for (int i = 0; i < d; i++)
		{
			ans[i] = a[i];
			sum -= a[i];
		}
		for (int i = 0; i < d; i++)
		{
			if (sum >= b[i] - a[i])
			{
				ans[i] = b[i];
				sum -= b[i] - a[i];
			}
			else
			{
				ans[i] = a[i] + sum;
				sum = 0;
			}
		}
		for (int i = 0; i < d; i++)
		{
			cout << ans[i] << " ";
		}
	}
	else
	{
		cout << "NO\n";
	}
}