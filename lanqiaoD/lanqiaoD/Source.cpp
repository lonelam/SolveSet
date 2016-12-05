#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 300000 + 50;

vector<int> G[maxn];
typedef long long ll;


void add_edge(int from, int to)
{
	G[from].push_back(to);
	G[to].push_back(from);
}

void initG(int n)
{
	for (int i = 0; i < n; i++)
	{
		G[i].clear();
	}
}

int most_far;
int md_node;
int to_farest[maxn];
int depth[maxn];
int cdepth[maxn];//childtree depth
void dfs2(int u, int p, int d)
{
	for (int i = 0; i < G[u].size(); i++)
	{
		if (G[u][i] != p) dfs2(G[u][i], u, d + 1);
	}
	most_far = max(most_far, d);
}
int dfs(int u, int p, int d)
{
	depth[u] = d;
	int cd = d;
	for (int i = 0; i < G[u].size(); i++)
	{
		if (G[u][i] != p)
		{
			cd = max(cd, dfs(G[u][i], u, d + 1));
		}
	}
	cdepth[u] = cd;
	if (d > most_far)
	{
		md_node = u;
		most_far = d;
	}
	return cd;
}
void dps(int u, int p, int pre, int d)
{
	int maxd = 0;
	int amaxd = 0;
	for (int i = 0; i < G[u].size(); i++)
	{
		if (G[u][i] != p)
		{
			if (cdepth[G[u][i]] >= maxd)
			{
				amaxd = maxd;
				maxd = cdepth[G[u][i]] ;
			}
			else if (amaxd < cdepth[G[u][i]])
			{
				amaxd = cdepth[G[u][i]] ;
			}
		}
	}
	for (int i = 0; i < G[u].size(); i++)
	{
		if (G[u][i] != p)
		{
			if (cdepth[G[u][i]] == maxd)
			{
				dps(G[u][i], u, max(pre + 1, amaxd + 1 - depth[u]), d + 1);
			}
			else
			{
				dps(G[u][i], u, max(pre + 1, maxd + 1 - depth[u]), d + 1);
			}
		}
	}
	to_farest[u] = max(pre, maxd - depth[u]);
}
int main()
{
	int n, q, m, s;
	while (scanf("%d%d", &n, &q) != EOF)
	{
		initG(n);
		int u, v;
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			add_edge(u - 1, v - 1);
		}
		most_far = 0;
		md_node = 0;
		dfs(0, -1, 0);
		dps(0, -1, 0, 0);
		dfs2(md_node, -1, 0);
		for (int i = 0; i < q; i++)
		{
			scanf("%d%d", &s, &m);
			ll ans = m - 1;
			ans *= most_far;
			ans += to_farest[s - 1];
			printf("%lld\n", ans);
		}
	}
}
/*

8 7
2 1
3 2
4 2
5 1
6 1
7 1
8 7
4 6
3 4
6 3
7 6
4 6
7 1
2 6


*/