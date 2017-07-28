#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const int maxk = 21;
int dfn[maxn], dfs_clock;
inline bool cmp(const int & i, const int & j)
{
  return dfn[i] < dfn[j];
}
int fa[maxn][maxk], depth[maxn];

struct edge
{
  int v;
  ll c;
} es[maxn * 2];
vector<int> G[maxn], H[maxn];

void addH(int u, int v)
{
  H[u].push_back(v);
}
int lca(int x, int y)
{
  if (depth[x] < depth[y]) swap(x, y);
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (depth[fa[x][k]] >= depth[y])
    {
      x = fa[x][k];
    }
  }
  if (x == y) return x;
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (fa[x][k] != fa[y][k])
    {
      x = fa[x][k];
      y = fa[y][k];
    }
  }
  return fa[x][0];
}
//vertices need to be arrange
int key_node[maxn], kcnt;
void build()
{
  static int stk[maxn];
  sort(key_node, key_node + kcnt, cmp);
  int p = 0;
  for (int i = 1; i < kcnt; i++)
  {
    if (lca(key_node[i], key_node[p]) != key_node[p])
    {
      key_node[++p] = key_node[i];
    }
  }
  kcnt = p + 1;
  int sz = 0;
  stk[sz++] = 0;
  for (int i = 0; i < kcnt; i++)
  {
    int f = lca(stk[sz - 1], key_node[i]);
    if (f == stk[sz - 1])
    {
      stk[sz++] = key_node[i];
    }
    else
    {
      while(sz - 2 >= 0 && depth[stk[sz - 2]] >= depth[f])
      {
        addH(stk[sz - 2], stk[sz - 1]);
        sz--;
      }
      if (stk[sz - 1] != f)
      {
        addH(f, stk[--sz]);
        stk[sz++] = f;
      }
      stk[sz++] = key_node[i];
    }
  }
  for (int i = 1; i < sz; i++)
  {
    addH(stk[i-1], stk[i]);
  }
}
