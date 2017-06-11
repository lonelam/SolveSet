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
int x, y;
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
	if (grid[x * maxn + y] != '.')
	{
		printf("miss 1\n");
		return;
	}
	memcpy(tmp, grid, sizeof(tmp));
	tmp[x * maxn + y] = hold;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		memset(bvis, 0, sizeof(bvis));
		bvis[tx][ty] = true;
		if (tx >= 0 && tx < maxn && ty >= 0 && ty < maxn && tmp[tx * maxn + ty] == tar && dfs(tx, ty, tar) == 0)
		{
			take(tx, ty, tar);
		}
	}
	memset(bvis, 0, sizeof(bvis));
	bvis[x][y] = true;
	int atm = dfs(x, y, hold);
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
				scanf("%s%d%d", cmd, &x, &y);
				x--; y--;
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