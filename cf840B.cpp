#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 100;
int d[maxn];
bool vis[maxn];
vector<pair<int,int> > G[maxn];
vector<int> ans;
int cnt;
void dfs(int u,int fa, int route)
{
  vis[u] = true;
  for (pair<int,int> e : G[u])
  {
    if (!vis[e.first])
    {
      dfs(e.first, u, e.second);
    }
  }
  if (d[u] == 1)
  {
    d[u] ^= 1;
    d[fa] ^= 1;
    ans.push_back(route);
  }
}
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  int sum = 0;
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", d+ i);
    if (d[i] != -1)
    {
      sum ^= d[i];
    }
  }
  for (int i = 1; i <= n; i++)
  {
    // scanf("%d", d+ i);
    if (d[i] == -1)
    {
      if (sum)
      {
        d[i] = 1;
        sum = 0;
      }
      else d[i] = 0;
    }
  }
  for (int i = 0; i < m; i++)
  {
    int u,v;
    scanf("%d%d", &u, &v);
    G[u].push_back({v, i + 1});
    G[v].push_back({u, i + 1});
  }
  dfs(1,1,0);
  // assert(!d[1]);
  printf("%d\n", sum!=1?(int)ans.size():-1);
  if (!sum)
  for (int i : ans)
  {
    printf("%d ", i);
  }
}
