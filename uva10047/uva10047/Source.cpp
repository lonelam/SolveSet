#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
const int maxn = 26;
char maze[maxn][maxn];
bool vis[maxn][maxn][4][5];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
typedef tuple<int, int, int, int> state;
int bfs(int sx, int sy, int tx, int ty, int n, int m)
{
	queue<state> cur, nex;
	
	cur.push(state({ sx, sy, 3, 0 }));
	int t = 0;
	memset(vis, 0, sizeof(vis));
	while (!cur.empty())
	{
		while (!cur.empty())
		{
			state c = cur.front();
			int cx, cy, dir, ccolor;
			tie(cx, cy, dir, ccolor) = c;
			cur.pop();
			
			if (!vis[cx][cy][dir][ccolor])
			{
				vis[cx][cy][dir][ccolor] = true;
				if (cx == tx && cy == ty && ccolor == 0)
				{
					return t;
				}
				int tcolor = (ccolor + 1) % 5;
				for (int i = -1; i <= 1; i++)
				{
					int td = (dir + i + 4) % 4;
					int ttx = cx + dx[td];
					int tty = cy + dy[td];
					if (ttx >= 0 && ttx < n && tty >= 0 && tty < m && maze[ttx][tty] != '#' && !vis[ttx][tty][td][tcolor])
					{
						nex.push({ ttx, tty, td, tcolor });
					}
				}
			}
			

		}
		swap(cur, nex);
		t++;
	}
	return -1;
}

int main()
{
	int m, n;
	int sx, sy, tx, ty;
	int kase = 1;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
		{
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			scanf(
				"%s", maze[i]
			);
			for (int j = 0; j < m; j++)
			{
				if (maze[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
				if (maze[i][j] == 'T')
				{
					tx = i;
					ty = j;
				}
			}
		}
		int ans = bfs(sx, sy, tx, ty, n, m);
		if (ans == -1)
		{
			printf("Case #%d\ndestination not reachable\n", kase++);
		}
		else
		{
			printf("Case #%d\nminimum time = %d sec\n", kase++, ans);
		}
		
	}
}