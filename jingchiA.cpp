#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
const int maxm = 50 + 1;
int dis[maxn][maxm];
    int n, m1, m2;
    int L;
bool inq[maxn][maxm];
vector<pair<int,int> > G[maxn];
vector<int> H[maxn];
int spfa()
{
  memset(dis, inf, sizeof(dis));
  dis[1][0] = 0;
  inq[1][0] = true;
  queue<pair<int,int> > Q;
  Q.push({1, 0});
  while(!Q.empty())
  {
    pair<int,int> cur = Q.front();
    Q.pop();
    inq[cur.first][cur.second] = false;
    if (cur.second < m1)
    for (int v: H[cur.first])
    {
      pair<int,int> t = {v, cur.second + 1};
      if (dis[t.first][t.second] > dis[cur.first][cur.second])
      {
        // cout << dis[t.first][t.second] << endl;
        dis[t.first][t.second] = dis[cur.first][cur.second];
        // cout << " " << cur.first << " "<< cur.second << " " <<dis[t.first][t.second] << endl;
        if (!inq[t.first][t.second])
        {
          Q.push(t);
          inq[t.first][t.second] = true;
        }
      }
    }
    for (pair<int,int> e: G[cur.first])
    {
      pair<int,int> t = {e.first, cur.second};
      if (dis[t.first][t.second] > dis[cur.first][cur.second] + e.second)
      {
        dis[t.first][t.second] = dis[cur.first][cur.second] + e.second;
        // cout << " " << cur.first << " "<< cur.second << " " <<dis[t.first][t.second] << endl;
        if (!inq[t.first][t.second])
        {
          Q.push(t);
          inq[t.first][t.second] = true;
        }
      }
    }
  }
  int ans = inf;
  for (int i = 0; i <= m1; i++)
  {
    if (dis[n][i] + i <= L)
    {
      ans = min(dis[n][i], ans);
      // cout << n << endl;
      // cout << dis[n][i] << endl;
    }
  }
  if (ans == inf) ans = -1;
  return ans;
}
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d%d%d", &n, &m1, &m2, &L);
    for (int i = 1; i <= n; i++)
    {
      G[i].clear();
      H[i].clear();
    }
    int u , v, c;
    for (int i = 0; i < m1; i++)
    {
      scanf("%d%d", &u, &v);
      H[u].push_back(v);
      H[v].push_back(u);
    }
    for (int i = 0;i < m2; i++)
    {
      scanf("%d%d%d", &u, &v, &c);
      G[u].push_back({v, c});
      G[v].push_back({u, c});
    }
    printf("%d\n", spfa());
  }
}
