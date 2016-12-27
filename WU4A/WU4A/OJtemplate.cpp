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
bool vis[maxn][maxn][11];
int dis[maxn][maxn][11];
int pre[maxn][maxn][11];
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
	vis[S/ 1000][S % 1000][0] = true;
	dis[S / 1000][S % 1000][0] = 0;
	Q.push(S * 10);
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
        int curd = cur % 10;
		int curx = cur / 10000;
		int cury = (cur / 10) % 1000;
        vis[curx][cury][curd] = false;
		for (int i = 0; i < 4; i++)
		{
			int tx = curx + dx[i];
			int ty = cury + dy[i];
            int td = max(curd, cs(tx, ty));
			if (td == inf || tx < 0 || ty < 0 || tx >= n || ty >= m)
			{
				continue;
			}
			if (dis[tx][ty][td] > dis[curx][cury][curd] + cs(tx, ty))
			{
				dis[tx][ty][td] = dis[curx][cury][curd] + cs(tx, ty);
				pre[tx][ty][td] = cur;
				if (!vis[tx][ty][td])
				{
					vis[tx][ty][td] = true;
					Q.push(tx * 10000 + ty * 10 + td);
				}
			}
		}
	}
    bool iscon = false;
    int tx = T / 1000;
    int ty = T % 1000;
    int ans = 0;
    S *= 10;
  //  cout << S << endl;
    for (int i = 0; i < 10; i++)
    {
        if (dis[tx][ty][i] != inf)
        {
            iscon = true;
            int p = T * 10 + i;
            int sum = 0;
            while(p != S)
            {
                int pd = p % 10;
                p /= 10;
                int px = p / 1000;
		        int py = p % 1000;
                sum += cs(px, py);
                p = pre[px][py][pd];
            }
            ans = max(ans, cost + i - sum);
        }
    }
    return ans;
    if (!iscon)
	{
		return 0;
	}
    return ans;
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
