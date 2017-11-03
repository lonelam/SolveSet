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
const int maxn = 100 + 100;
typedef long long ll;
typedef long double ld;
int n;
int vis[maxn];
char s[maxn];
char t[maxn][maxn];
int grid[maxn][maxn];
int main()
{
	while (cin >> s)
	{
		cin >> n;
		int len = strlen(s);
		for (int i = 0; i < n; i++)
		{
			cin >> t[i];
			int m = strlen(t[i]);
			for (int j = -m + 1; j < len; j++)
			{
				int k;
				for (k = 0; k < m; k++)
				{
					if (k + j >= 0 && k + j < len && t[i][k] != s[j + k])
					{
							break;
					}
				}
				if (k == m)
				{
					grid[max(j, 0)][min(j + m, len)] = 1;
				}
			}
		}
		for (int k = 0; k <= len; k++)
		{
			for (int i = 0; i <= len; i++)
			{
				for (int j = 0; j <= len; j++)
				{
					grid[i][j] |= grid[i][k] & grid[k][j];
				}
			}
		}
		if (grid[0][len])
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}