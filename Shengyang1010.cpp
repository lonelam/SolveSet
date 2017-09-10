#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 100;
const int maxk = 21;
int fa[maxn][maxk];
int d[maxn];
int n;
vector<int> G[maxn];
//get path from leaves
vector<int> trace[maxn];
vector<int> rule[maxn];
int ans;
struct path
{
  int u, v;
  int lca;
}ps[maxn];
int psvis[maxn];
void init()
{
  memset(psvis,0,sizeof(psvis));
  for (int i = 0; i <= n; i++)
  {
    rule[i].clear();
    G[i].clear();
    trace[i].clear();
  }
  ans = 0;
}
int lca(int u, int v)
{
  if (d[u] < d[v])
  {
    swap(u,v);
  }
  for (int k = maxk - 1; k >= 0; k--)
  {
    if(d[fa[u][k]] >= d[v])
    {
      u = fa[u][k];
    }
  }
  if (u == v)
  {
    return u;
  }
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (fa[u][k] != fa[v][k])
    {
      u = fa[u][k];
      v = fa[v][k];
    }
  }
  return fa[u][0];
}
void dfs(int u, int p)
{
  d[u] = d[p] + 1;
  fa[u][0] = p;
  for (int k = 1; k < maxk; k++)
  {
    fa[u][k] = fa[fa[u][k-1]][k-1];
  }
  for (int v: G[u])
  {
    if (v != p)
    {
      dfs(v, u);
    }
  }
}
set<int> dfs2(int u)
{
  set<int> now;
  for (int v: G[u])
  {
    if (v != fa[u][0])
    {
      set<int> tmp = dfs2(v);
      for (int s: tmp)
      {
        if (!psvis[s])
        {
          now.insert(s);
        }
      }
    }
  }
  for (int s: trace[u])
  {
    if (!psvis[s])
    {
      now.insert(s);
    }
  }
  for (int s: rule[u])
  {
    if (!psvis[s])
    {
      for (int x: now)
      {
        psvis[x] = true;
      }
      ans++;
      now.clear();
      return now;
    }
  }
  return now;
}
int main()
{
  while(~scanf("%d", &n))
  {
    int u, v;
    init();
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    d[0] = 0;
    dfs(0, 0);
    int p;
    scanf("%d", &p);
    for (int i = 0; i < p; i++)
    {
      scanf("%d%d", &ps[i].u, &ps[i].v);
      trace[ps[i].u].push_back(i);
      trace[ps[i].v].push_back(i);
      ps[i].lca = lca(ps[i].u, ps[i].v);
      rule[ps[i].lca].push_back(i);
    }
    dfs2(0);
    printf("%d\n", ans);
  }
}
/*

6
0 1
0 2
2 3
2 4
4 5
4 6
3
1 3
3 4
5 6

*/
