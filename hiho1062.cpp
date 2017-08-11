#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const int maxk = 20;
map<string, int> id;
map<int, string> table;
int tot;
int n, m;
char tmp[maxn];
int get_id()
{
  if (id.find(tmp) != id.end())
  {
    return id[tmp];
  }
  else
  {
    table[tot] = tmp;
    return id[tmp]=tot++;
  }
}
vector<int> G[maxn];
int fa[maxn][maxk];
int d[maxn];
void dfs(int cur, int parent)
{
  fa[cur][0] = parent;
  for (int k = 1; k < maxk; k++)
  {
    fa[cur][k] = fa[fa[cur][k-1]][k-1];
  }
  for (int nex: G[cur])
  {
    if (nex != parent)
    {
      d[nex] = d[cur] + 1;
      dfs(nex, cur);
    }
  }
}
int lca(int x, int y)
{
  if (d[x] < d[y])
  {
    swap(x,y);
  }
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (d[fa[x][k]] >= d[y])
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
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    tot = 0;
    for (int i = 0; i < n;i ++)
    {
      scanf("%s", tmp);
      int u = get_id();
      scanf("%s", tmp);
      int v = get_id();
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(0,0);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
      scanf("%s", tmp);
      int u = get_id();
      scanf("%s", tmp);
      int v = get_id();
      printf("%s\n", table[lca(u, v)].c_str());
    }
  }
}
