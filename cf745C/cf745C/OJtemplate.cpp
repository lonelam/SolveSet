#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn = 2000 + 50;
const int maxm = 100000 + 500;
int degree[maxn];
vector<int> G[maxn];
int n, m, k;
int lef;
int c[maxn];
int dsum[maxn];
int nodesum[maxn];
bool ccno[maxn];
int cccnt[maxn];

vector<int> cc[maxn];
void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
	degree[u]++;
	degree[v]++;
}
void dfs(int u,int p, int color)
{
	lef--;
	ccno[u] = color;
	cc[color].push_back(u);
	cccnt[color]++;
	for (int i = 0; i < G[u].size(); i++)
	{
		if (ccno[G[u][i]] == 0) dfs(G[u][i], u, color);
	}
}
int main()
{
	while (scanf("%d%d%d", &n, &m, &k)!=EOF)
	{
		memset(nodesum, 0, sizeof(nodesum));
		memset(ccno, 0, sizeof(ccno));
		lef = n;
		memset(degree, 0, sizeof(degree));
		memset(dsum, 0, sizeof(dsum));
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
			cc[i].clear();
		}
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", c + i);
		}
		int u, v;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			add_edge(u, v);
		}
		int lgnum = 0;
		int lgcc = 1;
		for (int i = 1; i <= k; i++)
		{
			dfs(c[i], -1, i);
			
		}
		for (int i = 1; i <= k; i++)
		{
			if (cc[i].size() > lgnum)
			{
				lgnum = cc[i].size();
				lgcc = i;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (ccno[i] == 0)
			{
				ccno[i] = lgcc;
				cc[lgcc].push_back(i);
			}
		}
		int ans = 0;
		for (int i = 1; i <= k; i++)
		{
			ans += cc[i].size() * (cc[i].size() - 1) / 2;
		}
		ans -= m;
		printf("%d\n", ans);
	}
	return 0;
}