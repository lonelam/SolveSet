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
const int maxn = 1000 + 10;
int dp[maxn][maxn];
int lmax[maxn][maxn];
int rmax[maxn][maxn];
int val[maxn];
int main()
{
	int T;
	int n;
	while (cin >> T)
	{
		while (T--)
		{
			cin >> n;
			val[0] = val[n + 1] = 1;
			for (int i = 1; i <= n; i++)
			{
				cin >> val[i];
			}
			for (int i = 1; i <= n; i++)
			{
				dp[i][i] = val[i - 1] * val[i] * val[i + 1];
			}
			dp[0][0] = dp[n + 1][n + 1] = 1;
			for (int len = 2; len <= n; len++)
			{
				int lef = n - len + 1;
				for (int i = 1; i <= lef; i++)
				{
					int L = i - 1;
					int R = i + len;
					dp[i][i + len - 1] = max(val[L] * val[i] * val[R] + dp[i + 1][i + len - 1], val[R - 1] * val[L] * val[R] + dp[i][R - 2]);
					int nowl = i + 1;
					int nowr = R - 1;
					for (int j = nowl; j < nowr; j++)
					{
						dp[i][i + len - 1] = max(dp[i][i + len - 1], dp[i][j - 1] + dp[j + 1][nowr] + val[j] * val[L] * val[R]);
					}
				}
			}
			cout << dp[1][n] << endl;
		}
	}
	return 0;
}