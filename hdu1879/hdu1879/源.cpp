#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstring>
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
		int v = -1;
		for (int u = 1; u <= n; u++)
		{
			if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
			{
				v = u;
			}
		}
		if (v == -1)
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
	return res;
}
int main()
{
	int  a, b, c,d, m;
	while (scanf("%d",&n)!=EOF && n)
	{
		memset(G, inf, sizeof(G));
		m = n * (n - 1) / 2;
		while (m--)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if (d == 1)
			{
				G[a][b] = 0;
				G[b][a] = 0;
			}
			else
			{
				G[a][b] = c;
				G[b][a] = c;
			}
		}
		printf("%d\n", prim());
	}
}