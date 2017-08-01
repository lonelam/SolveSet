#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 200000 + 100;
struct edge
{
  int v, w;
} es[maxn * 2];
int tot = 0;;
vector<int> G[maxn];
int fa[maxn];
int cycp = -1;
ll dp[maxn];
bool iscyc[maxn];
void dfs(int cur)
{
  for (int e: G[cur])
  {
    int v = es[e].v;
    if (v == fa[cur]) continue;
    if (fa[v])
    {
      cycp = cur;
      fa[v] = cur;
      continue;
    }
    fa[v] = cur;
    dfs(v);
  }
}
void dfs2(int cur)
{
  for(int en: G[cur])
  {
    edge & e = es[en];
    if (e.v == fa[cur] || iscyc[e.v])
    {
      continue;
    }
    fa[e.v] = cur;
    dfs2(e.v);
    dp[cur] = max(dp[cur], dp[e.v] + (ll)e.w);
  }

}
void addedge(int u, int v, int w)
{
  G[u].push_back(tot);
  es[tot++] = {v,w};
  G[v].push_back(tot);
  es[tot++] = {u, w};
}
ll dp2[maxn], dp3[maxn];
bool vis[maxn * 2];
void dfs3(int cur)
{
  for(int en: G[cur])
  {
    edge & e = es[en];
    if (e.v == fa[cur])
    {
      dfs3(e.v);
      dp2[cur] = dp2[e.v] + (ll)e.w;
    }
  }
}
int main()
{
  int n;
  int u,v,l;
  while(scanf("%d", &n) != EOF)
  {
    tot = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &u, &v, &l);
      addedge(u,v,l);
    }
    dfs(1);
    int p = cycp;
    while(fa[p] != cycp)
    {
      iscyc[p] = true;
      p = fa[p];
    }
    ll cyclen = 0;
    ll ans = inf;
    for (int i = 1; i <= n; i++)
    {
      if (iscyc[i])
      {
        dfs2(i);
        for (int en: G[i])
        {
          if (iscyc[es[en].v])
          {
            cyclen += es[en].w;
          }
        }
      }
    }
  }
}
