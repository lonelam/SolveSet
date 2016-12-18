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
const int maxn = 600;
int w[maxn], v[maxn];
const int maxm = 100000 + 5;
int dp[maxm];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> w[i] >> v[i];
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			for (int j = m; j >= w[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
		cout << dp[m] << endl;
	}

	return 0;
}