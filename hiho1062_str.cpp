
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int maxk = 20;
map<string, string> fa[maxk];
map<string, vector<string> > G;
map<string, int> depth;
map<string, bool> vis;
void dfs(string & cur, string & parent)
{
  // cout << cur << endl;
  fa[0][cur] = parent;
  for (int k = 1; k < maxk; k++)
  {
    fa[k][cur] = fa[k-1][fa[k-1][cur]];
  }
  for (string & v: G[cur])
  {
    depth[v] = depth[cur] + 1;
    dfs(v,cur);
  }
}
string lca(const string * x,const string *y)
{
  if (depth[*x] > depth[*y]) swap(x, y);
  for (int k = maxk-1; k>=0; k--)
  {
    if (depth[*y] - (1<<k)>= depth[*x])
    {
      y = &fa[k][*y];
    }
  }
  if (*x == *y)
  {
    return *x;
  }
  for (int k = maxk - 1; k>= 0; k--)
  {
    if (fa[k][*x] != fa[k][*y])
    {
      x = &fa[k][*x];
      y = &fa[k][*y];
    }
  }
  return fa[0][*x];
}
int main()
{
  int n;
  //ios::sync_with_stdio(false),cin.tie(0);
  while(scanf("%d", &n) != EOF)
  {
    static string u, v;
    string origin = "";
    static char a[maxn], b[maxn];
    for (int i = 0; i < n; i++)
    {
      scanf("%s%s", a, b);
      u = a;
      v = b;
      if (origin.empty())
      {
        origin = u;
      }
      G[u].push_back(v);
      fa[0][v] = u;
    }
    depth[origin] = 0;
    dfs(origin, origin);
    int q;
    scanf("%d", &q);
    while(q--)
    {
      scanf("%s%s", a,b);
      u = a;
      v = b;
      printf("%s\n", lca(&u, &v).c_str());
//      cout << lca(&u, &v) << endl;
    }
  }
}
