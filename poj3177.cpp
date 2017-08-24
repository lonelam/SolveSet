#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 5;
const int maxm = 10000 + 5;
int n, m, num, ans, cnt, top;
int stk[maxn], low[maxn], dfn[maxn], color[maxn], deg[maxn];
vector<int> G[maxn];
bool isIn[maxn], vis[maxn][maxn];
void Tarjan(int u, int p)
{
  stk[++top] = u;
  isIn[u] = true;
  dfn[u] = low[u] = ++num;
  int v;
  for (int i = 0; i < G[u].size(); i++)
  {
    v = G[u][i];
    if (v != p)
    {
      if (dfn[v] == 0)
      {
        Tarjan(v, u);
        low[u] = min(low[u], low[v]);
      }
      else if (isIn[v] && dfn[v] < low[u])
      {
        low[u] = dfn[v];
      }
    }
  }
  if (dfn[u] == low[u])
  {
    ++cnt;
    do {
      v = stk[top--];
      isIn[v] = false;
      color[v] = cnt;
    } while(v != u);
  }
}
int solve()
{
  cnt = num = top = 0;
  memset(dfn, 0, sizeof(dfn));
  memset(isIn, 0, sizeof(isIn));
  for (int i = 1; i <= n; i++)
  {
    if (dfn[i] == 0)
    {
      Tarjan(i, 0);
    }
  }
  memset(deg, 0, sizeof(deg));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < G[i].size(); j++)
    {
      if (color[i] != color[G[i][j]])
      {
        ++deg[color[i]];
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= cnt; i++)
  {
    if (deg[i] == 1)
    {
      ++ans;
    }
  }
  return (ans + 1) >> 1;
}
int main()
{
  int s, e;
  while(scanf("%d%d", &n, &m) != EOF)
  {
    for (int i = 1; i <= n; i++)
    {
      G[i].clear();
      for (int j = i; j <= n; j++)
      {
        vis[i][j] = vis[j][i] = false;
      }
    }
    while(m--)
    {
      scanf("%d%d", &s, &e);
      if (!vis[s][e])
      {
        vis[s][e] = vis[e][s] = true;
        G[s].push_back(e);
        G[e].push_back(s);
      }
    }
    printf("%d\n", solve());
  }
}
