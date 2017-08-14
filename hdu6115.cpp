#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const int maxk = 20;
int n, m;
struct query
{
  int x, y, id;
};
vector<query> qs[maxn];
vector<int> fac[maxn];
ll dis[maxn];
int dfn[maxn], dfs_clock;
inline bool cmp(const int i, const int j)
{
  return dfn[i] < dfn[j];
}
int fa[maxn][maxk], depth[maxn];
struct edge
{
  int v;
  int w;
}es[maxn * 2];
vector<int> G[maxn];
int tot;
void init()
{
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  for (int i = 1; i <= m; i++)
  {
    qs[i].clear();
    fac[i].clear();
  }
  tot = 0;
  dfs_clock = 0;
}
void addG(int u, int v, int w)
{
  G[u].push_back(tot);
  es[tot++] = {v, w};
  G[v].push_back(tot);
  es[tot++] = {u, w};
}
int lca(int x, int y)
{
  if (depth[x] < depth[y]) swap(x, y);
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (depth[fa[x][k]] >= depth[y])
    {
      x = fa[x][k];
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
void dfs(int cur, int parent)
{
  fa[cur][0] = parent;
  dfn[cur] = dfs_clock++;
  for (int k = 1; k < maxk; k++)
  {
    fa[cur][k] = fa[fa[cur][k - 1]][k-1];
  }
  for (int eno: G[cur])
  {
    edge & e = es[eno];
    if(e.v != parent)
    {
      dis[e.v] = e.w + dis[cur];
      depth[e.v] = 1 + depth[cur];
      dfs(e.v, cur);
    }
  }
}
ll dist(int u, int v)
{
  int _lca = lca(u, v);
  return dis[u] + dis[v] - 2 * dis[_lca];
}
void solve()
{
  init();
  for (int i = 1; i < n; i++)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    addG(u, v, w);
  }
  depth[1] = dis[1] = 0;
  dfs(1, 1);
  for (int i = 1; i <= m; i++)
  {
    static int gg;
    scanf("%d", &gg);
    for (int j = 0; j < gg; j++)
    {
      static int tmp;
      scanf("%d", &tmp);
      fac[i].push_back(tmp);
    }
    sort(fac[i].begin(), fac[i].end(), cmp);
  }
  int Q;
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++)
  {
    static int a, b;
    scanf("%d%d", &a, &b);
    ll ans = 0x3f3f3f3f3f3f3f3f;
    if (fac[a].size() < fac[b].size()) swap(a, b);
    for (int x: fac[b])
    {
      auto lb = lower_bound(fac[a].begin(), fac[a].end(), x, cmp);
      if (lb != fac[a].end())
      {
        ans = min(ans, dist(*lb, x));
      }
      if (lb != fac[a].begin())
      {
        lb--;
        ans = min(ans, dist(*lb, x));
      }
    }
    printf("%lld\n", ans);
  }
}
int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d%d", &n, &m);
      solve();
    }
  }
}
