#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 250000 + 100;
const int maxk = 21;
struct edge
{
  int v;
  ll c;
} es[maxn * 2];
vector<int> G[maxn], H[maxn];
//gtot : 0-maxn * 2;
//htot : maxn * 2 - maxn * 4;
int gtot, n, m;
int dfn[maxn], dfs_clock;
int fa[maxn][maxk], depth[maxn];
ll cut_cost[maxn];
void addG(int u, int v, ll w)
{
  es[gtot] = {v, w};
  G[u].push_back(gtot++);
  es[gtot] = {u, w};
  G[v].push_back(gtot++);
}
void addH(int u, int v)
{
  H[u].push_back(v);
}
void init()
{
  gtot = 0;
  for (int i = 0; i <= n; i++)
  {
    G[i].clear();
  }
  fa[0][0] = 0;
  depth[0] = -1;
  dfs_clock = 0;
  cut_cost[0] = inf;
}
void dfs(int cur, int parent)
{
  dfn[cur] = dfs_clock++;
  fa[cur][0] = parent;
  for (int k = 1; k < maxk; k++)
  {
    fa[cur][k] = fa[fa[cur][k-1]][k-1];
  }
  for (int i = 0; i < G[cur].size(); i++)
  {
    edge & e = es[G[cur][i]];
    if (e.v != parent)
    {
      cut_cost[e.v] = min(e.c, cut_cost[cur]);
      depth[e.v] = depth[cur] + 1;
      dfs(e.v, cur);
    }
  }
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
bool cmp(int lhs, int rhs)
{
  return dfn[lhs] < dfn[rhs];
}
int riches[maxn], kcnt;
void build()
{
  static int stk[maxn];
  sort(riches, riches + kcnt, cmp);
  int p = 0;
  for (int i = 1; i < kcnt; i++)
  {
    if (lca(riches[i], riches[p]) != riches[p])
    {
      riches[++p] = riches[i];
    }
  }
  kcnt = p + 1;
  int sz = 0;
  stk[sz++] = 0;
  for (int i = 0; i < kcnt; i++)
  {
    int f = lca(stk[sz - 1], riches[i]);
    if (f == stk[sz - 1])
    {
      stk[sz++] = riches[i];
    }
    else
    {
      while(sz - 2 >= 0 && depth[stk[sz - 2]] >= depth[f])
      {
        addH(stk[sz - 2], stk[sz - 1]);
        sz--;
      }
      if (stk[sz - 1] != f)
      {
        addH(f, stk[--sz]);
        stk[sz++] = f;
      }
      stk[sz++] = riches[i];
    }
  }
  for (int i = 1; i < sz; i++)
  {
    addH(stk[i-1], stk[i]);
  }
}
ll dp(int cur, int parent)
{
  if (H[cur].empty())
  {
    return cut_cost[cur];
  }
  ll ret = 0;
  for (int i = 0; i < H[cur].size(); i++)
  {
    int v = H[cur][i];
    if (v != parent) ret += dp(v, cur);
  }
  H[cur].clear();
  return min(ret, cut_cost[cur]);
}
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    init();
    addG(0, 1, inf);
    for (int i = 1; i < n; i++)
    {
      static int u, v;
      static ll w;
      scanf("%d%d%lld", &u, &v, &w);
      addG(u,v,w);
    }
    dfs(0, 0);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
      scanf("%d", &kcnt);
      for (int j = 0; j < kcnt; j++)
      {
        scanf("%d", riches + j);
      }
      build();
      ll ans = dp(0, 0);
      printf("%lld\n", ans);
    }
  }
}
