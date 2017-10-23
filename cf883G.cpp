#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 10;
int n, m, s;
struct edge
{
  bool t;
  int u, v;
} es[maxn];
bool vis[maxn];
vector<int> G[maxn];
char ans[maxn];
int cnt;
void dfsmax(int u)
{
  vis[u] = true;
  cnt++;
  for (int i = 0; i < G[u].size(); i++)
  {
    edge & e = es[G[u][i]];
    if (e.t)
    {
      if (e.u == u)
      {
        if (!vis[e.v])
        {
          ans[G[u][i]] = '+';
          dfsmax(e.v);
        }
      }
      else
      {
        if (!vis[e.u])
        {
          ans[G[u][i]] = '-';
          dfsmax(e.u);
        }
      }
    }
    else
    {
      if (!vis[e.v])
      {
        dfsmax(e.v);
      }
    }
  }
}
void dfsmin(int u)
{
  vis[u] = true;
  cnt++;
  for (int i = 0; i < G[u].size(); i++)
  {
    edge & e = es[G[u][i]];
    if (e.t)
    {
      if (e.u ==  u)
      {
        ans[G[u][i]] = '-';
      }
      else
      {
        ans[G[u][i]] = '+';
      }
    }
    else if (!vis[e.v])
    {
      dfsmin(e.v);
    }
  }
}
int main()
{
  scanf("%d%d%d", &n, &m, &s);
  int tmp;
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%d", &tmp, &es[i].u, &es[i].v);
    G[es[i].u].push_back(i);
    es[i].t = (tmp == 2);
    if (tmp == 2) G[es[i].v].push_back(i), ans[i]='+';
  }
  cnt = 0;
  dfsmax(s);
  printf("%d\n", cnt);
  for (int i = 0; i < m; i++)
  {
    if (es[i].t)printf("%c", ans[i]);
  }
  printf("\n");
  cnt = 0;
  memset(vis,0,sizeof(vis));
  dfsmin(s);
  printf("%d\n", cnt);
  for (int i = 0; i < m; i++)
  {
    if (es[i].t)printf("%c", ans[i]);
  }
  printf("\n");


}
