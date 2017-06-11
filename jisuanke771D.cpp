#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100000 + 100;
struct edge
{
  int to, w;
} es[maxn * 8];
vector<int> G[maxn];
int tot;
void addedge(int from, int to, int w)
{
  G[from].push_back(tot);
  es[tot++] = {to, w};
}
int s, t;
ll dis[maxn];
bool inq[maxn];
int n, m, k, m1, m2;
int u, v, c;
ll spfa()
{
  queue<int> Q;
  Q.push(s - 1);
  memset(dis, 0x3f, sizeof(dis));
  memset(inq,0,sizeof(inq));
  dis[s - 1] = 0;
  while(!Q.empty())
  {
    int cur = Q.front();
    //cout << cur << endl;
    Q.pop();
    inq[cur] = false;
    for (int i = 0; i < G[cur].size(); i++)
    {
      edge & e = es[G[cur][i]];
      if (dis[e.to] > dis[cur] + e.w)
      {
        dis[e.to] = dis[cur] + e.w;
        if (!inq[e.to])
        {
          inq[e.to] = true;
          Q.push(e.to);
        }
      }
    }
  }
  if (dis[t - 1] == inf) dis[t - 1] = -1;
  return dis[t - 1];
}
int main()
{
  while(scanf("%d%d", &n, &m) != EOF)
  {
    int group = n;
    int pi;
    tot = 0;
    for (int i = 0; i < n + m * 2; i++) G[i].clear();
    for (int i = 0; i < m; i++)
    {
      scanf("%d", &k);
      for (int j = 0; j < k; j++)
      {
        scanf("%d", &pi);
        addedge(pi - 1, group + i, 0);//out
        addedge(group + i + m, pi - 1, 0);//in
      }
    }
    scanf("%d", &m1);

    for (int i = 0; i < m1; i++)
    {
      scanf("%d%d%d", &u, &v, &c);
      addedge(u - 1, v - 1, c);
      addedge(v - 1, u - 1, c);
    }
    scanf("%d", &m2);
    for (int i = 0; i < m2; i++)
    {
      scanf("%d%d%d", &u, &v, &c);
      addedge(u + group - 1, v + group - 1 + m, c);//out
      addedge(v + group - 1, u + group - 1 + m, c);//in
    }
    scanf("%d%d", &s, &t);
    printf("%lld\n", spfa());
  }
}
