#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int dfn = 0, L[maxn], R[maxn];
int p[maxn];
int n;
int t[maxn << 1];
vector<int> G[maxn];
void dfs(int u)
{
  t[dfn] = p[u];
  L[u] = dfn++;
  for (int v: G[u])
  {
    dfs(v);
  }
  t[dfn] = p[u];
  R[u] = dfn++;
}
int sum[maxn << 3], lazy[maxn << 3];
int sz[maxn << 3];
void pushup(int r)
{
  sum[r] = sum[r << 1] + sum[r << 1 | 1];
}
void pushdown(int o)
{
  if (!lazy[o]) return;
  lazy[o] = 0;
  lazy[o << 1] ^= 1;
  sum[o << 1] = sz[o << 1] - sum[o << 1];
  lazy[o << 1 | 1] ^= 1;
  sum[o << 1 | 1] = sz[o << 1 | 1] - sum[o << 1 | 1];
}
void build(int lb = 0, int rb = dfn, int o = 1)
{
  if (lb + 1 == rb)
  {
    sz[o] = 1;
    sum[o] = t[lb];
    return;
  }
  const int mid = (lb + rb) / 2;
  build(lb, mid, o << 1);
  build(mid, rb, o << 1 | 1);
  sz[o] = sz[o << 1] + sz[o << 1 | 1];
  pushup(o);
}
void flip(int ql, int qr, int lb = 0, int rb = dfn, int o = 1)
{
  if (ql <= lb && rb <= qr)
  {
    lazy[o] ^= 1;
    sum[o] = sz[o] - sum[o];
    return;
  }
  const int mid = (lb + rb) / 2;
  pushdown(o);
  if (ql < mid) flip(ql, qr, lb, mid, o << 1);
  if (mid < qr) flip(ql, qr, mid, rb, o << 1 | 1);
  pushup(o);
}
int query(int ql, int qr, int lb = 0, int rb = dfn, int o = 1)
{
  if (ql <= lb && rb <= qr)
  {
    return sum[o];
  }
  const int mid = (lb + rb) / 2;
  pushdown(o);
  int ret = 0;
  if (ql < mid) ret = query(ql, qr, lb, mid, o << 1);
  if (mid < qr) ret += query(ql, qr, mid, rb, o << 1 | 1);
  return ret;
}
int q, v;
char cmd[10];
int main()
{
  scanf("%d", &n);
  for (int i = 2; i <= n; i++)
  {
    // static int v;
    scanf("%d", &v);
    G[v].push_back(i);
  }
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", p + i);
  }
  dfs(1);
  build();
  scanf("%d", &q);
  while(q--)
  {
    scanf("%s%d", cmd, &v);
    if (cmd[0] == 'g')
    {
      printf("%d\n", query(L[v], R[v] + 1) / 2);
    }
    else if (cmd[0] == 'p')
    {
      flip(L[v], R[v] + 1);
    }
  }
}
