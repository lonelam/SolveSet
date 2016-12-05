#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 100010;
int dp[MAXN][35];
int mm[MAXN];
//初始化RMQ, b数组下标从1开始，从0开始简单修改
void initRMQ(int n, int b[])
{
	mm[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		mm[i] = ((i&(i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
		dp[i][0] = b[i];
	}
	for (int j = 1; j <= mm[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}
//查询最大值
int rmq(int x, int y)
{
	int k = mm[y - x + 1];
	return min(dp[x][k], dp[y - (1 << k) + 1][k]);
}

int A[MAXN];
int main()
{
	int n, m;
	int t;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d", &n);
			for (int i = 1; i <= n; i++)
			{
				scanf("%d", A + i);
			}
			scanf("%d", &m);
			int x, y;
			initRMQ(n, A);

			for (int i = 0; i < m; i++)
			{
				scanf("%d%d", &x, &y);
			//	cout << md << endl;
				if (x == y)
				{
					printf("%d\n", A[x]);
					continue;
				}
				int md = rmq(x + 1, y);
				printf("%d\n", A[x] % md);
			}
		}
	}
}