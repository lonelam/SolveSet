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
const int DEG = 20;
typedef long long ll;
typedef long double ld;
vector<int> G[maxn];
int fa[maxn][DEG], root, depth[maxn];
int n;
int indegree[maxn];
void init()
{
	for (int i = 1; i <= n; i++)
	{
		G[i].clear();
	}
	memset(indegree, 0, sizeof(indegree));
}
void dfs(int cur, int d)
{
	depth[cur] = d;
	for (int i = 1; i < DEG; i++)
	{
		fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
	}
	for (int i = 0; i < G[cur].size(); i++)
	{
		fa[G[cur][i]][0] = cur;
		dfs(G[cur][i], d + 1);
	}
}
int lca(int u, int v)
{
	if (depth[u] < depth[v]) swap(u, v);
	int hu = depth[u], hv = depth[v];
	for (int i = DEG - 1; i >= 0; --i)
	{
		if ( hu - (1 << i) >= hv)
		{
			hu -= 1 << i;
			u = fa[u][i];
		}
	}
	if (u == v) return u;
	for (int i = DEG - 1; i >= 0; --i)
	{
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}


int main()
{
	int u, v;
	int m;
		char pad[10];
	while (scanf("%d", &n) != EOF)
	{
		init();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &u);
			scanf("%[^0-9]s", pad);
			scanf("%d", &m);
			scanf("%[^0-9]s", pad);
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &v);
				G[u].push_back(v);
				indegree[v]++;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (indegree[i] == 0)
			{
				fa[i][0] = i;
				dfs(i, 0);
			}
		}
		scanf("%d", &m);
		map<int, int> cnt;
		for (int i = 0; i < m; i++)
		{
			scanf("%[^0-9]s",pad);
			scanf("%d%d", &u, &v);
			cnt[lca(u, v)]++;
		}
		for (map<int, int>::iterator i = cnt.begin(); i != cnt.end(); i++)
		{
			printf("%d:%d\n", i->first, i->second);
		}
		scanf("%[^0-9]s",pad);
	}
}