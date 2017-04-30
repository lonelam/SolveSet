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
const int maxn = 10000 + 5;
const int DEG = 20;

struct edge
{
  int to, nex;
} e[maxn << 1];
int head[maxn], tot;

void addedge(int u, int v)
{
  e[tot].to = v;
  e[tot].nex = head[u];
  head[u] = tot++;
}
void init()
{
  tot = 0;
  memset(head, -1, sizeof(head));
}

int fa[maxn][DEG];
int deg[maxn];

void bfs(int root)
{
  queue<int> Q;
  deg[root] = 0;
  fa[root][0] = root;
  Q.push(root);
  while(!Q.empty())
  {
    int u = Q.front(); Q.pop();
    for (int i = 1; i < DEG; i++)
    {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i != -1; i = e[i].nex)
    {
      int v = e[i].to;
      if (v == fa[u][0])
      {
        continue;
      }
      deg[v] = deg[u] + 1;
      fa[v][0] = u;
      Q.push(v)
    }
  }
}
int lca(int u, int v)
{
  if (deg[u] > deg[v])
  {
    swap(u, v);
  }
  int hu = deg[u], hv = deg[v];
  int tu = u, tv = v;
  for (int det = hv - hu, i = 0; det; det >>= 1, i++)
  {
    if (det & 1) tv = fa[tv][i];
  }
  if (tu == tv) return tu;
  for (int i = DEG - 1; i >= 0; i--)
  {
    if (fa[tu][i] == fa[tv][i]) continue;
    tu = fa[tu][i];
    tv = fa[tv][i];
  }
  return fa[tu][0];
}
