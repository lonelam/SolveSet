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
const int maxn = 250 + 5;
typedef long long ll;
typedef long double ld;
const int Mod = 1e9 + 7;
inline void add(int & x, int y)
{
	x += y;
	x = (x >= Mod ? x - Mod : x);
}
int n, m;
char g[maxn][maxn];
char tmp[maxn][maxn];
int dp[maxn][1 << 15][2][2];
int calc(int i, int j, int mask, bool e, bool l)
{
	if (i == n) return 1;
	if (j == m) return calc(i + 1, 0, mask, e, 0);
	int & ret = dp[i * m + j][mask][e][l];
	if (ret != -1)
	{
		return ret;
	}
	ret = 0;
	if (g[i][j] == 'x')
	{
		return ret = calc(i, j + 1, mask & (~(1 << j)), e, 0);
	}
	else if (g[i][j] == '.')
	{
		if (l || (mask >> j & 1))
		{
			ret = calc(i, j + 1, mask, e, l);
		}
		else if (!e)
		{
			ret = calc(i, j + 1, mask, true, 0);
		}
		add(ret, calc(i, j + 1, mask | (1 << j), e, true));
		return ret;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", g[i]);
	}
	if (n < m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				tmp[j][i] = g[i][j];
			}
		}
		swap(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				g[i][j] = tmp[i][j];
			}
			//reverse(g[i], g[i] + m);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", calc(0, 0, 0, 0, false));
	return 0;
}