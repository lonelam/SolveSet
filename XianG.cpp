#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 100;
const int maxq = 1000;
int Mq = 0;
const int maxk = 17;
int n, q;
int fa[maxn][maxk];
int sum[maxn][maxq];
vector<int> G[maxn];
int a[maxn];
int d[maxn];
void init()
{
  memset(fa, 0, sizeof(fa));
  memset(sum, 0, sizeof(sum));
  memset(a, 0, sizeof(a));
  memset(d, 0, sizeof(d));
}
int stepup(int u, int len)
{
  for (int k = 0; len && k < maxk; k++)
  {
    if (len & 1)
    {
      u = fa[u][k];
    }
    len >>= 1;
  }
  return u;
}
void dfs(int u, int par)
{
  fa[u][0] = par;
  d[u] = d[par] + 1;
  for (int k = 1; k < maxk; k++)
  {
    fa[u][k] = fa[fa[u][k-1]][k-1];
  }
  for (int q = 1; q < Mq; q++)
  {
    sum[u][q] = a[u];
    if (q < d[u])
    {
      sum[u][q] ^= sum[stepup(u, q)][q];
    }
  }
  for (int v: G[u])
  {
    if (v != par)
    {
      dfs(v, u);
    }
  }
}
int lca(int x, int y)
{
  if (d[x] > d[y]) swap(x, y);
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (d[fa[y][k]] >= d[x])
    {
      y = fa[y][k];
    }
  }
  if (x == y) return x;
  for (int k = maxk -1 ; k>= 0; k--)
  {
    if (fa[x][k] != fa[y][k])
    {
      x = fa[x][k];
      y = fa[y][k];
    }
  }
  return fa[x][0];
}
int solve(int u, int v, int rep)
{
  int l = lca(u, v);
  int dis = d[u] - d[l] + d[v] - d[l];
  if (d[v] - d[l] >= dis % rep)
  {
    v = stepup(v, dis % rep);
    dis -= dis % rep;
  }
  else
  {
    v = stepup(u, dis - dis % rep);
    l = v;
    dis -= dis % rep;
  }
  // if (u == v) return a[u];
  assert((d[u] - d[l] + d[v] - d[l])% rep == 0);
  if (rep >= Mq)
  {
    int res = a[u] ^ a[v];
    if (u == l)
    {
      res ^= a[u];
    }
    assert(d[u] >= d[l]);
    while(d[u] - d[l] > rep)
    {
      u = stepup(u, rep);
      // d[stepup(u, rep)] = d[l];
      res ^= a[u];
    }
    assert(d[v] >= d[l]);
    while(d[v] - d[l] >= rep)
    {
      v = stepup(v, rep);
      res ^= a[v];
    }
    return res;
  }
  else
  {
    int res = sum[u][rep] ^ sum[v][rep];
    if ((d[l] - d[u] ) % rep == 0)
    {
      assert((d[l] - d[v]) % rep == 0);
      res ^= a[l];
    }
    return res;
  }
}
int main()
{
  while(~scanf("%d%d", &n, &q))
  {
    init();
    Mq = sqrt(n) + 2;
    // Mq = 0;
    for (int i = 1; i <= n; i++)
    {
      G[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
      static int u, v;
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", a + i);
    }
    d[1] = 0;
    dfs(1, 1);
    while(q--)
    {
      static int u, v, k;
      scanf("%d%d%d", &u, &v, &k);
      printf("%d\n", solve(u, v, k));
    }
  }
}
/*
7 100
1 2
1 3
2 4
2 5
3 6
6 7
1 2 4 8 16 32 64
1 6 2
4 5 1
4 5 2
4 7 2
5 7 2
*/
