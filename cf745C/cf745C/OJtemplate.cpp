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
const int maxn = 1000 + 50;
const int maxm = 100000 + 500;
int degree[maxn];
vector<int> G[maxn];
int n, m, k;
int c[maxn];
int dsum[maxn];
int nodesum[maxn];
bool ccno[maxn];

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
	ccno[u] = color;
	cc[color].push_back(u);
	for (int i = 0; i < G[u].size(); i++)
	{
		if (G[u][i] != p && ccno[u] == 0) dfs(G[u][i], u, color);
	}
}
int main()
{
	while (scanf("%d%d%d", &n, &m, &k)!=EOF)
	{
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
		int lgcc = 0;
		for (int i = 1; i <= k; i++)
		{
			dfs(c[i], -1, i);
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
			int sum = 0;
			for (int k : cc[i])
			{
				sum += degree[k];
			}
			sum /= 2;
			ans -= sum;
			ans += cc[i].size() * (cc[i].size() - 1) / 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}