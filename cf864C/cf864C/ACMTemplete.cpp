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
ll a, b, f, k;
int solve()
{
	
	ll rem = b;
	ll ans = 0;
	//ll pos = 0;
	//ll tar = 2 * a * k;
	ll step[] = { f, a - f, a - f, f };
	ll cost[] = {2 * f, a - f, 2 * (a - f), f};
	for (ll i = 0; i < k / 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			rem -= step[j];
			if (rem < 0)
			{
				ans++;
				rem = b - cost[j];
				if (rem < 0)
				{
					return -1;
				}
			}
		}
	}
	if (k & 1)
	{
		for (int j = 0; j < 2; j++)
		{
			rem -= step[j];
			if (rem < 0)
			{
				ans++;
				rem = b - cost[j];
				if (rem < 0)
				{
					return -1;
				}
			}
		}
	}
	return ans;
}
int main()
{
	while (cin >> a >> b >> f >> k)
	{
		cout << solve() << endl;
	}
}