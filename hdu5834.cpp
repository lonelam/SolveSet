#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
struct edge
{
  int to, w;
} es[maxn * 2];
int tot, N, val[maxn];
vector<int> G[maxn];
void add_edge(int u, int v, int w)
{
  es[tot].to = v;
  es[tot].w = w;
  G[u].push_back(tot++);
  es[tot].to = u;
  es[tot].w = w;
  G[v].push_back(tot++);
  return;
}
int retget[maxn], dpget[maxn];
int upget[maxn], upretget[maxn];
int ans[maxn];
void infodfs(int cur, int p)
{
  int acc = 0;
  int dpval = 0, dpn = -1, dpval2 = 0, dpn2 = -1;
  for (int i = 0; i < G[cur].size(); i++)
  {
    edge & e = es[G[cur][i]];
    if (e.to != p)
    {
      infodfs(e.to, cur);
      int dptmp = dpget[e.to] - e.w;
      int rettmp = retget[e.to] - 2 * e.w;
      if ( rettmp > 0) dptmp -= rettmp;
      if (dpval < dptmp)
      {
        dpval2 = dpval;
        dpval = dptmp;
        dpn = i;
      }
      else if ( dpval2 < dptmp)
      {
        dpval2 = dptmp;
      }
      if (rettmp > 0) acc += rettmp;
    }
  }
  dpget[cur] = dpval + val[cur] + acc;
  retget[cur] = val[cur] + acc;
}
void ansdfs(int cur, int p)
{
  int dpval = 0, dpn = -1, dpval2 = 0;
  for (int i = 0; i < G[cur].size(); i++)
  {
    edge & e = es[G[cur][i]];
    if (e.to != p)
    {
      int dptmp = dpget[e.to] - e.w;
      int rettmp = retget[e.to] - 2 * e.w;
      if ( rettmp > 0) dptmp -= rettmp;
      if (dpval < dptmp)
      {
        dpval2 = dpval;
        dpval = dptmp;
        dpn = i;
      }
      else if ( dpval2 < dptmp)
      {
        dpval2 = dptmp;
      }
    }
  }
  for (int i = 0; i < G[cur].size(); i++)
  {
    edge & e = es[G[cur][i]];

    if (e.to != p)
    {
      int rettmp = max(0, retget[e.to] - 2 * e.w);
      upretget[e.to] = max(0, retget[cur] - rettmp + upretget[cur] - 2 * e.w);
      if (i != dpn)
      {
        upget[e.to] = max(upget[cur]  - rettmp + retget[cur], upretget[cur] + dpget[cur] - rettmp) - e.w;
      }
      else
      {
        upget[e.to] = max(upget[cur] - rettmp + retget[cur], upretget[cur] + retget[cur] + dpval2 - rettmp) - e.w;
      }
    }
  }
  ans[cur] = max(upget[cur] + retget[cur], upretget[cur] + dpget[cur]);
  for (int i = 0; i < G[cur].size(); i++)
  {
    edge & e = es[G[cur][i]];
    if (e.to != p)
    {
      ansdfs(e.to, cur);
    }
  }
}
int main()
{
  int T;
  int u, v, w;
  int kase = 1;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &N);
      tot = 0;
      memset(retget, 0, sizeof(retget));
      memset(dpget, 0, sizeof(dpget));
      memset(upretget, 0, sizeof(upretget));
      memset(upget, 0, sizeof(upget));
      for (int i = 1; i <= N; i++)
      {
        G[i].clear();
        scanf("%d", val + i);
      }
      for (int i = 1; i < N; i++)
      {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
      }
      infodfs(1, -1);
      ansdfs(1, -1);
      printf("Case #%d:\n", kase++);
      for (int i = 1; i<=N; i++)
      {
        //cout <<"*debug * "<< i << " dpget: " << dpget[i] << ", retget: "<< retget[i] <<", upretget:" << upretget[i] <<", upget:  " << upget[i] << endl;
        printf("%d\n", ans[i]);
      }
    }
  }
}
