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
const int maxn = 40000 + 100;
typedef long long ll;
typedef long double ld;
const int DEG = 16;
struct edge
{
	int to, val;
} es[maxn * 2];
int tot;
vector<int> G[maxn];
void addedge(int u, int v, int w)
{
	es[tot].to = v;
	es[tot].val = w;
	G[u].push_back(tot++);
	es[tot].to = u;
	es[tot].val = w;
	G[v].push_back(tot++);
}
int n, m;
int dis[maxn], fa[maxn][DEG];
int d[maxn];
void dfs(int cur, int p, int depth)
{
	d[cur] = depth;
	fa[cur][0] = p;
	for (int i = 1; i < DEG; i++)
	{
		fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
	}
	for (int i = 0; i < G[cur].size(); i++)
	{
		edge & e = es[G[cur][i]];
		if (e.to != p)
		{
			dis[e.to] = dis[cur] + e.val;
			dfs(e.to, cur, depth + 1);
		}
	}
}
int lca(int u, int v)
{
	if (d[u] < d[v]) swap(u, v);
	int hu = d[u], hv = d[v];
	for (int i = DEG - 1; i >= 0; i--)
	{
		if (hu - (1 << i) >= hv)
		{
			hu -= 1 << i;
			u = fa[u][i];
		}
	}
	if (u == v) return u;
	for (int i = DEG - 1; i >= 0; i--)
	{
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}
int DIS(int u, int v)
{
	return dis[u] + dis[v] - 2 * dis[lca(u, v)];
}
int main()
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d%d", &n, &m);
			int u, v, w;
			for (int i = 1; i <= n; i++)
			{
				G[i].clear();
			}
			tot = 0;
			for (int i = 1; i < n; i++)
			{
				scanf("%d%d%d", &u, &v, &w);
				addedge(u, v, w);
			}
			dis[1] = 0;
			dfs(1, -1, 0);
			for (int i = 0; i < m; i++)
			{
				scanf("%d%d", &u, &v);
				printf("%d\n", DIS(u, v));
			}
		}
	}
}