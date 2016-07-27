#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int maxn = 2002;
const int maxk = 1001;
int dp[maxn][maxk];
int w[maxn];
const int inf = 0x3f3f3f3f;
int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", w + i);
		}
		sort(w, w + n);
		memset(dp, inf, sizeof(dp));
		for (int i = 0; i <= n; i++)
		{
			dp[i][0] = 0;
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < k; j++)
			{
				dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + (w[i] - w[i - 1])*(w[i] - w[i - 1]));

			}
		}
		printf("%d\n", dp[n][k]);
	}
}