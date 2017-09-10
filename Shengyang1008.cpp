#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
ll p[maxn];
ll dpbuy[maxn];
ll dpsell[maxn];
struct edge
{
  int v;
  ll w;
}es[maxn * 2];
int tot;
vector<int> G[maxn];
int n;
ll ans;
void init()
{
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  ans = 0;
  tot = 0;
}
void dfs(int u, int fa)
{
  dpbuy[u] = -p[u];
  dpsell[u] = p[u];
  for (int eno: G[u])
  {
    edge & e = es[eno];
    if (e.v != fa)
    {
      dfs(e.v, u);
      dpbuy[u] = max(dpbuy[u], dpbuy[e.v] - e.w);
      dpsell[u] = max(dpsell[u], dpsell[e.v] - e.w);
    }
  }
  ans = max(ans, dpbuy[u] + dpsell[u]);
}
void add(int u, int v, ll w)
{
  es[tot] = {v, w};
  G[u].push_back(tot++);
  es[tot] = {u, w};
  G[v].push_back(tot++);
}
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i++)
    {
      scanf("%lld", p + i);
    }
    for (int i = 1; i < n; i++)
    {
      int u,v;
      ll w;
      scanf("%d%d%lld", &u, &v, &w);
      add(u,v,w);
    }
    dfs(1,1);
    printf("%lld\n", ans);
  }
}
