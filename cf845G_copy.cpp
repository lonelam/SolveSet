
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
vector<pair<int, ll> > e[maxn];
vector<ll> base;
void add(ll x)
{
  for (int i = 0; i < base.size(); i++)
  {
    x = min(x, x ^ base[i]);
  }
  if (x) base.push_back(x);
}
int vis[maxn];
ll t[maxn];
void dfs(int u, ll now)
{
  vis[u] = 1;
  t[u] = now;
  for (int i = 0; i < e[u].size(); i++)
  {
    int v = e[u][i].first;
    if (vis[v])
    {
      add(now ^ e[u][i].second ^ t[v]);
    }
    else
    {
      dfs(v, now ^ e[u][i].second);
    }
  }
}
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
  {
    int x, y;
    ll w;
    scanf("%d%d%lld", &x, &y, &w);
    e[x].push_back({y, w});
    e[y].push_back({x, w});
  }
  dfs(1, 0);
  for (int i = 0; i < base.size(); i++)
  {
    t[n] = min(t[n], t[n] ^ base[i]);
  }
  printf("%lld\n", t[n]);
  return 0;
}
