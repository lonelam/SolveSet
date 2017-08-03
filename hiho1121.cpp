#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int n, m;
vector<int> G[maxn];
int vis[maxn];
void addedge(int u, int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}
bool dfs(int cur, int parent)
{
  for (int v: G[cur])
  {
    if (v != parent)
    {
      if (vis[v] == -1)
      {
        vis[v] = vis[cur] ^ 1;
        if (!dfs(v, cur) ) return false;
      }
      else if (vis[v] == vis[cur])
      {
        return false;
      }
    }
  }
  return true;
}
int main()
{
  int T;
  int u, v;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d%d", &n, &m);
      for (int i = 1; i <= n; i++)
      {
        G[i].clear();
        vis[i] = -1;
      }
      for (int i = 0; i < m; i++)
      {
        scanf("%d%d", &u, &v);
        addedge(u, v);
      }
      bool ans = true;
      for (int i = 1; i <= n; i++)
      {
        if (vis[i] == -1)
        {
          vis[i] = 0;
          if (!dfs(i,i)) ans = false;
        }
      }
      if (ans)
      {
        printf("Correct\n");
      }
      else
      {
        printf("Wrong\n");
      }
    }
  }
}
