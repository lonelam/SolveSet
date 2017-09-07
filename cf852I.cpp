#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int maxk = 21;
int dfs_clock, f[maxn], n, q, a[maxn], b[maxn];
int dfL[maxn], dfR[maxn];
int u[maxn], v[maxn];
int sex[maxn];
int cnt[maxn][2];
ll ans[maxn];
int belong[maxn],bsize, bcnt;
vector<int> disc;
vector<int> G[maxn];
int color[maxn * 2];
int gen[maxn * 2];
int num[maxn * 2];
int pa[maxn][maxk];
int d[maxn];
void dfs(int u, int fa)
{
  dfL[u] = ++dfs_clock;
  d[u] = d[fa] + 1;
  num[dfs_clock] = u;
  color[dfs_clock] = f[u];
  gen[dfs_clock] = sex[u];
  pa[u][0] = fa;
  for (int i = 1; i < maxk; i++)
  {
    pa[u][i] = pa[pa[u][i-1]][i-1];
  }
  for (int v: G[u])
  {
    if (v != fa)
    {
      dfs(v, u);
    }
  }
  dfR[u] = ++dfs_clock;
  color[dfs_clock] = f[u];
  gen[dfs_clock] = sex[u];
  num[dfs_clock] = u;
}
int vis[maxn];
int lca(int u, int v)
{
  if (d[u] > d[v])
  {
    swap(u,v);
  }
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (d[pa[v][k]] >= d[u])
    {
      v = pa[v][k];
    }
  }
  if (u == v) return u;
  for (int k = maxk - 1; k>=0; k--)
  {
    if (pa[u][k] != pa[v][k])
    {
      u=pa[u][k];
      v = pa[v][k];
    }
  }
  return pa[u][0];
}
void init()
{
  for (int i = 1; i <= n; i++)
  {
    disc.push_back(f[i]);
  }
  sort(disc.begin(), disc.end());
  disc.erase(unique(disc.begin(), disc.end()), disc.end());
  for (int i = 1; i <= n; i++)
  {
    f[i] = lower_bound(disc.begin(), disc.end(), f[i]) - disc.begin();
  }
  int m = disc.size();
  bsize = sqrt(m);
  bcnt = (bsize + m - 1) / bsize;
  for (int i = 0; i < m; i++)
  {
    belong[i] = i / bsize;
  }
  dfs(1, 1);
}
struct node
{
  int lb, rb;
  int trace;
  int P;
  bool operator<(const node & rhs) const
  {
    if (belong[lb] == belong[rhs.lb])
    {
      if (belong[lb]&1)
      return rb < rhs.rb;
      return rb > rhs.rb;
    }
    return belong[lb] < belong[rhs.lb];
  }
} ns[maxn * 10];
int tot;
void Mo()
{
  for (int i = 0; i < q; i++)
  {
    if (d[a[i]] > d[b[i]]) swap(a[i], b[i]);
    int c = lca(a[i], b[i]);
    if (c == a[i])
    {
      ns[tot++] = {dfL[a[i]], dfL[b[i]], i, 0};
    }
    else
    {
      if (dfL[a[i]] > dfL[b[i]]) swap(a[i], b[i]);
      // ns[tot++] = {dfL[c], dfL[b[i]], i, 1};
      ns[tot++] = {dfR[a[i]], dfL[b[i]], i, c};
    }
  }
  sort(ns, ns + tot);
  int L = 1, R = 0;
  ll pcnt = 0;
  for (int i = 0; i < tot; i++)
  {
    while(R < ns[i].rb)
    {
      R++;
      vis[num[R]]++;
      if (vis[num[R]] == 1)
      {
        pcnt +=  (ll)cnt[color[R]][gen[R] ^ 1];
        cnt[color[R]][gen[R]] ++;
      }
      else
      {
        pcnt -= (ll)cnt[color[R]][gen[R] ^ 1];
        cnt[color[R]][gen[R]] --;
      }
    }
    while(L > ns[i].lb)
    {
      L--;
      vis[num[L]]++;
      if (vis[num[L]] == 1)
      {
        pcnt += (ll) cnt[color[L]][gen[L] ^ 1];
        cnt[color[L]][gen[L]] ++;
      }
      else
      {
        pcnt -= (ll) cnt[color[L]][gen[L] ^ 1];
        cnt[color[L]][gen[L]] --;
      }
    }
    while(R > ns[i].rb)
    {
      vis[num[R]]--;
      if (vis[num[R]] == 1)
      {
        pcnt += (ll)cnt[color[R]][gen[R] ^ 1];
        cnt[color[R]][gen[R]] ++;
      }
      else
      {
        pcnt -= (ll)cnt[color[R]][gen[R] ^ 1];
        cnt[color[R]][gen[R]] --;
      }
      R--;
    }
    while(L < ns[i].lb)
    {
      vis[num[L]]--;
      if (vis[num[L]] == 1)
      {
        pcnt += (ll) cnt[color[L]][gen[L] ^ 1];
        cnt[color[L]][gen[L]] ++;//= type[L];
      }
      else
      {
        pcnt -= (ll) cnt[color[L]][gen[L] ^ 1];
        cnt[color[L]][gen[L]] --;
      }
      L++;
    }
    if (ns[i].P)
    {
      ans[ns[i].trace] += (ll)pcnt + (ll)cnt[f[ns[i].P]][sex[ns[i].P] ^ 1];
    }
    else
    ans[ns[i].trace] += (ll)pcnt;
  }
  for (int i = 0; i < q; i++)
  {
    printf("%lld\n", ans[i]);
  }
}
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", sex + i);
  }
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", f + i);
  }
  int u,v;
  for (int i = 1; i < n; i++)
  {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  init();
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    scanf("%d%d", a + i, b + i);
    // a[i--]
  }
  Mo();
}
