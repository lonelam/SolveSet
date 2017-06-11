#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3 * 15 + 1;
typedef long long ll;
typedef long double ld;
bool vis[17][17][17][3];
ld dp[17][17][17][3];
int n;
ld dfs(int num0, int num1, int num2, int cur)
{
	if (vis[num0][num1][num2][cur])
	{
		return dp[num0][num1][num2][cur];
	}
	vis[num0][num1][num2][cur] = true;
	if (num0 > n || num1 > n + 1 || num2 > n)
	{
		return dp[num0][num1][num2][cur] = 0;
	}
	if (cur == 1)
	{
		//0, 1|1, 0|2,2
		dp[num0][num1][num2][cur] = dfs(num0 + 1,num1,num2,1) * (ld)(num0 + 1) / (ld)(num0 + num1 + num2 + 1) + dfs(num0,num1 + 1,num2,0) * (ld)(num1 + 1) / (ld)(num0 + num1 + num2 + 1) + dfs(num0, num1, num2 + 1, 2) * (ld)(num2 + 1) / (ld)(num0 + num1 + num2 + 1);
		return dp[num0][num1][num2][cur];
	}
	else if (cur == 2)
	{

		//0, 2|2, 0|1,1
		dp[num0][num1][num2][cur] = dfs(num0 + 1,num1,num2,2) * (ld)(num0 + 1) / (ld)(num0 + num1 + num2 + 1) + dfs(num0,num1 + 1,num2,1) * (ld)(num1 + 1) / (ld)(num0 + num1 + num2 + 1) + dfs(num0, num1, num2 + 1, 0) * (ld)(num2 + 1) / (ld)(num0 + num1 + num2 + 1);
		return dp[num0][num1][num2][cur];
	}
	return dp[num0][num1][num2][cur] = 0;
}
ld ans[16];
int main()
{
	for (n = 1; n <= 15; n++)
	{
		memset(vis, 0, sizeof(vis));
		dp[n][n + 1][n][0] = 1;
		vis[n][n + 1][n][0] = true;
		ans[n] = dfs(0, 0, 0, 1);
		//cout << ans[n] << endl;
	}
	int k;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d", &n);
		printf("%.9llf\n", ans[n]);
	}
}