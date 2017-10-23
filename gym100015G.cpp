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
  int v, w;
};
int inq[maxn], dis[maxn];
vector<edge> G[maxn];
bool solve(int x)
{
  inq[x] = 1;
  for (int i = 0; i < G[x].size(); i++)
  {
    edge & e = G[x][i];
    if (dis[e.v] > dis[x] + e.w)
    {
      dis[e.v] = dis[x] + e.w;
      if (inq[e.v]) return false;
      if (!solve(e.v)) return false;
    }
  }
  inq[x] = 0;
  return true;
}
char cmd[10];
int i, j, c;
int n, m, q;
int main()
{
  while(~scanf("%d%d%d", &n, &m, &q))
  {
    memset(inq,0,sizeof(inq));
    memset(dis,inf,sizeof(dis));
    if (n == 0 && m == 0 && q == 0)
    {
      return 0;
    }
    int tot = n + m + 1;
    for (int i = 0; i < tot; i++) G[i].clear();
    for (int k = 0; k < q; k++)
    {
      scanf("%d%d%s%d", &i, &j, cmd, &c);
      if (cmd[0] == '<')
      {
        G[j + n].push_back({i, c});
      }
      else if (cmd[0] == '>')
      {
        G[i].push_back({j + n, -c});
      }
      else
      {
        assert(false);
      }
    }
    for (int i = 1; i < tot; i++)
    {
      G[0].push_back({i, 0});
    }
    dis[0] = 0;
    if (solve(0))
    {
      printf("Possible\n");
    }
    else
    {
      printf(
        "Impossible\n"
      );
    }
  }
}
/*
2 1 3
1 1 <= 3
2 1 <= 5
1 1 >= 4
2 2 4
1 1 <= 3
2 1 <= 4
1 2 >= 5
2 2 >= 7
0 0 0

*/
