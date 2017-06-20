#define _USE_MATH_DEFINES
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
typedef long long ll;
typedef long double ld;

const int maxn = 55;
char a[maxn];
char b[maxn];
int aL, aR, bL, bR, rem;
int n, m;
bool dfs(char pre = '$', int head = 0)
{
	if (rem == 0) return true;
	rem--;
	if (head == 0)
	{
		if (aL < aR)
		{
			aL++;
			if (dfs(a[aL - 1], 1))
			{
				return true;
			}
			aL--;
		}
		if (bL < bR)
		{
			bL++;
			if (dfs(b[bL - 1], 1))
			{
				return true;
			}
			bL--;
		}
	}
	else if (head == 1)
	{
		if (aL < aR && a[aR - 1] == pre)
		{
			aR--;
			if (dfs('$', 0))
			{
				return true;
			}
			aR++;
		}
		if (bL < bR && b[bR - 1] == pre)
		{
			bR--;
			if (dfs('$', 0))
			{
				return true;
			}
			bR++;
		}
	}
	rem++;
	return false;
}
int main()
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%s", a);
			scanf("%s", b);
			n = strlen(a);
			m = strlen(b);
			int ans = 1;
			for (int len = n + m; len > 1 && ans == 1; len--)
			{
				for (int i = 0; i < n && ans == 1; i++)
				{
					for (int j = 0; j < m && ans == 1; j++)
					{
						for (int k = 0; k <= n && ans == 1; k++)
						{
							aL = i;
							bL = j;
							aR = i + k;
							bR = j + len - k;
							if (aR > n || bR > m) continue;
							rem = len;
							if (dfs())
							{
								ans = len;
							}
						}
					}
				}
			}
			printf("%d\n", ans);
		}
	}
}
