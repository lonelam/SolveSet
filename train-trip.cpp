#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int T;
int n;
ll dp_cost[maxn];
int dp_member[maxn];
ll cost[3];
vector<int> G[maxn];
int fa[maxn];
void dfs(int cur, int parent)
{
  fa[cur] = parent;
  for (int v: G[cur])
  {
    if (v != parent)
    {
      dfs(v, cur);
      dp_member[cur] += dp_member[v];
      if (dp_member[v])
      {
        dp_cost[cur] += dp_cost[v] + cost[dp_member[v] - 1];
      }
    }
  }
}

int main()
{
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d%lld%lld%lld", &n, cost, cost +1, cost + 2);
      cost[1] = min({cost[1], cost[0] * 2,cost[2] + cost[0]});
      cost[2] = min({cost[2], cost[1] + cost[0], cost[0] * 3});
      for (int i = 1; i <= n; i++)
      {
        dp_cost[i] = 0;
        dp_member[i] = 0;
        G[i].clear();
      }
        int tmp[3];
      for (int i = 0; i < 3; i++)
      {
        scanf("%d", tmp + i);
        dp_member[tmp[i]]++;
      }
      int u,v;
      for (int i = 1; i < n; i++)
      {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
      }
      dfs(1,1);
      if (cost[0] > cost[1] + cost[2])
      {
        ll len = 0;
        for (int i = 0; i < 3; i++)
        {
          int p = tmp[i];
          ll cnt = 0;
          while(dp_member[p] == 1)
          {
            cnt+=(cost[0] - cost[1] - cost[2]);
            p = fa[p];
          }
          if (dp_member[p] == 2)
          {
            while(dp_member[p] == 2)
            {
              cnt -= cost[0] + cost[2] - cost[1];
              p = fa[p];
            }
          }
          len = max(len, cnt);
        }
        dp_cost[1] =min(dp_cost[1], dp_cost[1] - (ll) len);
      }
      printf("%lld\n", dp_cost[1]);
    }
  }
}
/*

100
8
2 1 3
2 5 8
1 2
1 3
3 5
3 4
6 7
7 8
6 4
*/
