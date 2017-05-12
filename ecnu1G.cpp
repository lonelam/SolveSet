#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
struct edge
{
  int u, v, t, f;
  ld w;
  bool operator<(const edge & rhs) const
  {
    return w > rhs.w;
  }
} es[maxn];
int tot;
vector<int> G[maxn];
void addedge(int u, int v, int t, int f)
{
//  es[tot] = {u, v, t, f, (ld)t};
  es[tot].u = u;
  es[tot].v = v;
  es[tot].t = t;
  es[tot].f = f;
  es[tot].w = t;
  G[u].push_back(tot);
  G[v].push_back(tot);
  tot++;
}
int n, m;
ll budget;
int u, v, t, f;
bool vis[maxn];
void init()
{
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  tot = 0;
}

int main()
{
  while(scanf("%d%d%lld", &n, &m, &budget) != EOF)
  {
    init();
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d%d%d", &u, &v, &t, &f);
      addedge(u, v, t, f);
    }
    ld L = 1, R = budget / (n - 1);
    while(abs(R - L) > 1e-7)
    {
      ld sum = 0;
      memset(vis, 0, sizeof(vis));
      const ld mid = L + (R - L) / (ld)2;
      priority_queue<edge> Q;
      for (int i = 0; i < tot; i++)
      {
        if (es[i].f)
          es[i].w = es[i].t * mid;
      }
      vis[1] = true;
      for (int i = 0; i < G[1].size(); i++)
      {
        Q.push(es[G[1][i]]);
      }
      while(!Q.empty())
      {
        const edge e = Q.top();
        int eu = e.u;
        int ev = e.v;
        Q.pop();
        if (vis[eu] && vis[ev])
        {
          continue;
        }
        ld ew = e.w;
        sum += ew;
        if (!vis[eu])
        {
          vis[eu] = true;
          for (int i = 0; i < G[eu].size(); i++)
          {
            const edge & ee = es[G[eu][i]];
            if (!vis[ee.u] || !vis[ee.v])
            {
              Q.push(ee);
            }
          }
        }
        else if (!vis[ev])
        {
          vis[ev] = true;
          for (int i = 0; i < G[e.v].size(); i++)
          {
            const edge & ee = es[G[e.v][i]];
            if (!vis[ee.u] || !vis[ee.v])
            {
              Q.push(ee);
            }
          }
        }
      }
      if (sum <= (ld)budget)
      {
        L = mid;
      }
      else
      {
        R = mid;
      }
    }
    printf("%llf\n", L);
  }
}
