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
const int maxn = 1000 + 100;
typedef long long ll;
typedef long double ld;
int dp[maxn];
int a[maxn];
int n;
char grid[4][maxn];
int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= 4; i++)
		{
			scanf("%d", a + i);
		}
		for (int i = 0; i < 4; i++)
		{
			scanf("%s", grid[i] + 1);
		}
		memset(dp, inf, sizeof(dp));
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i >= 4)
			{
				dp[i] = min(dp[i], dp[i - 4] + a[4]);
				bool flg = true;
				for (int j = 0; j < 4; j++)
				{
					for (int k = i - 3; k <= i; k++)
					{
						if (grid[j][k] == '*')
						{
							flg = false;
							break;
						}
					}
				}
			}
			if (i >= 3)
			{
				for (int sr = 0; sr < (1 << 4); sr++)
				{
					for (int sc = 0; sc < (1 << 2); sc++)
					{
						int cnt = 0, flg = true;
						for (int j = 0; j < 4; j++)
						{
							for (int k = 0; k < 2; k++)
							{
								if (sr >> j & 1 && sc >> k & 1)
								{
									cnt++;
									continue;
								}
								for (int ii = 0; ii < 4; ii++)
								{
										for (int jj = )
								}
							}
						}
					}
				}
			}
		}
	}
}