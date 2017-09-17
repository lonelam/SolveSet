#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 100;
const int maxs = 800;
const int maxk = 19;
vector<int> G[maxn];
int d[maxn];
int fa[maxn][maxk];
int xsum[maxn][maxs];
int a[maxn];
int n, q;
int s_ub;
void init()
{
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  s_ub = sqrt(n) + 1;
  d[1] = 1;
}
int moveup(int u, int len)
{
  assert(d[u] > len);
  for (int k = 0; k < maxk && len; k++)
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
  d[u] = d[par] + 1;
  fa[u][0] = par;
  for (int s = 1; s < s_ub; s++)
  {
    xsum[u][s] = a[u];
    if (d[u] > s)
    {
      xsum[u][s] ^= xsum[moveup(u, s)][s];
    }
  }
  for (int i = 1; i < maxk; i++)
  {
    fa[u][i] = fa[fa[u][i-1]][i-1];
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
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (fa[x][k] != fa[y][k])
    {
      x = fa[x][k];
      y = fa[y][k];
    }
  }
  return fa[x][0];
}
int solve(int x, int y, int step)
{
  int l = lca(x, y);
  int dis = d[x] - d[l] + d[y] - d[l];
  if (dis % step)
  {
    if (d[y] - d[l] >= (dis % step))
    {
      y = moveup(y, dis % step);
    }
    else
    {
      y = moveup(x, dis - dis % step);
    }
    l = lca(x, y);
    dis = d[x] - d[l] + d[y] - d[l];
  }
  if (step < s_ub)
  {
    int ans = xsum[x][step] ^ xsum[y][step];
    if ((d[x] - d[l]) % step == 0)
    {
      ans ^= a[l];
    }
    return ans;
  }
  else
  {
    int  ans = a[x] ^ a[y];
    if (x == l)
    {
      ans ^= a[x];
    }
    while(d[x] - d[l] > step)
    {
      x = moveup(x, step);
      ans ^= a[x];
    }
    while(d[y] - d[l] >= step)
    {
      y = moveup(y, step);
      ans ^= a[y];
    }
    return ans;
  }
}
int main()
{
  while(~scanf("%d%d", &n, &q))
  {
    init();

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
    dfs(1, 1);
    for (int i = 0; i < q; i++)
    {
      static int u, v, k;
      scanf("%d%d%d", &u, &v, &k);
      printf("%d\n", solve(u,v,k));
    }
  }
}
