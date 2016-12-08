#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;
const int maxn = 1005;
char maze[maxn][maxn];
int firetime[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = { 0 , 0, 1,-1 };
int dy[] = { 1, -1,0,0 };
int bfs(int n, int m, int jx, int jy, vector<pair<int, int>> & fires)
{
	queue<pair<int, int>> cur, nex;
	for (pair<int, int> of : fires)
	{
		cur.push(of);
	}
	int t = 0;
	memset(vis, 0, sizeof(vis));
	memset(firetime, 0x3f, sizeof(firetime));
	while (!cur.empty())
	{
		t++;
		while (!cur.empty())
		{
			pair<int, int> c = cur.front();
			cur.pop();
			if (!vis[c.first][c.second])
			{
				vis[c.first][c.second] = true;
				firetime[c.first][c.second] = t;
				for (int i = 0; i < 4; i++)
				{
					int tx = c.first + dx[i], ty = c.second + dy[i];
					if (tx >= 0 && tx < n && ty >= 0 && ty < m && maze[tx][ty] != '#' && !vis[tx][ty])
					{
						nex.push({ tx, ty });
					}
				}
			}
		}
		swap(cur, nex);
		
	}
	t = 0;
	cur.push({ jx, jy });
	memset(vis, 0, sizeof(vis));
	while (!cur.empty())
	{
		t++;
		while (!cur.empty())
		{
			pair<int, int > c = cur.front();
			cur.pop();
			if ((c.first == 0 || c.first == n - 1 || c.second == 0 || c.second == m - 1 )&& firetime[c.first][c.second] > t)
			{
				return t;
			}
			if (!vis[c.first][c.second])
			{
				vis[c.first][c.second] = true;
				for (int i = 0; i < 4; i++)
				{

					int tx = c.first + dx[i], ty = c.second + dy[i];
					if (tx >= 0 && tx < n && ty >= 0 && ty < m && maze[tx][ty] != '#' && !vis[tx][ty] && firetime[tx][ty] > t)
					{
						nex.push({ tx, ty });
					}
				}
			}
		}
		swap(cur, nex);
	}
	return -1;
}
int main()
{
	int t, m , n , jx, jy;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", maze[i]);
		}
		vector<pair<int, int>> fire;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (maze[i][j] == 'J')
				{
					jx = i;
					jy = j;
				}
				if (maze[i][j] == 'F')
				{
					fire.push_back({ i,j });
				}
			}
		}
		int ans = bfs(n, m, jx, jy, fire);
		if (ans == -1)
		{
			printf("IMPOSSIBLE\n");

		}
		else
		{
			printf("%d\n", ans);
		}
	}
}