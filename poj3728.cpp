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
const int maxn = 5e4 + 5;
int s[maxn], t[maxn], d[maxn], p[maxn], ans[maxn];
int h[maxn], q[maxn], g[maxn], f[maxn], mx[maxn], mi[maxn], up[maxn], dw[maxn];
bool vis[maxn];
int i, j, k, n, m, e;
inline void add(int u, int v, int c, int h[])
{
  s[e] = u, t[e] = v, d[e] = c, p[e] = h[u], h[u] = e++;
  s[e] = v, t[e] = u, d[e] = -c, p[e] = h[v], h[v] = e++;
}
int find(int x)
{
  if (f[x] == x) return x;
  int y = f[x];
  up[x] = max({mx[y] - mi[x], up[x], up[y]});
  dw[x] = max({mx[x] - mi[y], dw[x], dw[y]});
  mx[x] = max(mx[x], mx[y]);
  mi[x] = min(mi[x], mi[y]);
  return f[x];
}
void tarjan(int u)
{
  int i, v, x, y;
  vis[f[u] = u] = 1;
  for (i = q[u]; i; i = p[i])
  {
    if (vis[v=t[i]])
  }
}
