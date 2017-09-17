#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 5;
const ll moder = 19260817;
const int msize = 64;
ll M[maxn][msize];
ll seed;
ll power19[msize];
ll power26[msize];
int n, q;
struct mat
{
  ll a[msize];
  ll b[msize];
  mat(){memset(a,0,sizeof(a));memset(b,0,sizeof(b));}
  void init()
  {
    memset(a,0,sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 0; i < msize; i++)
    {
      a[i] |= 1ULL << i;
      b[i] |= 1ULL << i;
    }
  }
  void getb()
  {
    memset(b, 0, sizeof(b));
    for (int i = 0; i < msize; i++)
    {
      for (int j = 0; j < msize; j++)
      {
        if ((a[i] >> j) & 1ULL)
        {
          b[j] |= 1ULL << i;
        }
      }
    }
  }
  void geta()
  {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < msize; i++)
    {
      for (int j = 0; j < msize; j++)
      {
        if ((b[j] >> i) & 1ULL)
        {
          a[i] |= 1ULL << j;
        }
      }
    }
  }
  void fill()
  {
    for (int i = 0; i < msize; i++)
      a[i] = b[i] = ULLONG_MAX;
  }
  mat operator*(const mat & rhs) const
  {
    mat ret;
    for (int i = 0; i < 64; i++)
    {
      for (int j = 0; j < 64; j++)
      {
        //p (node[2]*node[3]*node[4]).get_output()
        if (__builtin_popcountll(a[i] & rhs.b[j]) & 1)
        {
          ret.a[i] |= 1ULL << j;
          ret.b[j] |= 1ULL << i;
        }
      }
    }
    return ret;
  }
  mat operator~() const
  {
    mat ret;
    return ret;
    ret.fill();
    for (int i = 0; i < msize; i++)
    {
      for (int j = 0; j < msize; j++)
      {
        if (i != j)
        {
          ret.b[j] &= (~a[i]);
        }
      }
    }
    ret.geta();
    return ret;
  }
  ll get_output() const
  {
    ll ret = 0;
    for (int i = 0; i < msize; i++)
    {
      for (int j = 0; j < msize; j++)
      {
        if ((a[i] >> j) & 1)
        {
          ret = (ret + power19[i] * power26[j] % moder) % moder;
        }
      }
    }
    return ret;
  }
};
mat dis[maxn],rdis[maxn],node[maxn];
void get_M()
{
  for (int i = 0; i < n ;i++)
  {
    for (int p = 0; p < 64; p++)
    {
      seed ^= seed * seed + 15;
      M[i][p] = seed;
      node[i].a[p] = seed;
    }
    node[i].getb();
  }
}
vector<int> G[maxn];
const int maxk = 13;
int fa[maxn][maxk];
int d[maxn];
void dfs(int u, int par)
{
  d[u] = d[par] + 1;
  dis[u] = dis[par] * node[u];
  fa[u][0] = par;
  for (int k = 1; k < maxk; k++)
  {
    fa[u][k] = fa[fa[u][k-1]][k-1];
  }
  for (int v: G[u])
  {
    if (v != par)
    {
      dfs(v, u);
    }
  }
}
int lca(int u, int v)
{
  if (d[u] > d[v])
  {
    swap(u, v);
  }
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (d[fa[v][k]] >= d[u])
    {
      v = fa[v][k];
    }
  }
  if (u == v) return u;
  for (int k = maxk - 1; k>= 0; k--)
  {
    if (fa[u][k] != fa[v][k])
    {
      u = fa[u][k];
      v = fa[v][k];
    }
  }
  return fa[u][0];
}
int main()
{
  power19[0]=19;
  power26[0]=26;
  for (int i = 1; i < msize; i++)
  {
    power19[i] = power19[i-1] * 19ULL % moder;
    power26[i] = power26[i-1] * 26ULL % moder;
  }
  while(~scanf("%d%d", &n, &q))
  {
    for (int i = 0; i < n; i++)
    {
      G[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
      static int u,v;
      scanf("%d%d", &u, &v);
      u--, v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    scanf("%llu", &seed);
    get_M();
    dis[0].init();
    d[0] = 0;
    dfs(0, 0);
    for (int i = 0; i < n; i++)
    {
      rdis[i] = ~dis[i];
    }
    for (int i = 0; i < q; i++)
    {
      static int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      int l = lca(u, v);
      mat ans = dis[u] * dis[v] * rdis[l] * rdis[l] * node[l];
      printf("%llu\n", ans.get_output());
    }
  }
}
