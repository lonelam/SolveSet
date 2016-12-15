#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 40;
const int maxS = 1 << 8;
int a[maxn];
int jump[maxn][maxn];
int dp[maxn][maxS];
int n;
int pre[10];
int ans;
void dp_init()
{
	memset(pre, -1, sizeof(pre));
	memset(jump, -1, sizeof(jump));
	for (int i = 0; i < n; i++)
	{
		int cur = a[i] - 1;
		jump[i][0] = i + 1;
		jump[i][1] = i;
		if (pre[cur] != -1)
		{
			for (int j = 2; j < n; j++)
			{
				jump[i][j] = jump[pre[cur]][j - 1];
			}
		}
		pre[cur] = i;
	}
	for (int i = 0; i < 8; i++)
	{
		if (pre[i] != -1)
			ans++;
	}
}
bool iter(int x)
{
	memset(dp, -10000, sizeof(dp));
	dp[0][0] = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int S = 0; S < maxS; S++)
		{
			int cur = a[i] - 1;
			dp[i + 1][S] = dp[i][S];
			if (S & (1 << cur))
			{
				if (jump[i][x] != -1)
				{
					dp[i + 1][S] = max(dp[i + 1][S], dp[jump[i][x]][S - (1 << cur)] + x);
				}
				if (jump[i][x + 1] != -1)
				{
					dp[i + 1][S] = max(dp[i + 1][S], dp[jump[i][x + 1]][S - (1 << cur)] + x + 1);
				}
			}
		}
	}
	ans = max(ans, dp[n][maxS - 1]);
	if (dp[n][maxS - 1] > 0)
		return true;
	return false;
}

int main()
{
	while (cin >> n)
	{
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		dp_init();
		int l = 0, r = n / 8 + 2;
		while (l + 1 < r)
		{
			const int mid = l + (r - l) / 2;
			if (iter(mid))
			{
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		iter(l);
		cout << ans << endl;
	}
}
/*

24
1 8 1 2 8 2 3 8 3 4 8 4 5 8 5 6 8 6 7 8 7 8 8 8
8
8 7 6 5 4 3 2 1
3
1 1 1


*/