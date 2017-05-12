
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
    return w < rhs.w;
  }
} es[maxn];
int tot;
void addedge(int u, int v, int t, int f)
{
//  es[tot] = {u, v, t, f, (ld)t};
  es[tot].u = u;
  es[tot].v = v;
  es[tot].t = t;
  es[tot].f = f;
  es[tot].w = t;
  tot++;
}
int n, m;
ll budget;
int u, v, t, f;
int fa[maxn];
int rnk[maxn];
int fnd(int x)
{
  if (fa[x] == x)
  {
    return x;
  }
  return fa[x] = fnd(fa[x]);
}
void join(int a, int b)
{
  a = fnd(a);
  b = fnd(b);
  if (rnk[a] == rnk[b])
  {
    fa[b] = a;
    rnk[a]++;
    return;
  }
  if (rnk[a] < rnk[b])
  {
    swap(a,b);
  }
  fa[b] = a;
}
void dsu()
{
  for (int i = 1; i <= n; i++)
  {
    fa[i] = i;
    rnk[i] = 1;
  }
}
void init()
{
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
    ld L = 1, R = 1e9 + 7;
    while(abs(R - L) > 1e-7)
    {
      ld sum = 0;
      dsu();
      const ld mid = L + (R - L) / (ld)2;
      for (int i = 0; i < tot; i++)
      {
        if (es[i].f)
          es[i].w = es[i].t * mid;
      }
      sort(es, es + tot);
      for (int i = 0; i < tot; i++)
      {
        int eu = es[i].u, ev = es[i].v;
        if (fnd(eu) != fnd(ev))
        {
          sum += es[i].w;
          join(eu, ev);
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
