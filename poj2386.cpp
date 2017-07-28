#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 105;
char grid[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = {0,0,1,-1, 1, 1, -1,-1};
int dy[] = {1,-1,0,0, 1, -1, -1, 1};
int n, m;
void dfs(int x, int y)
{
  vis[x][y] = true;
  //cout << x << " "<< y << endl;
  for (int d = 0; d < 8; d++)
  {
    int tx = x + dx[d];
    int ty = y + dy[d];
    if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == 'W' && !vis[tx][ty])
    {
      dfs(tx, ty);
    }
  }
}
int main()
{
  while(cin >> n >> m)
  {
    memset(vis,0,sizeof(vis));
    for (int i = 0; i < n; i++)
    {
      cin >> grid[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!vis[i][j] && grid[i][j] == 'W')
        {
          cnt++;
          dfs(i, j);
        }
      }
    }
    cout << cnt << endl;
  }
}
