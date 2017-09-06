#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
const int maxk = 21;
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
}
void addedge(int u, int v)
{
  G[u].push_back(v);
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
  for (int v: G[cur])
  {
      depth[v] = 1 + depth[cur];
      dfs(v, cur);
  }
}
ll dist(int u, int v)
{
  int _lca = lca(u, v);
  return dis[u] + dis[v] - 2 * dis[_lca];
}
map<string, int> disc;
map<int, string> name;
int main()
{
  int N;
  while(cin >> N)
  {
    int t = 1;
    string u, v;
    n = 2 * N;
    init();
    disc.clear();
    name.clear();
    for (int i = 0; i < N; i++)
    {
      cin >> u >> v;
      if (!disc[u])
      {
        name[t] = u;
        disc[u] = t++;
      }
      if (!disc[v])
      {
        name[t] = v;
        disc[v] = t++;
      }
      addedge(disc[u], disc[v]);
    }
    int Q;
    cin >> Q;
    dis[1] = 0;
    depth[1]=0;
    dfs(1, 1);
    while(Q--)
    {
      cin >> u >> v;
      cout << name[lca(disc[u], disc[v])] << endl;
    }
  }
}
