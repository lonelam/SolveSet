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
#include <cctype>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn = 100 + 5;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int m, n;
char grid[maxn][maxn];
bool vis[maxn][maxn];
int dis[maxn][maxn];
int pre[maxn][maxn];
bool path[maxn][maxn];
int cost;
const int inf = 0x3f3f3f3f;
int cs(int x, int y)
{
	if (grid[x][y] == '0')
	{
		return inf;
	}
	if (isdigit(grid[x][y]))
	{
		return grid[x][y] - '0';
	}
	return 0;
}

int spfa(int S, int T)
{
	queue<int> Q;
	memset(dis, inf, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	vis[S/ 1000][S % 1000] = true;
	dis[S / 1000][S % 1000] = 0;
	Q.push(S);
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		int curx = cur / 1000;
		int cury = cur % 1000;
		vis[curx][cury] = false;
		for (int i = 0; i < 4; i++)
		{
			int tx = curx + dx[i];
			int ty = cury + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m)
			{
				continue;
			}
			if (dis[tx][ty] > dis[curx][cury] + cs(tx, ty))
			{
				dis[tx][ty] = dis[curx][cury] + cs(tx, ty);
				pre[tx][ty] = cur;
				if (!vis[tx][ty])
				{
					vis[tx][ty] = true;
					Q.push(tx * 1000 + ty);
				}
			}
		}
	}
	if (dis[T/ 1000][T % 1000] == inf)
	{
		return 0;
	}
	int p = T;
	int sum = 0;
	int MMax = 0;
	while (p != S)
	{
		int px = p / 1000;
		int py = p % 1000;
		sum += cs(px, py);
		MMax = max(MMax, cs(px, py));
		p = pre[px][py];
	}
	return cost - sum + MMax;
}
int main()
{
	int T;
	int kase = 1;
	while (cin >> T)
	{
		while (T--)
		{
			cin >> n >> m;
			int ss, tt;
			cost = 0;
			for (int i = 0; i < n; i++)
			{
				cin >> grid[i];
				for (int j = 0; j < m; j++)
				{
					if (grid[i][j] == 'A')
					{
						ss = i * 1000 + j;
					}
					if (grid[i][j] == 'B')
					{
						tt = i * 1000 + j;
					}
					if (grid[i][j] > '0' && grid[i][j] <= '9')
					{
						cost += grid[i][j] - '0';
					}
				}
			}
			cout << "Case #" << kase++ << ": " << spfa(ss, tt) << endl;
		}
	}
	return 0;
}

/*

4
2 4
0A24
701B
2 3
A04
90B
2 2
3A
B5
3 3
37A
496
B52

*/