#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 100;
const int inf = 0x3f3f3f3f3f3f3f3f;
ll a[maxn];
ll dp[maxn];
ll imax[maxn];
ll sum[maxn];
int m, n;
int main()
{
	while (scanf("%d%d", &m, &n) != EOF)
	{
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", a + i);
			sum[i] = sum[i - 1] + a[i];
		}
		memset(dp, 0, sizeof(dp));
		memset(imax, 0, sizeof(imax));
		for (int i = 1; i <= m; i++)
		{
			dp[i] = sum[i];
			imax[i] = -inf;
			for (int j = i + 1; j <= n; j++)
			{
				dp[j] = dp[j - 1] + a[j];
				dp[j] = max(dp[j], imax[j] + a[j]);
				imax[j] = max(imax[j - 1],  dp[j - 1]);
			}
		}
		ll ans = -inf;
		//important
		for (int i = m; i <= n; i++)
		{
			ans = max(ans, dp[i]);
		}
		printf("%lld\n", ans);
	}
}