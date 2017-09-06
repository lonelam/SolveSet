#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, m;
int w[maxn];
vector<int> G[maxn];
int sccno[maxn], scctot;
vector<int> scc[maxn];
bool sccvis[maxn];
ll wsum[maxn];
int dfn[maxn], dfs_clock;
int low[maxn];
bool inq[maxn];
stack<int> stk;
void init()
{
  memset(wsum,0,sizeof(wsum));
  memset(sccvis, 0, sizeof(sccvis));
  memset(inq,0,sizeof(inq));
  memset(dfn, 0,sizeof(dfn));
  memset(low, 0, sizeof(low));
  dfs_clock = 1;
  for (int i = 1; i <= n; i++) G[i].clear();
  for (int i = 0; i < scctot; i++) scc[i].clear();
  scctot = 0;
}
void dfs(int u)
{
  dfn[u] = low[u] = dfs_clock++;
  stk.push(u);
  inq[u] = true;
  for (int v: G[u])
  {
    if (!dfn[v])
    {
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
    else if (inq[v])
    {
      low[u] = min(low[u], dfn[v]);
    }
  }
  int v;
  if (dfn[u] == low[u])
  {
    // wsum[scctot] = 0;
    do {
      v = stk.top();
      stk.pop();
      inq[v] = false;
      if (v != u) w[u] += w[v];
      sccno[v] = u;
    } while(u != v);
  }
}
void upd()
{
  for (int i = 1; i <= n; i++)
  {
    if (i != sccno[i])
    for (int v: G[i])
    {
      if (v != sccno[i])
      {
        G[sccno[i]].push_back(v);
      }
    }
  }
}
ll dp[maxn];
void sccdfs(int u)
{
  dp[u] = 0;
  sccvis[u] = true;
    for (int v: G[u])
    {
      if (u != sccno[v])
      {
        sccdfs(sccno[v]);
        dp[u] = max(dp[u], dp[sccno[v]]);
      }
    }
  dp[u] += w[u];
}
int main()
{
  scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", w + i);
    }
    for (int i = 0; i < m; i++)
    {
      static int u,v;
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
    }
    dfs(1);
    upd();
    sccdfs(sccno[1]);
    // assert(false);
    assert(stk.empty());
    printf("%lld\n", dp[sccno[1]]);
}
