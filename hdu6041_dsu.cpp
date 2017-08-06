#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
const int maxk = 100000 + 10;
int n, m;
int tot, lnk[maxn], dsu[maxn];
int fa[maxn], dep[maxn], eval[maxn], cnt, sum, ans;
struct edge
{
  int v, w;
} es[maxn << 2];
vector<int> G[maxn];
int etot = 0;
void addedge(int u, int v, int w)
{
  es[etot] = {v, w};
  G[u].push_back(etot++);
  es[etot] = {u, w};
  G[v].push_back(etot++);
}
struct nontreeedge
{
  int u, v, w;
}Q[maxn >> 1 | 1];
int f[3][maxk], cur, pre = 1;
int dsu_find(int u)
{
  return dsu[u] < 0 ? u : dsu[u] = dsu_find(dsu[u]);
}
bool dsu_merge(int u, int v)
{
  u = dsu_find(u);
  v = dsu_find(v);
  if (u == v)
  {
    return 0;
  }
  if (dsu[u] < dsu[v])
  {
    dsu[v] = u;
  }
  else if (dsu[v] < dsu[u])
  {
    dsu[u] = v;
  }
  else
  {
    --dsu[u];
    dsu[v] = u;
  }
  return 1;
}
void dfs(int u)
{
  for (int eno: G[u])
  {
    edge & e = es[eno];
    if (e.v == fa[u])
    {
      continue;
    }
    fa[e.v] = u;
    dep[e.v] = dep[u] + 1;
    eval[e.v] = e.w;
    dfs(e.v);
  }
}
int idx[maxn];
struct PriorityQueue
{
  int size, seq[maxn], pos[maxn];
  void push(int val, int ind)
  {
    ++size;
    int p = size >> 1, c = size;
    while(p && seq[p] < val)
    {
      seq[c] = seq[p];
      pos[c] = pos[p];
      c = p;
      p >>= 1;
    }
    seq[c] = val;
    pos[c] = idx;
  }
}
