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
const int maxn = 1000 + 100;
typedef long long ll;
typedef long double ld;
ll s, m;
ll mem[maxn][maxn];
ll dfs(ll x, ll d)
{
	if (d == 0)
	{
		return 0;
	}
	if (mem[x][d] != -1)
	{
		return mem[x][d];
	}
	ll ret = 0;
	for (int a = 1; a < x; a++)
	{
		for (int k = 0; k < d; k++)
		{
			ret = max(ret, dfs(x - a, d - 1 - k) + dfs(a, k) + a * (x - a));
		}
	}
	return mem[x][d] = ret;
}
int main()
{
	memset(mem, -1, sizeof(mem));
	while (cin >> s >> m)
	{
		ll tmp = 0, ans = 0;
		int L = -1, R = s-1;
		while (L + 1 < R)
		{
			cout << L << " " << R << endl;
			const int mid = (L + R + 1) / 2;
			if (dfs(s, mid) >= m)
			{
				R = mid;
			}
			else
			{
				L = mid;
			}
		}
		if (dfs(s, R) >= m)
		{
			cout << R << endl;
		}
		else
		{
			cout << -1 << endl;
		}
		
	}
}