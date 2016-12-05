#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int num[1002];
int dp[1002];
int main()
{
	int n, tmp;
	while (scanf("%d", &n) != EOF && n)
	{
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", num + i);
			for (int j = i; j >= 0; j--)
			{
				if (num[j] < num[i])
				{
					dp[i] = max(dp[i], dp[j]);
				}
			}
			dp[i] += num[i];
			ans = max(ans, dp[i]);
		}

		printf("%d\n", ans);
	}
}