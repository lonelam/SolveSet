#define _USE_MATH_DEFINES
#include <cstdio>
#include <cassert>
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
const int maxn = 10000 + 500;
const int scale = 22;
int fa[scale][maxn];
int dp[maxn];
ll dis[maxn];
struct edge
{
  int v;
  ll d;
} es[maxn * 2];
int tot;
vector<int> G[maxn];
void addedge(int u, int v, ll d)
{
  es[tot] = {v, d};
  G[u].push_back(tot++);
  es[tot] = {u, d};
  G[v].push_back(tot++);
}
void dfs(int cur, int p, int depth = 0)
{
  fa[0][cur] = p;
  dp[cur] = dp[p] + 1;
  for (int k = 0; k  + 1< scale; k++)
  {
    fa[k + 1][cur] = fa[k][fa[k][cur]];
  }
  for (int i = 0; i < G[cur].size(); i++)
  {
    edge & e = es[G[cur][i]];
    if (e.v != p)
    {
      dis[e.v] = dis[cur] + e.d;
      dfs(e.v, cur, depth + 1);
    }
  }
}
int lca(int x, int y)
{
  if (x == y) return x;
  if (fa[scale - 1][x] != fa[scale - 1][y]) return -1;
  if (dp[x] > dp[y]) swap(x, y);
  for (int k = scale - 1; k >= 0; k--)
  {
    if (dp[y] - (1 << k) >= dp[x])
    {
      y = fa[k][y];
    }
  }
  if (x == y) return x;
  assert(dp[x] == dp[y]);
  for (int k = scale - 1; k >= 0; k--)
  {
    if (fa[k][x] != fa[k][y])
    {
      x = fa[k][x];
      y = fa[k][y];
    }
  }
  return fa[0][x];
}
int main()
{
  static int n, m, c;
  while(scanf("%d%d%d", &n, &m, &c) !=EOF)
  {
    static int u, v;
    static ll d;
    tot = 0;
    for (int i = 1; i <= n; i++)
    {
      G[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d%lld", &u, &v, &d);
      assert(u > 0 && u <= n && v > 0 && u <= n);
      addedge(u, v, d);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
      if (dp[i] == -1)
      {
        for (int k = 0; k < scale; k++)
        {
          fa[k][i] = i;
        }
        dis[i] = 0;
        dp[i] = 0;
        dfs(i, i);
      }
    }
    for (int i = 0; i < c; i++)
    {
      scanf("%d%d", &u, &v);
      assert(u > 0 && u <= n && v > 0 && u <= n);
      int ans = lca(u, v);
      if (ans == -1)
      {
        printf("Not connected\n");
      }
      else
      {
        printf("%lld\n", dis[u] + dis[v] - 2 * dis[ans]);
      }
    }
  }
}
/*
10 8 10
1 3 2
1 2 2
2 5 2
2 6 2
3 4 2
3 7 2
3 8 2
9 10 5
*/
