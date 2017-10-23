#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
struct edge
{
  int v, cost;
};
vector<edge> G[maxn];
int n, m;
int inq[maxn];
int dis[maxn];
int vis[maxn];
int flg = 0;
bool spfa()
{
  dis[0] = 0;
  queue<int> Q;
  Q.push(0);
  vis[0] = 1;
  inq[0] = 1;
  while(!Q.empty())
  {
    int cur = Q.front();
    Q.pop();
    inq[cur] = 0;
    for (int i = 0; i < G[cur].size(); i++)
    {
      if (dis[G[cur][i].v] > G[cur][i].cost + dis[cur])
      {
        dis[G[cur][i].v] = G[cur][i].cost + dis[cur];
        if (!inq[G[cur][i].v])
        {
          inq[G[cur][i].v] = 1;
          Q.push(G[cur][i].v);
          if (++vis[G[cur][i].v] >= n)
          {
            return false;
          }
        }
      }
    }
  }
  return true;
}
int cmd, a, b, c;
// bool solve(int x)
// {
//   inq[x] = 1;
//   for (int i = 0; i < G[x].size();i ++)
//   {
//     edge v = G[x][i];
//     if (dis[v.v] > dis[x] + v.cost)
//     {
//       dis[v.v] = dis[x] + v.cost;
//       if (inq[v.v])
//       {
//         return false;
//       }
//       else
//       {
//         if (!solve(v.v)) return false;
//       }
//     }
//   }
//   inq[x] = 0;
//   return true;
// }
int main()
{
  while(~scanf("%d%d", &n, &m ))
  {
    memset(inq,0,sizeof(inq));
    memset(vis, 0, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    flg = 0;
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 0; i < m; i++)
    {
      scanf("%d", &cmd);
      if (cmd == 1)
      {
        scanf("%d%d%d", &a, &b, &c);
        G[a].push_back({b, -c});
      }
      else if (cmd == 2)
      {
        scanf("%d%d%d", &a, &b, &c);
        G[b].push_back({a, c});
      }
      else if (cmd == 3)
      {
        scanf("%d%d", &a, &b);
        G[a].push_back({b, 0});
        G[b].push_back({a, 0});
      }
    }
    for (int i = 1; i <= n; i++)
    {
      G[0].push_back({i, 0});
    }
    dis[0] = 0;
    if (spfa())
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }
  }
}
