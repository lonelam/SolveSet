#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 5;
struct opt
{
  int w, x, y;
  bool operator< (const opt & R)const
  {
    return w < R.w;
  }
};
int n, m, K;
vector<int> W;
void merge(vector<int> & V, vector<int> B)
{
  priority_queue<opt> Q;
  for (int i = 0; i < B.size(); i++)
  {
    Q.push({V[0] + B[i], i, 0});
  }
  W.resize(0);
  while(W.size() < K && !Q.empty())
  {
    auto it = Q.top(); Q.pop();
    W.push_back(it.w);
    if (it.y + 1 < V.size())
    {
      ++it.y;
      Q.push((opt) {B[it.x] + V[it.y], it.x, it.y});
    }
  }
  V = W;
}
struct edge
{
  int x, w;
} es[maxn << 2];
vector<int> G[maxn];
int etot;
void addedge(int u, int v, int w)
{
  es[etot] = {v, w};
  G[u].push_back(etot++);
  es[etot] = {u, w};
  G[v].push_back(etot++);
}
vector<int> res;
int dfn[maxn], low[maxn], dfs_clock;
stack<int> S;
void dfs(int x, int fa)
{
  dfn[x] = low[x] = ++dfs_clock;
  for (int eno: G[x])
  {
    edge & e = es[eno];
    int y = e.x;
    if (!dfn[y])
    {
      S.push(eno);
      dfs(y, eno ^ 1);
      low[x] = min(low[x], low[y]);
      if (low[y] > dfn[x]) {}//(x, y) is bridge
      if (low[y] >= dfn[x])
      {
        int j;
        vector<int> V;
        do
        {
          j = S.top();
          S.pop();
          V.push_back(es[j].w);
        }while(j != eno);
        if (V.size() > 1)
        {
          merge(res, V);
        }
      }
    }
    else if (eno != fa && dfn[y] < dfn[x])
    {
      S.push(eno), low[x] = min(low[x], dfn[y]);
    }
  }
}
void work()
{
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }

  etot = dfs_clock = 0;
  int sum = 0;
  for  (int i = 0; i < m; i++)
  {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    addedge(x,y,z);
    sum += z;
  }
  scanf("%d", &K);
  res.resize(0);
  res.push_back(0);
  memset(dfn,0,sizeof(dfn));
  dfs(1, 0);
  int w = 0;
  for (int i = 0; i < res.size(); i++)
  {
    w += (i + 1) * (sum - res[i]);
  }
  static int ca = 0;
  printf("Case #%d: %u\n", ++ca, w);
}
int main()
{
  // freopen("C:\\hdsummer_data\\r1\\data\\1009.in", "r", stdin);
  res.reserve(maxn);
  W.reserve(maxn);
  while(scanf("%d%d", &n, &m) != EOF)
  {
    work();
  }
  return 0;
}
