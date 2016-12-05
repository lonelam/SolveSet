#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100005;
typedef long long ll;
ll a[maxn];
ll pres[maxn];
const int MAXN = maxn;
int dp[MAXN][20];
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
			dp[i][j] = dp[i][j - 1] + dp[i + (1 << (j - 1))][j - 1];
}
//查询最大值
int rmq(int x, int y)
{
	int k = mm[y - x + 1];
	return dp[x][k]+ dp[y - (1 << k) + 1][k];
}
void del(int )
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", a);
		pres[0] = a[0];
		for (int i = 1; i < n; i++)
		{
			scanf("%d", a + i);
			pres[i] = pres[i - 1] + a[i];
		}
		int ans = pres[n - 1];
		for(int i = 0; i < )
	}

}