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
const int maxn = 6000 + 100;
int dp1[maxn];
int dp2[maxn];
vector<int> G[maxn];
int rating[maxn];
int indegree[maxn];
void dfs(int u, int p)
{
	for (int i = 0; i < G[u].size(); i++)
	{
		dfs(G[u][i], u);
		dp1[u] += max(0, dp2[G[u][i]]);
		dp2[u] += max(0, dp1[G[u][i]]);
	}
	dp1[u] += max(0, rating[u]);
}
int main()
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> rating[i];
			G[i].clear();
		}
		int u, v;
		memset(indegree, 0, sizeof(indegree));
		for (int i = 1; i < n; i++)
		{
			cin >> u >> v;
			G[v].push_back(u);
			indegree[u]++;
		}
		int rt = 1;
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		for (int i = 1; i <= n; i++)
		{
			if (indegree[i] == 0)
			{
				rt = i;
				break;
			}
		}
		
		dfs(rt, -1);
		cout << max(dp1[rt], dp2[rt]) <<endl;
	}
	return 0;
}