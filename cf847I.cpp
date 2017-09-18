#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 250 + 3;
int n, m, q, p;
int ans[maxn][maxn];
char grid[maxn][maxn];
typedef pair<int,int> pii;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int vis[maxn][maxn];
void bfs(int cx, int cy)
{
  queue<pii> * cur = new queue<pii>(), *nex = new queue<pii>;
  // set<pii> vis;
  cur->push({cx, cy});
  int hash = (cx << 10) + cy;
  vis[cx][cy] = hash;
  int val = q * (grid[cx][cy] - 'A' + 1);
  while(!cur->empty())
  {
    while(!cur->empty())
    {
      pii c = cur->front(); cur->pop();
      ans[c.first][c.second] += val;
      for (int d = 0; d < 4; d++)
      {
        pii t = {c.first + dx[d], c.second + dy[d]};
        if (t.first >= 0 && t.first < n && t.second >= 0 && t.second < m && grid[t.first][t.second] != '*' && vis[t.first][t.second] != hash)
        {
          vis[t.first][t.second] = hash;
          nex->push(t);
        }
      }
    }
    swap(cur, nex);
    val >>= 1;
    // cout << val << endl;
    if (!val) {
      delete cur;
      delete nex;
      return;
    }
  }
  delete cur;
  delete nex;
}
int main()
{
  scanf("%d%d%d%d", &n, &m, &q, &p);
  memset(vis, -1, sizeof(vis));
  for (int i = 0; i < n; i++)
  {
    scanf("%s", grid[i]);
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (isalpha(grid[i][j]))
      {
        bfs(i, j);
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     cout << ans[i][j] << " ";
  //   }
  //   cout << endl;
  // }
      }
    }
  }
  int op = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (ans[i][j] > p) op++;
    }
  }
  printf("%d\n", op);
}
