#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
set<int> st;
int deep[maxn], fa[maxn][20], head[maxn], nex[maxn * 2], d[maxn];
int cnt, t, pos[maxn], n, q, vis[maxn];
ll ans, dis[maxn];
struct use
{
  int st, en;
  ll v;
} e[maxn * 2];
void add(int x, int y, ll v)
{
  nex[++cnt] = head[x];
  head[x] = cnt;
  e[cnt] = {x, y, v};
}
void dfs(int x)
{
  d[x] = ++t;
  pos[t] = x;
  for (int i = 1; (1 << i) <= deep[x]; i++)
  {
    fa[x][i] = fa[fa[x][i-1]][i-1];
  }
  for (int i = head[x]; i; i = nex[i])
  {
    if (e[i].en != fa[x][0])
    {
        fa[e[i].en][0] = x;
        deep[e[i].en] = deep[x] + 1;
        dis[e[i].en] = dis[x] + e[i].v;
        dfs(e[i].en);
    }
  }
}
int lca(int x, int y)
{
  if (deep[x] < deep[y]) swap(x, y);
  int c = deep[x] - deep[y];
  for (int i = 0; i <= 18; i++)
  {
    if (c & (1 << i)) x = fa[x][i];
  }
  for (int i = 18; ~i; i--)
  {
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  }
  if (x != y)
  {
    return fa[x][0];
  }
  else return x;
}
ll cal(int x, int y)
{
  int f = lca(x, y);
  return dis[x] + dis[y] - dis[f] * 2;
}
int main()
{
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++)
  {
    static int x, y;
    static ll v;
    scanf("%d%d%lld", &x, &y, &v);
    add(x, y, v);
    add(y, x, v);
  }
  dfs(1);
  st.insert(-1);
  st.insert(inf);
  for (int i = 1; i <= q; i++)
  {
    static int x;
    scanf("%d", &x);
    int p, l, r;
    ll temp = 0;
    if (!vis[x])
    {
      st.insert(d[x]);
      p = 1;
    }
    else
    {
      st.erase(d[x]);
      p = -1;
    }
    vis[x] = !vis[x];
    l = *--st.lower_bound(d[x]);
    r = *st.upper_bound(d[x]);
    if (l != -1)
    {
      ans += cal(pos[l], x) * p;
    }
    if (r != inf)
    {
      ans += cal(pos[r], x) * p;
    }
    if (l != -1  && r != inf)
    {
      ans -= cal(pos[l], pos[r]) * p;
    }
    if (st.size() != 2)
    {
      temp = cal(pos[*++st.begin()], pos[*++st.rbegin()]);
    }
    printf("%lld\n", ans + temp);
  }
}
