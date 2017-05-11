#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;

vector<int> G[maxn];
int n;
int cl[maxn];
map<int, int> map_pool[maxn];
int tot;
int id[maxn];
ll ans[maxn];
ll mx[maxn];
ll cnt[maxn];
void init()
{
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  tot = 0;
}
void add_edge(int u, int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}
int dfs(int cur, int p)
{
  if (G[cur].size() == 1 && G[cur][0] == p)
  {
    map_pool[tot] = {make_pair(cl[cur],1)};
    mx[tot] = 1;
    ans[cur] = cnt[tot] = cl[cur];
    return tot++;
  }
  int large = -1;
  ans[cur] = 0;
  for (int i = 0; i < G[cur].size(); i++)
  {
    const int v = G[cur][i];
    if (v != p)
    {
      id[v] = dfs(v, cur);
      if (large == -1 || map_pool[id[v]].size() > map_pool[large].size())
      {
        large = id[v];
      }
    }
  }
  for (int i = 0; i < G[cur].size(); i++)
  {
    if (G[cur][i] == p) continue;
    const int v = id[G[cur][i]];
    if (v != large)
    {
      for (auto e : map_pool[v])
      {
        map_pool[large][e.first] += e.second;
        if (map_pool[large][e.first] > mx[large])
        {
          mx[large] = map_pool[large][e.first];
          cnt[large] = e.first;
        }
        else if (map_pool[large][e.first] == mx[large])
        {
          cnt[large] += e.first;
        }
      }
    }
  }
  map_pool[large][cl[cur]] += 1;
  if (map_pool[large][cl[cur]] > mx[large])
  {
    mx[large] = map_pool[large][cl[cur]];
    cnt[large] = cl[cur];
  }
  else if (map_pool[large][cl[cur]] == mx[large])
  {
    mx[large] = map_pool[large][cl[cur]];
    cnt[large] += cl[cur];
  }
  ans[cur] = cnt[large];
  return id[cur] = large;
}
int main()
{
  int u, v;
  while(scanf("%d", &n) != EOF)
  {
    init();
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", cl + i);
    }
    for (int i = 1; i < n; i++)
    {
      scanf("%d%d", &u, &v);
      add_edge(u, v);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++)
    {
      printf("%lld ", ans[i]);
    }
    printf("\n");
  }
}
