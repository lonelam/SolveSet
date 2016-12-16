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
const int maxS = 1 << 10;
const int maxn = 1000 + 100;
int howmanyone[maxS];
void init()
{
	for (int i = 0; i < maxS; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (i & (1 << k))
			howmanyone[i]++;
		}
	}
}
int wi[maxn];
int dp[maxn][maxS];
int main()
{
	init();
	int N, M, Q;
	while (cin >> N >> M >> Q)
	{
		for (int i = 0; i < N; i++)
		{
			cin >> wi[i];
		}
		const int mS = 1 << M;
		const int mD = mS >> 1;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; i++)
		{
			for (int st = (1 << M) - 1; st >= 0; st--)
			{
				if (howmanyone[st] > Q)
				{
					dp[i + 1][st] = 0;
					continue;
				}
				if (st & 1)
				{
					dp[i + 1][st] = max(dp[i][(st >> 1) + mD],  dp[i][st >> 1] ) + wi[i];
				}
				else
				{
					dp[i + 1][st] = max(dp[i][(st >> 1) + mD], dp[i][st >> 1]);
				}
			}
		}
		int ans = 0;
		for (int st = (1 << M) - 1; st >= 0; st--)
		{
			ans = max(ans, dp[N][st]);
		}
		cout << ans << endl;
		
	}

	return 0;
}