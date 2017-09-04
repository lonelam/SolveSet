#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int n, q;
struct node
{
  int ch[2];
  int sz;
}pool[maxn * 64];
void pushup(int r)
{
  pool[r].sz = pool[pool[r].ch[0]].sz + pool[pool[r].ch[1]].sz + 1;
}
int tot;
void init()
{
  pool[0].ch[0] = pool[0].ch[1] = 0;
  pool[0].sz = 0;
  tot = 1;
}
int newnode()
{
  pool[tot].ch[0] = pool[tot].ch[1] = 0;
  pool[tot].sz = 1;
  return tot++;
}
void insert(int & pos, int i, int x)
{
  if (pos == 0)
  {
    pos = newnode();
  }
  if (i == -1)
  {
    return;
  }
  insert(pool[pos].ch[x >> i & 1], i - 1, x);
  pushup(pos);
}
int find(int & pos, int i, int x)
{
  if (i == -1)
  {
    return x;
  }
  if (pool[pos].ch[(x >> i & 1) ^ 1])
  {
    return find(pool[pos].ch[(x >> i & 1) ^ 1], i - 1, x ^ (1 << i));
  }
  else
  {
    return find(pool[pos].ch[(x >> i & 1)], i - 1, x);
  }
}
void merge(int & cur, int & tar, int i)
{
  if (tar == 0)
  {
    tar = cur;
    return;
  }
  if (i == -1)
  {
    return;
  }
  if (pool[cur].ch[0])
  {
    merge(pool[cur].ch[0], pool[tar].ch[0], i - 1);
  }
  if (pool[cur].ch[1])
  {
    merge(pool[cur].ch[1], pool[tar].ch[1], i - 1);
  }
  pushup(tar);
}
int ans[maxn];
struct query
{
  int u, x, id;
};
vector<int> G[maxn];
vector<query> qs[maxn];
int val[maxn];
int dfs(int u)
{
  vector<int> trees;
  int self = 0;
  insert(self, 31, val[u]);
  trees.push_back(self);
  for (int v: G[u])
  {
    trees.push_back(dfs(v));
  }
  for (int r: trees)
  {
    if (pool[r].sz > pool[self].sz)
    {
      self = r;
    }
  }
  for (int r: trees)
  {
    if (r != self)
    {
      merge(r, self, 31);
    }
  }
  for (query q: qs[u])
  {
    ans[q.id] = find(self, 31, q.x) ^ q.x;
  }
  return self;
}
int main()
{
  int n, q;
  while(~scanf("%d%d", &n, &q))
  {
    init();
    for (int i = 1; i <= n; i++)
    {
      G[i].clear();
      qs[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
       scanf("%d", val + i);
    }
    for (int i = 2; i <= n; i++)
    {
      int f;
      scanf("%d", &f);
      G[f].push_back(i);
    }
    for (int i = 0; i < q; i++)
    {
      int u, x;
      scanf("%d%d", &u, &x);
      qs[u].push_back({u, x, i});
    }
    int troot = dfs(1);
    for (int i = 0; i < q; i++)
    {
      printf("%d\n", ans[i]);
    }
  }
}
