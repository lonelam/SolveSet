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
int n;
int par[maxn];
int rk[maxn];
void init()
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		rk[i] = 1;
	}
}
int fd(int u)
{
	if (par[u] == u)
	{
		return u;
	}
	return par[u] = fd(par[u]);
}
void join(int u, int v)
{
	int pu = fd(u), pv = fd(v);
	if (pu == pv)
		return;
	if (rk[pv] == rk[pu])
	{
		par[pv] = pu;
		rk[pu]++;
	}
	if (rk[pu] > rk[pv])
	{
		par[pv] = pu;
		return;
	}
	if (rk[pv] > rk[pu])
	{
		par[pu] = pv;
	}
}
int bi[maxn];
int wi[maxn];
int dp[maxn][maxn];
bool vis[maxn];
int wsum[maxn];
int bsum[maxn];
int groupno[maxn];
vector<int> group[maxn];
int main()
{
	int m, w;
	while (cin >> n >> m >> w)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> wi[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> bi[i];
		}
		init();
		int uu, vv;
		for (int i = 0; i < m; i++)
		{
			cin >> uu >> vv;
			join(uu - 1, vv - 1);
		}
		int cnt = 0;
		memset(vis, 0, sizeof(vis));
		memset(bsum, 0, sizeof(bsum));
		memset(wsum, 0, sizeof(wsum));
		for (int i = 0; i < n; i++)
		{
			if (!vis[fd(i)])
			{
				group[cnt].clear();
				vis[fd(i)] = true;
				groupno[fd(i)] = cnt++;
			}
			wsum[groupno[fd(i)]]+= wi[i];
			bsum[groupno[fd(i)]] += bi[i];
			group[groupno[fd(i)]].push_back(i);
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < cnt; i++)
		{
			for (int j = w; j >= 0; j--)
			{
				dp[i + 1][j] = dp[i][j];
				for (int k = 0; k < group[i].size(); k++)
				{
					if (j >= wi[group[i][k]])
						dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - wi[group[i][k]]] + bi[group[i][k]]);
				}
				if (j >= wsum[i])
				{
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - wsum[i]] + bsum[i]);
				}
			}
		}
		cout << dp[cnt][w] << endl;
	}
	return 0;
}