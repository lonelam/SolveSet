#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 100;
const int maxk = 14;
int n;
int T;
vector<int> G[maxn];
int fa[maxn][maxk];
int d[maxn];
void addedge(int u, int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}
typedef pair<int,int> path;
int dp[maxn];
int mlen;
vector<path> ps;
void dfs(int u, int par)
{
  d[u] = d[par] + 1;
  dp[u] = d[u];
  fa[u][0] = par;
  int one = d[u];
  int two = d[u];
  for (int k = 1; k < maxk; k++)
  {
    fa[u][k] = fa[fa[u][k-1]][k-1];
  }
  for (int v: G[u])
  {
    if (v != par)
    {
      dfs(v, u);
      dp[u] = max(dp[v], dp[u]);
      if (dp[v] > one)
      {
        two = one;
        one = dp[v];
      }
      else if (dp[v] > two)
      {
        two = dp[v];
      }
    }
  }
  mlen = max(mlen, one + two - 2 * d[u]);
}
int main()
{
  scanf("%d", &T);
  while(T--)
  {
    mlen = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
      static int u, v;
      scanf("%d%d", &u, &v);
      addedge(u,v);
    }
  }
}
