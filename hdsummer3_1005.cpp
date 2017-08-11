#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
struct edge
{
  int v, w;
} es[maxn * 2];
int n, k;
int tot;
// ll dis[maxn];
vector<int> G[maxn];
ll tmp[maxn];
int sz[maxn];
void dfs(int cur, int parent)
{
  sz[cur] = 1;
  for (int & eno: G[cur])
  {
    const edge & e = es[eno];
    if (e.v != parent)
    {
      // dis[e.v] = dis[cur] + (ll)e.w;
      // tmp[tcnt++] = dis[cur];
      dfs(e.v, cur);
      sz[cur] += sz[e.v];
      if (sz[e.v]>=2)tmp[sz[e.v]-2] += (ll) e.w;
      // for (int i = 0; i < sz[e.v] - 1; i++)
      // {
      //   tmp[i] += (ll)e.w;
      // }
    }
  }
}
void addedge(int u, int v, int w)
{
  G[u].push_back(tot);
  es[tot++] = {v, w};
  G[v].push_back(tot);
  es[tot++] = {u, w};
}
int main()
{
  while(scanf("%d%d",&n, &k) != EOF)
  {
    tot = 0;
    ll ans = 0;
    if (n > 1000) memset(tmp,0,sizeof(tmp));
    else
    {
      for (int i = 0; i <= n; i++)
      {
        tmp[i] = 0;
      }
    }
    for (int i = 1; i <= n; i++)
    {
      G[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
      static int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      addedge(a,b,c);
      ans += (ll)c;
    }
    // dis[1] = 0;
    dfs(1, 1);
    for (int i = n - 1; i >= 0; i--)
    {
      tmp[i] += tmp[i+1];
    }
    // sort(tmp, tmp + n, greater<int>());
    for (int i = 1; i < k; i++)
    {
      ans += tmp[i-1];
    }
    printf("%lld\n", ans);
  }

}
