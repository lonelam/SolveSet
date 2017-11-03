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
#include <climits>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
#define v first
#define w second
int n;
ll dp[maxn][2];
vector<pair<int, ll> > G[maxn];
void init()
{
	for (int i = 1; i <= n; i++)
	{
		G[i].clear();
	}
	memset(dp, inf, sizeof(dp));
}
void dfs(int u, int par)
{
	ll zerosum = 0, onesum = 0, zeromin = LLONG_MAX, onemin = LLONG_MAX;
	for (pair<int,ll> g : G[u])
	{
		if (g.v != par)
		{
			dfs(g.v, u);
			zerosum += dp[g.v][0];
			onesum += dp[g.v][1];
			dp[u][0] = min(dp[u][0], dp[g.v][1] + g.w);
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		init();
		for (int i = 1; i < n; i++)
		{
			static int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back({ v, w });
			G[v].push_back({ u, w });
		}
		dfs(1, 1);
	}
}