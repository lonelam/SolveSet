#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[11][100003];
int main()
{
	int t, n,time,x;
	while (scanf("%d", &t) != EOF && t)
	{
		int mtime = 0;
		memset(dp, 0, sizeof(dp));
		while (t--)
		{
			scanf("%d%d", &x, &time);
			dp[x][time] ++;
			mtime = max(mtime, time);
		}
		for (int i = mtime; i > 0; i--)
		{
			dp[0][i - 1] += max(dp[0][i], dp[1][i]);
			for (int j = 1; j < 10; j++)
			{
				dp[j][i - 1] += max(dp[j][i], max( dp[j - 1][i], dp[j + 1][i] ));
			}
			dp[10][i - 1] += max(dp[10][i], dp[9][i]);
		}
		printf("%d\n", dp[5][0]);
	}
}
