#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 60;
char grid[maxn][maxn];
int vis[maxn][maxn];
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool dfs(int x, int y, int d, char color)
{
    vis[x][y] = d;
    for (int dir = 0; dir < 4; dir++)
    {
        int tx = x + dx[dir];
        int ty = y + dy[dir];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m)
        {
            if (grid[tx][ty] == color)
            {
                if (!vis[tx][ty])
                {
                    if (dfs(tx, ty, d + 1, color)) return true;
                }
                else if (d > vis[tx][ty] + 2)
                {
                    //cout <<"debug";
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", grid[i]);
        }
        memset(vis,0,sizeof(vis));
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                {
                    if (dfs(i,j,1,grid[i][j]))
                    {
                        ans = true;
                    }
                }
            }
        }

        if (ans)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
