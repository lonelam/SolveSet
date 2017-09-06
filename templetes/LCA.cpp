typedef long long ll;
const int maxn = 100000 + 100;
const int maxk = 20;
struct edge
{
  int v, w;
} es[maxn * 2];
int tot;
vector<int> G[maxn];
ll dis[maxn];
int fa[maxn][maxk];
int depth[maxn];
int n, m;
void init()
{
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  tot = 0;
}
void addedge(int u, int v, int w)
{
  G[u].push_back(tot);
  es[tot++] = {v, w};
  G[v].push_back(tot);
  es[tot++] = {u, w};
}
int lca(int x, int y)
{
  if (depth[x] > depth[y]) swap(x, y);
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (depth[fa[y][k]] >= depth[x])
    {
      y = fa[y][k];
    }
  }
  if (x == y) return x;
  for (int k = maxk -1 ; k>= 0; k--)
  {
    if (fa[x][k] != fa[y][k])
    {
      x = fa[x][k];
      y = fa[y][k];
    }
  }
  return fa[x][0];
}
void dfs(int cur, int parent)
{
  fa[cur][0] = parent;
  for (int k = 1; k < maxk; k++)
  {
    fa[cur][k] = fa[fa[cur][k - 1]][k - 1];
  }
  for (int eno: G[cur])
  {
    edge & e = es[eno];
    if (e.v != parent)
    {
      dis[e.v] = e.w + dis[cur];
      depth[e.v] = 1 + depth[cur];
      dfs(e.v, cur);
    }
  }
}
ll dist(int u, int v)
{
  int _lca = lca(u, v);
  return dis[u] + dis[v] - 2 * dis[_lca];
}
