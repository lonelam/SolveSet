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

typedef long long ll;
ll k, t;
//dp[i + 1][j] means i char used, j remain to fill
int can[110];
ll C[170][11];
vector<ll> dp(170);
const ll maxx = 2e9 + 7;

ll DP(int n)
{
	//set to zero
	for (int i = 0; i <= n; i++) dp[i] = 0;
	dp[0] = 1;
	for (int i = 0; i < 16; i++)
	{
		for (int len = n; len >= 0; len--)
		{
			for (int j = 1; j <= can[i]; j++)
			{
				dp[len + j] += dp[len] * min(maxx, C[len + j][j]);
				dp[len + j] = min(dp[len + j], maxx);
			}
		}
	}
	return dp[n];
}
void output(int p)
{
	if (p < 10) cout << p;
	else
		cout << char(p - 10 + 'a');
}
void dfs(int n, int p, int k)
{
	output(p);
	if (!n)
	{
		cout << endl;
		return;
	}
	for (int i = 0; i < 16; i++)
	{
		if (can[i] == 0) continue;
		can[i] --;
		ll cnt = DP(n - 1);
		if (cnt >= k)
		{
			dfs(n - 1, i, k);
			return;
		}
		k -= cnt;
		can[i]++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	ll k;
	int t;
	for (int i = 0; i < 170; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= min(i, 10); j++)
		{
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			C[i][j] = min(C[i][j], maxx);
		}
	}
	start:
	if (cin >> k >> t)
	{
		for (int i = 0; i < 16; i++)
		{
			can[i] = t;
		}
		for (int len = 1; ; len++)
		{
			for (int i = 1; i < 16; i++)
			{
				can[i]--;
				ll cnt = DP(len - 1);
				if (cnt >= k)
				{
					dfs(len - 1, i, k);
					goto start;
				}
				k -= cnt;
				can[i]++;
			}
		}
	}
	return 0;
}