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
const int maxn = 100000 + 100;
typedef long long ll;
const ll moder = 1e9 + 7;
typedef long double ld;
int n;
ll m, k, x;
//0:1~k-1, 1:k, 2:k+1~m
ll dp[maxn][3][11];
vector<int> G[maxn];
void dfs(int u, int par)
{
	/*for (int i = 0; i <= x; i++)
	{
		dp[u][0][i] = k - 1;
		if (i)dp[u][1][i] = 1;
		dp[u][2][i] = m - k;
	}*/
	dp[u][0][0] = k - 1;
	dp[u][1][1] = 1;
	dp[u][2][0] = m - k;
	//ll tmp = m - k;
	bool vi = false;
	for (int v : G[u])
	{
		if (v != par)
		{
			dfs(v, u);
			if (!vi)
			{
			/*	for (int j = 0; j <= x; j++)
				{
					dp[u][0][j] = k - 1;
					dp[u][1][j] = 1;
					dp[u][2][j] = m - k;
				}*/
				vi = true;
			}
			static ll tmp[3][11];
			memcpy(tmp, dp[u], sizeof(dp[u]));
			for (int j = x; j >= 0; j--)
			{
				//if (dp[u][0][j] == -1) 
				for (int i = 0; i <= j; i++)
				{
					dp[u][0][j] = ((dp[v][0][i] + dp[v][1][i] + dp[v][2][i]) % moder * tmp[0][j - i] % moder + (i?dp[u][0][j]:0)) % moder;
					//if (dp[u][1][j] == -1) 

					dp[u][1][j] = (dp[v][0][i] * tmp[1][j-i] % moder + (i?dp[u][1][j]:0)) % moder;
					//else dp[u][1][j] = 0;
					//if (dp[u][2][j] == -1) 
					dp[u][2][j] = ((dp[v][0][i] + dp[v][2][i]) % moder * tmp[2][j-i] % moder + (i?dp[u][2][j]:0))% moder ;
				}
			}
			//cout << v << endl;
		}
	}
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (dp[u][j][i] == -1) dp[u][j][i] = 0;
		}
	}
}
int main()
{
	while (~scanf("%d%lld", &n, &m))
	{
		//memset(dp, -1, sizeof(dp));
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		scanf("%lld%lld", &k, &x);
		dfs(1, 1);
		ll ans = 0;
		for (int i = 0; i <= x; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				ans = (ans + dp[1][j][i]) % moder;
			}
		}
		printf("%lld\n", ans);
	}
}