#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
int T;
int n, m, s, e;
struct len
{
  int a, b;
  bool operator<(const len & rhs) const
  {
    return a < rhs.a || a == rhs.a && b > rhs.b;
  }
  len operator+(const len & rhs)
  {
    len ret = (*this);
    ret.a += rhs.a;
    ret.b += rhs.b;
    return ret;
  }
}dis[maxn];
struct edge
{
  int v;
  len w;
};
int u, v, al, be;
vector<edge> G[maxn];
bool inq[maxn];
void spfa()
{
  queue<int> Q;
  for (int i = 1; i <= n; i++)
  {
    dis[i].a = inf;
    dis[i].b = 0;
  }
  dis[s].a = 0;
  Q.push(s);
  inq[s] = true;
  while(!Q.empty())
  {
    int cur = Q.front();
    Q.pop();
    inq[cur] = false;
    for (edge & e: G[cur])
    {
      if ( dis[cur] + e.w < dis[e.v])
      {
        dis[e.v] = dis[cur] + e.w;
        if (!inq[e.v])
        {
          inq[e.v] = true;
          Q.push(e.v);
        }
      }
    }
  }
  cout << dis[e].a << " "<< dis[e].b << endl;
}
int main()
{

  while(cin >> T)
  {
    while(T--)
    {
      cin >> n >> m >> s >> e;
      for (int i = 1; i <= n; i++)
      {
        G[i].clear();
      }
      for (int i = 0; i < m; i++)
      {
        cin >> u >> v >> al >> be;
        G[u].push_back({v, {al,be}});
        G[v].push_back({u, {al,be}});
      }
      spfa();
    }
  }
}
