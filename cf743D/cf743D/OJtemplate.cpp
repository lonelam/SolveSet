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
const int maxn = 200000 + 100;
vector<int> G[maxn];
typedef long long ll;
ll a[maxn];
ll dp[maxn];
const ll inf = 0x3f3f3f3f3f3f3f3f;
void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
ll dfs1(int u, int p)
{
	ll mm = -inf;
	ll sum = 0;

	for (int i = 0; i < G[u].size(); i++)
	{
		if (G[u][i] != p)
		{
			ll tmp = dfs1(G[u][i], u);
			mm = max(mm, dp[G[u][i]]);
			sum += tmp;
		}
	}
	//cout << u << "  " << max(a[u] + sum, mm) << endl;
	dp[u] = max(a[u] + sum, mm );
	return sum + a[u];
	
}

ll dfs2(int u, int p)
{
	ll prem = -inf, mm = -inf;

	for (int i = 0; i < G[u].size(); i++)
	{
		if (G[u][i] != p)
		{
			if (mm < dp[G[u][i]])
			{
				prem = mm;
				mm = dp[G[u][i]];
			}
			else if (prem < dp[G[u][i]])
			{
				prem = dp[G[u][i]];
			}
		}
	}
	ll ans = prem + mm;
	for (int i = 0; i < G[u].size(); i++)
	{
		if (G[u][i] != p)
		{
			ans = max(ans, dfs2(G[u][i], u));
		}
	}
	return ans;
}
int main()
{
	ll n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		int u, v;
		for (int i = 1; i < n; i++)
		{
			cin >> u >> v;
			add_edge(u - 1, v - 1);
		}
		dfs1(0, -1);
		ll ans = dfs2(0, -1);
		if (ans < -inf / 2)
		{
			cout << "Impossible\n";
		}
		else
		{
			cout << ans << endl;
		}
	}
	return 0;
}
/*

4 
-1

*/