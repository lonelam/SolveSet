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
const int maxn = 300000 + 100;
const int maxk = 21;
int dfn[maxn], dfs_clock;
int fa[maxn][maxk], depth[maxn], size[maxn];
inline bool cmp(const int & lhs, const int & rhs)
{
  return dfn[lhs] < dfn[rhs];
}
vector<int> G[maxn], H[maxn];
int n;
void init()
{
  dfn[0] = -1;
  depth[0] = -1;
  dfs_clock = 0;
  for (int i = 0; i <= n; i++)
  {
    G[i].clear();
  }
}
void addG(int u, int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}
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

int key_nodes[maxn], kcnt;
int adj[maxn];
int ans[maxn];
int build()
{
  static int stk[maxn];
  sort(key_nodes, key_nodes + kcnt, cmp);
  int sz = 0;
  stk[sz++] = 0;
  for (int i = 0; i < kcnt; i++)
  {
    int f = lca(stk[sz - 1], key_nodes[i]);
    if (f == stk[sz - 1])
    {
      stk[sz++] = key_nodes[i];
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
      stk[sz++] = key_nodes[i];
    }
  }
  for (int i = 2; i < sz; i++)
  {
    addH(stk[i - 1], stk[i]);
  }
  return stk[1];
}
bool iskey(int x)
{
  return binary_search(key_nodes, key_nodes + kcnt, x, cmp);
}
void dfs(int cur)
{
  size[cur] = 1;
  dfn[cur] = dfs_clock++;
  for (int k = 1; k < maxk; k++)
  {
    fa[cur][k] = fa[fa[cur][k - 1]][k - 1];
  }
  for (int i = 0; i < G[cur].size(); i++)
  {
    int v = G[cur][i];
    if (v != fa[cur][0])
    {
      fa[v][0] = cur;
      depth[v] = depth[cur] + 1;
      dfs(v);
      size[cur] += size[v];
    }
  }
}
int q;
int dis(int x, int y)
{
  if (depth[x] > depth[y])
  {
    swap(x, y);
  }
  int f = lca(x, y);
  if (f == x)
  {
    return depth[y] - depth[x];
  }
  return depth[x] + depth[y] - 2 * depth[f];
}

void get_adj1(int cur)
{
  if (iskey(cur))
  {
    adj[cur] = cur;
  }
  else
  {
    adj[cur] = key_nodes[0];
  }
  for (int i = 0; i < H[cur].size(); i++)
  {
    int v = H[cur][i];
    get_adj1(v);
    const int d1 = dis(cur, adj[v]);
    const int d2 = dis(cur, adj[cur]);
    if (d1 < d2 || d1 == d2 && adj[v] < adj[cur])
    {
      adj[cur] = adj[v];
    }
  }
}
int cnt[maxn];
void get_adj2(int cur, int p)
{
  cnt[cur] = 0;
  const int d1 = dis(cur, adj[cur]);
  const int d2 = dis(cur, adj[p]);
  if (d2 < d1 || d2 == d1 && adj[p] < adj[cur])
  {
    adj[cur] = adj[p];
  }
  for (int i = 0; i < H[cur].size(); i++)
  {
    get_adj2(H[cur][i], cur);
  }
}
int trace(int tail, int step)
{
  int k = 0;
  while(step)
  {
    if (step & 1)
    {
      tail = fa[tail][k];
    }
    k++;
    step>>=1;
  }
  return tail;
}
void get_ans(int cur, int parent)
{
  if (cur == parent)
  {
    ans[adj[cur]] += n - size[cur];
  }
  else if (adj[cur] == cur)
  {
    if (adj[parent] == cur)
    {
      int asize = size[trace(cur, depth[cur] - depth[parent] - 1)];
      ans[cur] += asize - size[cur];
      cnt[parent] += asize - size[cur];
    }
    else
    {
      int d1 = dis(adj[parent], cur);
      int step = -1;
      if (cur < adj[parent])
      {
        step = d1 / 2;
      }
      else
      {
        step = (d1-1) / 2;
      }
      step = min( depth[cur] - depth[parent] - 1, step);
      int midsize = size[trace(cur, step)];
      int asize = size[trace(cur, depth[cur] - depth[parent] - 1)];
      ans[cur] += midsize - size[cur];
      cnt[parent] += midsize - size[cur];
      ans[adj[parent]] += asize - midsize;
      cnt[parent] += asize - midsize;
    }
  }
  else if (adj[cur] != adj[parent])
  {
    int d1 = dis(adj[parent], adj[cur]);
    int d2 = dis(adj[cur], cur);
    int step = -1;
    if (adj[cur] < adj[parent])
    {
      step = (d1 ) / 2;
    }
    else
    {
      step = (d1-1) / 2;
    }
    step -= d2;
    step = max(0, step);
    step = min(depth[cur] - depth[parent] - 1, step);
    int midsize = size[trace(cur, step)];
    int asize = size[trace(cur, depth[cur] - depth[parent] - 1)];
    ans[adj[cur]] += midsize - size[cur];
    cnt[parent] += midsize - size[cur];
    ans[adj[parent]] += asize - midsize;
    cnt[parent] += asize - midsize;
  }
  else
  {
    int asize = size[trace(cur, depth[cur] - depth[parent] - 1)];
    ans[adj[cur]] += asize - size[cur];
    cnt[parent] += asize - size[cur];
  }
  for (int i = 0; i < H[cur].size(); i++)
  {
    int v = H[cur][i];
    get_ans(v, cur);
    cnt[cur] += cnt[v];
  }
  H[cur].clear();
  ans[adj[cur]] += size[cur] - cnt[cur];
  cnt[cur] = size[cur];
}

int main()
{
  while(scanf("%d", &n) != EOF)
  {
    init();
    for (int i = 1; i < n; i++)
    {
      static int u, v;
      scanf("%d%d", &u, &v);
      addG(u, v);
    }
    fa[1][0] = 0;
    depth[1] = 0;
    dfs(1);
    scanf("%d", &q);
    for (int i =0; i < q; i++)
    {
      static int mem[maxn];
      scanf("%d", &kcnt);
      for (int j = 0; j < kcnt; j++)
      {
        scanf("%d", key_nodes + j);
        ans[key_nodes[j]] = 0;
        mem[j] = key_nodes[j];
      }
      int root = build();
      get_adj1(root);
      get_adj2(root, root);
      get_ans(root, root);
      for (int j = 0; j < kcnt; j++)
      {
        printf("%d ", ans[mem[j]]);
      }
      printf("\n");
    }
  }
}
/*
10
2 1
3 2
4 3
5 4
6 1
7 3
8 3
9 4
10 1

5
4
8 7 10 3
*/
