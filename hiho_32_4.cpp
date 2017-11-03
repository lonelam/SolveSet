#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
vector<int> G[maxn];
// set<int> neighbor;
int tag[maxn];
const ll moder = 1e9+7;
int deg[maxn];
int n, m;
int u[maxn * 2],v[maxn * 2];
int main()
{
  while(~scanf("%d%d", &n, &m))
  {
    for (int i = 1; i <= n; i++)
    {
      G[i].clear();
      deg[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d", u + i, v + i);
      deg[u[i]]++;
      deg[v[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
      if (deg[u[i]] >= 2 && deg[v[i]] >= 2)
      {
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
      }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
      if (deg[i] >= 3)
      {
        //neighbor.clear();
        for (int v: G[i])
        {
          tag[v] = i;
        }
        for (int v: G[i])
        {
          if (deg[v] > deg[i] || deg[v] == deg[i] && v > i) continue;
          int cnt = 0;
          for (int s: G[v])
          {
            if (tag[s] == i)
            {
              cnt++;
            }
          }
          if (cnt >= 2)
          {
            if (deg[i] > 4) ans = (ans + (cnt * (ll)(cnt-1LL) / 2LL) % moder * ((deg[i] - 3LL) * (deg[i] - 4LL) / 2LL % moder) ) % moder;
            if (deg[v] > 4) ans = (ans + (cnt * (ll) (cnt - 1LL) / 2LL) % moder * ((deg[v] - 3LL) * (deg[v] - 4LL) / 2LL % moder) ) % moder;
          }
        }
      }
    }
    printf("%lld\n", ans);
  }
}
