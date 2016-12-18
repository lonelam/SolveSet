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
const int maxn = 1000 + 50;
const int maxS = 1 << 6;
typedef long long ll;
const ll moder = 1e9 + 7;
int dp[2][maxS];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int mS = 1 << m;
		int flip = 1;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				memset(dp[flip], 0, sizeof(dp[flip]));
				flip ^= 1;
				for (int st = 0; st <= mS; st++)
				{
					if ((st >> j) & 1)
					{
						dp[flip ^ 1][st - (1 << j)] = ( dp[flip ^ 1][st - (1 << j)] + dp[flip][st] ) % moder;
					}
					else
					{
						dp[flip ^ 1][st + (1 << j)] = (dp[flip ^ 1][st + (1 << j)] + dp[flip][st] ) % moder;
						if (j < m - 1 && !((st >> (j + 1)) & 1))
						{
							dp[flip ^ 1][st + (1 << (j + 1))] = (dp[flip ^ 1][st + (1 << (j + 1))] + dp[flip][st]) % moder;
						}
					}
				}
			}
		}
		cout << dp[flip ^ 1][0] << endl;
	}
	return 0;
}