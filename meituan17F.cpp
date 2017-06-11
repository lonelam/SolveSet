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
const int maxn = 19;
typedef long long ll;
typedef long double ld;
char grid[maxn * maxn + 1];
char cmd[20];
char tmp[maxn * maxn + 1];
int X, y;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool bvis[maxn][maxn];
void take(int cx, int cy, char tar)
{
	tmp[cx * maxn + cy] = '.';
	for (int i = 0; i < 4; i++)
	{
		int tx = cx + dx[i];
		int ty = cy + dy[i];
		if (tx >= 0 && tx < maxn && ty >= 0 && ty < maxn && tmp[tx * maxn + ty] == tar)
		{
			take(tx, ty, tar);
		}
	}
}
int dfs(int cx, int cy, char tar)
{
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int tx = cx + dx[i];
		int ty = cy + dy[i];
		if (tx >= 0 && tx < maxn && ty >= 0 && ty < maxn && !bvis[tx][ty])
		{
			bvis[tx][ty] = true;
			if (tmp[tx * maxn + ty] == tar)
				ret += dfs(tx, ty, tar);
			else if (tmp[tx * maxn + ty] == '.')
				ret++;
		}
	}
	return ret;
}
set<string> vis;
void solve(char hold)
{
	char tar;
	if (hold == 'W')
	{
		tar = 'B';
	}
	else tar = 'W';
	if (grid[X * maxn + y] != '.')
	{
		printf("miss 1\n");
		return;
	}
	memcpy(tmp, grid, sizeof(tmp));
	tmp[X * maxn + y] = hold;
	for (int i = 0; i < 4; i++)
	{
		int tx = X + dx[i];
		int ty = y + dy[i];
		memset(bvis, 0, sizeof(bvis));
		if (tx >= 0 && tx < maxn && ty >= 0 && ty < maxn && tmp[tx * maxn + ty] == tar )
		{
		  bvis[tx][ty] = true;
      if (dfs(tx, ty, tar)) continue;
			take(tx, ty, tar);
		}
	}
	memset(bvis, 0, sizeof(bvis));
	bvis[X][y] = true;
	int atm = dfs(X, y, hold);
	if (atm == 0)
	{
		printf("miss 2\n");
		return;
	}
	if (vis.find(tmp) != vis.end())
	{
		printf("miss 3\n");
		return;
	}
	vis.insert(tmp);
	memcpy(grid, tmp, sizeof(tmp));
	/*
			for (int i = 0; i < maxn; i++)
			{
				for (int j = 0; j < maxn; j++)
				{
					printf("%c", grid[i * maxn + j]);
				}
				printf("\n");
			}
			*/
}
int main()
{
	int T, n;
	scanf("%d", &T);
	{
		while (T--)
		{
			vis.clear();
			scanf("%d", &n);
			for (int i = 0; i < maxn * maxn; i++)
			{
				grid[i] = '.';
			}
			grid[maxn * maxn] = '\0';
			for (int i = 0; i < n; i++)
			{
				scanf("%s%d%d", cmd, &X, &y);
				X--; y--;
				solve(cmd[0]);
			}
			for (int i = 0; i < maxn; i++)
			{
				for (int j = 0; j < maxn; j++)
				{
					printf("%c", grid[i * maxn + j]);
				}
				printf("\n");
			}

		}
	}
}

/*
1
12
B 1 3
W 1 2
B 2 4
W 2 1
B 1 1
W 2 3
B 3 3
W 3 2
B 1 1
W 2 3
B 2 2
W 2 3
*/
