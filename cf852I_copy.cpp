#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
int n, m, a[maxn], fst[maxn], vb[maxn], nxt[maxn], as[maxn], tot = 0, fa[maxn];
void ad_de(int a, int b)
{
  ++tot;
  nxt[tot] = fst[a];
  fst[a] = tot;
  vb[tot] = b;
}
void adde(int a, int b)
{
  ad_de(a,b);
  ad_de(b,a);
}
int cc = 0, st[maxn], ed[maxn], dfx[maxn];
void dfs(int x)
{
  st[x] = ++cc;
  dfx[cc] = x;
  for (int e = fst[x]; e; e = nxt[e])
  {
    int b = vb[e];
    if (b == fa[x]) continue;
    fa[b] = x;
    dfs(b);
  }
  ed[x] = ++cc;
  dfx[cc] = x;
}
typedef pair<int,int> pii;
int cc_ = 0, app[maxn], dep[maxn], lo2[maxn];
pii pp[maxn], minn[maxn][21];
void dfs_(int x)
{
  ++cc_;
  app[x] = cc_;
  pp[cc_] = pii(dep[x], x);
  for (int e = fst[x]; e; e = nxt[e])
  {
    int b = vb[e];
    if (b == fa[x])
    {
      continue;
    }
    dep[b] = dep[x] + 1;
    dfs_(b);
    pp[++cc_] = pii(dep[x], x);
  }
}
void build()
{
  for (int i = 1; i <= cc_; i++) minn[i][0] = pp[i];
  {
    for (int i = 1; i <= cc_; i++)
    {
      int g = 0;
      while((1 << g) <= i) ++g;
      lo2[i] = g-1;
    }
  }
  for (int p = 1; p < 21; p++)
  {
    for (int i = 1; i <= cc_; i++)
    {
      if (i + (1 << p) - 1 > cc_) break;
      minn[i][p] = min(minn[i][p-1], minn[i + (1 << (p-1))][p-1]);
    }
  }
}
int lca(int a, int b)
{
  a = app[a];
  b = app[b];
  if (a > b) swap(a,b);
  int l2 = lo2[b - a + 1];
  return min(minn[a][l2], minn[b-(1 << l2) + 1][l2]).second;
}
int bs, qn = 0;
struct query
{
  int l, r, m, id;
  bool operator<(const query & rhs) const
  {
    if (l / bs != rhs.l / bs) return l / bs < rhs.l / bs;
    else if ((l / bs) & 1) return r < rhs.r;
    return r > rhs.r;
  }
}qs[maxn];
#define Addq(l_,r_,m_,id_) ++qn,qs[qn].l=l_, qs[qn].r=r_,qs[qn].m=m_, qs[qn].id=id_;
int typ[maxn], cov[maxn];
ll cnt[2][maxn];
ll ans = 0, anss[maxn];
void edt(int p)
{
  cov[p] ^= 1;
  int k = (cov[p]) ?1:(-1),t=typ[p];
  cnt[t][a[p]]+=k;
  ans+=cnt[!t][a[p]]*k;
}
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", typ + i);
  }
  for (int i = 1; i <= n; i++)
}
