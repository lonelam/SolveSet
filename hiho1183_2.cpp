#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 20000 + 100;
int n, m;
vector<int> G[maxn];
int dfs_clock;
int dfn[maxn];
int low[maxn];
bool iscut[maxn];
//求桥
vector<pair<int,int> > bridge;
void init()
{
  dfs_clock = 1;
  memset(dfn, 0,sizeof(dfn));
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  memset(iscut,0,sizeof(iscut));
  bridge.clear();
}
void addedge(int u, int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}
void dfs(int u, int fa)
{
  low[u] = dfn[u] = dfs_clock++;
  int cnt = 0;
  for (int v: G[u])
  {
    if (v != fa)
    {
      if (!dfn[v])
      {
        dfs(v, u);
        cnt++;
        low[u] = min(low[u], low[v]);
        if (u == 1 && cnt > 1)
        {
          iscut[u] = true;
        }
        if (u != 1 && low[v] >= dfn[u])
        {
          iscut[u] = true;
        }
        if (low[v] > dfn[u])
        {
          bridge.push_back({min(u,v), max(u,v)});
        }
      }
      else
      {
        low[u] = min(low[u], dfn[v]);
      }
    }
  }
  if (cnt <= 1 && u == 1) iscut[u] = false;
}
int main()
{
  while(scanf("%d%d", &n, &m) != EOF)
  {
    init();
    for (int i = 0; i < m; i++)
    {
      static int u, v;
      scanf("%d%d", &u, &v);
      addedge(u,v);
    }
    dfs(1, 1);
    int flg = true;
    for (int i = 1; i <= n; i++)
    {
      if (iscut[i])
      {
        if (flg)
        {
          printf("%d", i);
          flg = false;
        }
        else
        {
          printf(" %d", i);
        }
      }
    }
    if (flg)
    {
      printf("Null");
    }
    printf("\n");
    for (pair<int,int>& ans: bridge)
    {
      if (ans.first > ans.second ) swap(ans.first, ans.second);
    }
    sort(bridge.begin(), bridge.end());
    for (pair<int,int> ans: bridge)
    {
      if (ans.first > ans.second ) swap(ans.first, ans.second);
      printf("%d %d\n", ans.first, ans.second);
    }
  }
}
