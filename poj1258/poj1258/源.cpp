#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstring>
#include<cstdio>
using namespace std;
typedef pair<int, int> P;
const int maxn = 102;
const int inf = 0x3f3f3f3f;

int G[maxn][maxn];
int mincost[maxn];
bool used[maxn];

int n;
int prim()
{
	memset(mincost, inf, sizeof(mincost));
	memset(used, 0, sizeof(used));
	mincost[1] = 0;
	int res = 0;
	while (true)
	{
		int v = 0;
		for (int u = 1; u <= n; u++)
		{
			if (!used[u] && mincost[u] < mincost[v])
			{
				v = u;
			}
		}
		if (v == 0)
		{
			break;
		}
		res += mincost[v];
		used[v] = true;
		for (int u = 1; u <= n; u++)
		{
			mincost[u] = min(mincost[u], G[v][u]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			return -1;
		}
	}
	return res;
}
int main()
{
	int  a, b, c, d, m;
	while (scanf("%d", &n) != EOF)
	{
		memset(G, inf, sizeof(G));
		for (int i = 1; i<=n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &a);
				G[i][j] = a;
			}
		}
		int ans = prim();
        printf("%d\n", ans);
	}
}