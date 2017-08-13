#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
char grid[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
void dfs(int x, int y)
{
  vis[x][y] = true;
  for (int d = 0; d < 4; d++)
  {
    int tx = x + dx[d];
    int ty = y + dy[d];
    if (tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty] && grid[tx][ty] == grid[x][y])
    {
      dfs(tx, ty);
    }
  }
}
int solve()
{
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!vis[i][j])
      {
        if (grid[i][j] == '0')
        {
          cnt0++;
        }
        else
        {
          cnt1++;
        }
        dfs(i, j);
      }
    }
  }
  if (cnt0 == 2 && cnt1 == 1) return 0;
  if (cnt0 == 1 && cnt1 == 1) return 1;
  return -1;
}
int main()
{
  while(scanf("%d%d", &n, &m) != EOF)
  {
    for (int i =1; i <= n; i++)
    {
      scanf("%s", grid[i] + 1);
    }
    n++;
    m++;
    for (int i = 0; i <= n; i++)
    {
      grid[i][0] = '0';
      grid[i][m] = '0';
    }
    for (int i = 0; i <= m; i++)
    {
      grid[0][i] = '0';
      grid[n][i] = '0';
    }
    n++;
    m++;
    // for (int i = 0; i < n; i++)
    // {
    //   for (int j = 0; j < m; j++)
    //   {
    //     cout << grid[i][j];
    //   }
    //   cout << endl;
    // }
    memset(vis,0,sizeof vis);
    printf("%d\n", solve());
  }
}
