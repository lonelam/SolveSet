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
		int v = 0;
		for (int u = 1; u <= n; u++)
		{
			if (!used[u] &&  mincost[u] < mincost[v])
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
	while (scanf("%d%d", &m,&n) != EOF && m)
	{
		memset(G, inf, sizeof(G));
		for(int i = 0;i<m;i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			G[a][b] = c;
			G[b][a] = c;
		}
		int ans = prim();
		if (ans == -1)
		{
			printf("?\n");
		}
		else printf("%d\n", ans);
	}
}