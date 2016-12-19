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
int f[35][35];
void init()
{
	f[0][0] = 1;
	for (int i = 1; i <= 31; i++)
	{
		f[i][0] = f[i - 1][0];
		for (int j = 1; j <= i; ++j)
		{
			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
		}
	}
}
int digit[33];
int calc(int x, int k)
{
	int tot = 0, ans = 0;
	for (int i = 31; i > 0; --i)
	{
		if (x & (1 << i))
		{
			++tot;
			if (tot > k)
			{
				break;
			}
			x ^= 1 << i;
		}
		if ((1 << (i - 1)) <= x)
		{
			ans += f[i - 1][k - tot];
		}
	}
	if (tot + x == k) ++ans;
	return ans;
}
int dfs(int x, int k, int B)
{
	int len = -1;
	while (x)
	{
		digit[++len] = x % B;
		x /= B;
	}
	int cnt = 0, ans = 0;
	for (int i = len; i >= 0; i--)
	{
		if (digit[i] == 1)
		{
			ans += f[i][k - cnt];
			cnt++;
			if (cnt == k)
				break;
		}
		else if (digit[i] > 1)
		{
			ans += f[i + 1][k - cnt];
			break;
		}
	}
	if (cnt == k)
		ans++;
	return ans;
}
int main()
{ 
	init();
	int x, y, k, B;
	while (~scanf("%d%d%d%d", &x, &y, &k, &B))
	{
		printf("%d\n", dfs(y, k, B) - dfs(x - 1, k, B));
	}
	return 0;
}