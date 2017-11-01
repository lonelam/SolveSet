#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
bool cnt[maxn][maxn];
int vis[maxn][maxn];
int n, m, a, b;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void dfs(int x, int y)
{
  if (vis[x][y]) return;
  vis[x][y] = 1;
  for (int d = 0; d < 4; d++)
  {
    int tx = x + dx[d] * a, ty = y + dy[d] * a;
    if (0 <= tx+dx[(d+1)%4]*b && tx+dx[(d+1)%4]*b < n &&  0 <= ty + dy[(d+1)%4]*b &&  ty + b*dy[(d+1)%4] < m)
    {
      dfs(tx+b*dx[(d+1)%4],  ty + b*dy[(d+1)%4] );
    }
    if (0 <= tx+b*dx[(d+3)%4] && tx+b*dx[(d+3)%4] < n &&  0 <= ty + b*dy[(d+3)%4] &&  ty + b*dy[(d+3)%4] < m)
    {
      dfs(tx+b*dx[(d+3)%4],  ty + b*dy[(d+3)%4] );
    }
  }
}
int main()
{
  while(cin >> n >> m >> a >> b)
  {
    memset(vis, 0, sizeof(vis));
    dfs(0, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
      //  cout << vis[i][j] << " ";
        ans += vis[i][j];
      }
      //cout << endl;
    }
    cout << ans << endl;
  }
}
