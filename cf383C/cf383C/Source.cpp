#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
int dp[maxn][maxn];
void floyd()
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}
int crash[maxn];
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}
bool vis[maxn];
int main()
{
	
	while (cin >> n)
	{
		memset(dp, inf, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			cin >> crash[i];
			dp[i][crash[i] - 1] = 1;
		}
		floyd();
		int t = 1;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dp[i][j] != inf && dp[i][j] == dp[j][i])
				{
					t = lcm(t, dp[i][j]);
					vis[i] = vis[j] = true;
				}
			}
		}
		bool ok = true;
		for (int i = 0; i < n; i++)
		{
			if (!vis[i]) ok = false;
		}
		if (!ok) cout << -1 << endl;
		else cout << t << endl;
	}

}