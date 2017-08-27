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
} es[maxn * 10];
int tot;
vector<int> G[maxn];

void add(int u, int v, int w)
{
  es[tot] = {v, w};
  G[u].push_back(tot++);
  es[tot] = {u, w};
  G[v].push_back(tot++);
}
int n, m;
bool vis[maxn];
int t[maxn];
vector<int> base;
void dfs(int u, int now)
{
  t[u] = now;
  vis[u] = true;
  for (int eno: G[u])
  {
    edge & e = es[eno];
    if (vis[e.v])
    {
      base.push_back(now ^ e.w ^ t[e.v]);
    }
    else dfs(e.v, now ^ e.w);
  }
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    static int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add(u,v,w);
  }
  dfs(1, 0);
  int ans = t[n];
  vector<int> candidate;
  for (int x: base)
  {
    for (int y: candidate)
    {
      x = min(x, y ^ x);
    }
    if (x)
    {
      candidate.push_back(x);
      ans = min(ans, ans ^ x);
    }
  }

  printf("%d\n", ans);
}
