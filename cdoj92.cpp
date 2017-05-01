#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const int DEG = 20;
struct edge
{
  int to, cost;
}es[maxn << 1];
vector<int> G[maxn];
int fa[maxn][DEG];
int n, T, q, x, y, z, tot, X, Y, Z;
int d[maxn];
int dis[maxn];
int root;
void add_edge()
{
  G[x].push_back(tot);
  es[tot++] = {y, z};
  G[y].push_back(tot);
  es[tot++] = {x, z};
}
void init()
{
  tot = 0;
  root = 1;
  fa[root][0] = 0;
  for (int i = 0; i < DEG; i++)
  {
    fa[0][i] = 0;
  }
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  d[0] = -1;
  dis[0] = dis[1] = 0;
}
void dfs(int cur, int p)
{
  fa[cur][0] = p;
  d[cur] = d[p] + 1;
  for (int i = 1; i < DEG; i++)
  {
    fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
  }
  for (int i = 0; i < G[cur].size(); i++)
  {
    edge & e = es[G[cur][i]];
    if (e.to != p)
    {
      dis[e.to] = dis[cur] + e.cost;
      dfs(e.to, cur);
    }
  }
}
int lca(int u, int v)
{
  if (d[u] > d[v]) swap(u, v);
  int hu = d[u], hv = d[v];
  for (int i = DEG - 1; i >= 0; i--)
  {
    if (hv - (1 << i) >= hu)
    {
      hv -= 1 << i;
      v = fa[v][i];
    }
  }
  if (u == v)
  {
    return u;
  }
  for (int i = DEG - 1; i >= 0; i--)
  {
    if (fa[v][i] != fa[u][i])
    {
      v = fa[v][i];
      u = fa[u][i];
    }
  }
  return fa[v][0];
}
int DIS(int u, int v)
{
  int papa = lca(u, v);
  return dis[u] + dis[v] - 2 * dis[papa];
}
int solve(int u, int v)
{
  return DIS(u, v) - min({DIS(u, v), DIS(u, X) + DIS(v, Y) + Z, DIS(u, Y) + DIS(v, X) + Z});
}
int main()
{
  int kase = 1;
  while(scanf("%d", &T)!= EOF)
  {
    while(T--)
    {
      printf("Case #%d:\n", kase++);
      scanf("%d%d", &n, &q);
      init();
      for (int i = 1; i < n; i++)
      {
        scanf("%d%d%d", &x, &y, &z);
        add_edge();
      }
      dfs(1, 0);
      scanf("%d%d%d", &X, &Y, &Z);
      for (int i = 0; i < q; i++)
      {
        scanf("%d%d", &x, &y);
        printf("%d\n", solve(x, y));
      }
    }
  }
}
