#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
struct edge
{
  int u, v;
  ll w;
} es[maxn * 2];
int tot;
vector<int> G[maxn];
set<int> dfnset;
int n, q;
int dfn[maxn], dfs_clock;
int rdfn[maxn];
ll ans = 0;
void init()
{
  tot = 0;
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  dfs_clock = 0;
  ans = 0;
  dfnset.clear();
}
void addedge(int u, int v, int w)
{
  G[u].push_back(tot);
  es[tot++] = {u, v, w};
  G[v].push_back(tot);
  es[tot++] = {v, u, w};
}
const int maxk = 18;
int d[maxn], fa[maxn][maxk];
ll dis[maxn];

void dfs(int cur)
{
  rdfn[dfs_clock] = cur;
  dfn[cur] = dfs_clock++;
  for (int k = 1; k < maxk; k++)
  {
    fa[cur][k] = fa[fa[cur][k - 1]][k - 1];
  }
  for (int i = 0; i < G[cur].size(); i++)
  {
    edge & e = es[G[cur][i]];
    if (e.v != fa[cur][0])
    {
      fa[e.v][0] = cur;
      dis[e.v] = dis[cur] + e.w;
      d[e.v] = d[cur] + 1;
      dfs(e.v);
    }
  }
}
int lca(int x, int y)
{
  if (d[x] < d[y]) swap(x, y);
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (d[x] - (1 << k) >= d[y])
    {
      x = fa[x][k];
    }
  }
  if (x == y)
  {
    return x;
  }
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
ll pathcalc(int x, int y)
{
  int f = lca(x, y);
  //cout << x << " "<< y << " "<< f<< endl;
  return dis[x] + dis[y] - dis[f] * 2;
}
int main()
{
  int kase = 1;
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d", &n, &q);
    init();
    //cout << n << endl;
    for (int i = 1; i < n; i++)
    {
      static int u, v;
      static ll w;
      scanf("%d%d%lld", &u, &v, &w);
      addedge(u, v, w);
     // cout << u << " "<< v << " "<< w << endl;
    }
    fa[1][0] = 1;
    dfs(1);
    printf("Case #%d:\n", kase++);
    for (int i = 0; i < q; i++)
    {
      static int cmd, oprand;
      scanf("%d%d", &cmd, &oprand);
      ll tmp = 0;
      if (cmd == 1 && dfnset.find(dfn[oprand]) == dfnset.end())
      {
        dfnset.insert(dfn[oprand]);
        auto pre = dfnset.lower_bound(dfn[oprand]);
        auto post = dfnset.upper_bound(dfn[oprand]);
        if (pre != dfnset.begin())
        {
          auto tmp = prev(pre);
          ans += pathcalc(rdfn[*tmp], oprand);
        }
        if (post != dfnset.end())
        {
          ans += pathcalc(rdfn[*post], oprand);
        }
        if (pre != dfnset.begin() && post != dfnset.end())
        {
          auto tmp = prev(pre);
          ans -= pathcalc(rdfn[*tmp], rdfn[*post]);
        }
      }
      else if (cmd == 2 && dfnset.find(dfn[oprand]) != dfnset.end())
      {
        dfnset.erase(dfn[oprand]);
        auto pre = dfnset.lower_bound(dfn[oprand]);
        auto post = dfnset.upper_bound(dfn[oprand]);
        if (pre != dfnset.begin())
        {
          auto tmp = prev(pre, 1);
          ans -= pathcalc(rdfn[*tmp], oprand);
        }
        if (post != dfnset.end())
        {
          ans -= pathcalc(rdfn[*post], oprand);
        }
        if (pre != dfnset.begin() && post != dfnset.end())
        {
          auto tmp = prev(pre);
          ans += pathcalc(rdfn[*tmp], rdfn[*post]);
        }
      }
        if (!dfnset.empty())
        {
          tmp = pathcalc(rdfn[*dfnset.begin()], rdfn[*dfnset.rbegin()]);
        }
      printf("%lld\n", (ans + tmp)/ 2);
    }
  }
}
/*
1
6 100
1 2 2
1 5 2
5 6 2
2 4 2
2 3 2
*/
