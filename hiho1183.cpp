#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int dfs_clock, dfn[maxn], par[maxn], low[maxn];
int n, m;
vector<int> cut;
vector<pair<int,int> > bridge;
bool vis[maxn];
vector<int> G[maxn];
void dfs(int u)
{
  int chcnt = 0;
  vis[u] = true;
  low[u] = dfn[u] = ++dfs_clock;
  for (int v: G[u])
  {
    if (!vis[v])
    {
      chcnt++;
      par[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (par[u] == u && chcnt > 1)
      {
        cut.push_back(u);
      }
      if (par[u] != u && low[v] >= dfn[u])
      {
        cut.push_back(u);
      }
      if (low[v] > dfn[u])
      {
        bridge.push_back({min(u,v), max(u,v)});
      }
    }
    else if (v != par[u] && dfn[v] < dfn[u])
    {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

int main()
{
  while(scanf("%d%d", &n, &m)!=EOF)
  {
    for (int i = 1; i <= n; i++)
    {
      G[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
      static int u, v;
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    memset(par, 0, sizeof(par));
    memset(vis,0,sizeof(vis));
    cut.clear();
    bridge.clear();
    par[1] = 1;
    dfs(1);
    sort(cut.begin(), cut.end());
    cut.erase(unique(cut.begin(), cut.end()), cut.end());
    sort(bridge.begin(), bridge.end());
    if (cut.empty())
    {
      printf("Null\n");
    }
    for (int i = 0; i < cut.size(); i++)
    {
      assert(!(i && cut[i] <= cut[i-1]));
      printf("%d%c", cut[i], (i == cut.size() - 1) ? '\n': ' ');
    }
    for (int i = 0; i < bridge.size(); i++)
    {
      assert(!(i && (bridge[i].first < bridge[i - 1].first || bridge[i].first == bridge[i].first && bridge[i].second < bridge[i].second)));
      if (bridge[i].first > bridge[i].second) swap(bridge[i].first, bridge[i].second);
      printf("%d %d\n", bridge[i].first, bridge[i].second);
    }
  }
}
