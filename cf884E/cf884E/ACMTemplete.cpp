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
const int maxn = (1 << 12) + 1;
typedef long long ll;
typedef long double ld;
int n, m;
bitset<1 << 14> grid[maxn];
int idx(char x)
{
	if (x >= '0' && x <= '9')
	{
		return x - '0';
	}
	return 10 + (x - 'A');
}
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void dfs(int x, int y)
{
	
	int go = 0;
	for (int d = 0; d < 4; d++)
	{
		int tx = x + dx[d];
		int ty = y + dy[d];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty])
		{
			go |= 1 << d;
			grid[tx].set(ty, 0);
		}
	}
	for (int d = 0; d < 4; d++)
	{
		if (go >> d & 1)
		{
			int tx = x + dx[d];
			int ty = y + dy[d];
			dfs(tx, ty);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	while (cin >> n >> m)
	{
		string tmp;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			for (int j = 0; j < m; j += 4)
			{
				int mask = idx(tmp[j >> 2]);
				for (int k = 0; k < 4; k++)
				{
					grid[i].set(j + 3 - k, mask >> k & 1);
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == true)
				{
					grid[i].set(j, 0);
					dfs(i, j);

					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}