
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 500000 + 100;
const int maxk = 21;
struct edge
{
  int to, nex, val;
};

struct graph
{
  edge e[maxn];
  int head[maxn], tot;
  bool vis[maxn];
  void addedge(int from, int to, int val = 1)
  {
    if (from == to)
    {
      return;
    }
    e[++tot] = {to, head[from], val};
    head[from] = tot;
  }
};
graph g, h;
int n, par[maxn][maxk];
int dfn[maxn], dfsc, dep[maxn];
ll mc[maxn];
void dfs(int u)
{
  dfn[u] = ++dfsc;
  for (int t = g.head[u]; t; t = g.e[t].nex)
  {
    int v = g.e[t].to;
    if (v != par[u][0])
    {
      // 切断某个结点和1的联系，要么切断自己，要么切断自己的祖先
      mc[v] = min(mc[u], (ll)g.e[t].val);
      dep[v] = dep[u] + 1;
      par[v][0] = u;
      dfs(v);
    }
  }
}
int lca(int x, int y)
{
  if (dep[x] < dep[y])
  {
    swap(x, y);
  }
  for (int j = maxk - 1; j >= 0; j--)
  {
    if (dep[par[x][j]] >= dep[y])
    {
      x = par[x][j];
    }
  }
  if (x == y)
  {
    return x;
  }
  for (int j = maxk - 1; j >= 0; j--)
  {
    if (par[x][j] != par[y][j])
    {
      x = par[x][j], y = par[y][j];
    }
  }
  return par[x][0];
}
int nodes[maxn];

int stk[maxn], tp;
bool cmp(int a, int b)
{
  return dfn[a] < dfn[b];
}
ll dp(int u)
{
  //u is a leaf
  if (!h.head[u])
  {
    return mc[u];
  }
  ll ret = 0;
  for (int t = h.head[u]; t; t = h.e[t].nex)
  {
    ret += dp(h.e[t].to);
  }
  //要么切断自身，要么切内部
  ret = min(ret, (ll) mc[u]);
  h.head[u] = 0;
  return ret;
}
void sub_task()
{
  h.tot = 0;
  int k, p = 1;
  scanf("%d", &k);
  for (int i = 1; i <= k; i++)
  {
    scanf("%d", nodes + i);
  }
  sort(nodes + 1, nodes + k + 1, cmp);
  //删去所有在某个关键点子树内部的点
  for (int i = 2; i <= k; i++)
  {
    if (lca(nodes[i], nodes[p]) != nodes[p])
    {
      nodes[++p] = nodes[i];
    }
  }
  stk[tp=1] = 1;
  for (int i = 1; i <= p; i++)
  {
    int z = lca(nodes[i], stk[tp]);
    while(true)
    {
      //退栈+连边，直到栈顶第二个元素(右链)的深度比前右链和待加入点的lca的深度小
      //一开始栈中只有根结点和虚根
      if (dep[stk[tp-1]] <= dep[z])
      {
        h.addedge(z, stk[tp--]);
        //倒数第二个结点就是lca的情况,???
        if (stk[tp] != z)
        {
          //assert(false);
          stk[++tp] = z;
        }
        break;
      }
      h.addedge(stk[tp-1], stk[tp]);
      tp--;
    }
    if (stk[tp] != nodes[i])
    {
      stk[++tp] = nodes[i];
    }
  }
  while(tp > 1)
  {
    h.addedge(stk[tp - 1], stk[tp]);
    tp--;
  }
  printf("%lld\n", dp(1));
}
int main()
{
  int m;
  scanf("%d", &n);
  for (int i = 1; i < n; i++)
  {
    int u,v,w;
    scanf("%d%d%d", &u, &v, &w);
    g.addedge(u,v,w);
    g.addedge(v,u,w);
  }
  //1不能被切断
  mc[1] = inf;
  par[1][0] = 0;
  dep[0] = -1;
  dfs(1);
  for (int j = 1; j <= 20; j++)
  {
    for (int i = 1; i <= n; i++)
    {
      par[i][j] = par[par[i][j - 1]][j - 1];
    }
  }
  scanf("%d", &m);
  while(m--)
  {
    sub_task();
  }
  return 0;
}
