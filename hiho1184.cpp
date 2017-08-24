#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 20000 + 100;
int dfs_clock, dfn[maxn];
int low[maxn];
vector<int> G[maxn];
stack<int> stk;
int bccno[maxn], bcctot;
vector<int> bcc[maxn];
int n, m;
void addedge(int u, int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}
void init()
{
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  dfs_clock = 1;
  memset(low, 0, sizeof(low));
  memset(dfn, 0, sizeof(dfn));
  for (int i = 0; i < bcctot; i++)
  {
    bcc[i].clear();
  }
  bcctot = 0;
}
void dfs(int u, int fa)
{
  int cnt = 0;
  dfn[u] = low[u] = dfs_clock++;
  stk.push(u);
  for (int v: G[u])
  {
    if (!dfn[v])
    {
      cnt++;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    }
    else if (fa != v)
    {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u])
  {
    do {
      int p = stk.top(); stk.pop();
      bccno[p] = bcctot;
      bcc[bcctot].push_back(p);
      if (p == u) break;
    } while(true);
    bcctot++;
  }
}
int main()
{
  while(scanf("%d%d", &n, &m) != EOF)
  {
    init();
    for (int i = 0; i < m; i++)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      addedge(u, v);
    }
    dfs(1,1);
    printf("%d\n", bcctot);
    for (int i = 0; i < bcctot; i++)
    {
      sort(bcc[i].begin(), bcc[i].end());
    }
    for (int i = 1; i <= n; i++)
    {
      printf("%d%c", bcc[bccno[i]][0], i==n?'\n':' ');
    }
  }
}
