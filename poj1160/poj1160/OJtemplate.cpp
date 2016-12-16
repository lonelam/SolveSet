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
const int maxv = 300 + 10;
const int maxp = 30 + 5;
int V, P;
int dp[maxp][maxv];
int cost[maxv][maxv];
int x[maxv];
const int inf = 0x3f3f3f3f;
int main()
{
	while (cin >> V >> P)
	{
		memset(dp, inf, sizeof(dp));
		for (int i = 0; i < V; i++)
		{
			cin >> x[i];
		}
		memset(cost, 0, sizeof(cost));
		for (int i = 0; i < V; i++)
		{
			for (int j = i + 1; j < V; j++)
			{
				cost[i][j] = cost[i][j - 1] + x[j] - x[(i + j) / 2];
			}
		}
		dp[0][0] = 0;
		for (int k = 1; k <= P; k++)
		{
			for (int i = 0; i < V; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					dp[k][i + 1] = min(dp[k - 1][j] + cost[j][i], dp[k][i + 1]);
				}
			}
		}
		cout << dp[P][V] << endl;
	}
	return 0;
}