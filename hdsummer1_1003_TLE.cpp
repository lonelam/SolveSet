#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
int c[maxn];
vector<int> G[maxn];
int n;
ll ans;
ll sz[maxn];
void init()
{
  ans = (ll)n * (ll)(n - 1) / 2LL;
  for (int i = 0; i < n;i ++)
  {
    G[i].clear();
  }
}
void addedge(int u, int v)
{
  G[u].push_back(v);
  G[v].push_back(u);
}
void calcans(int cur, int parent, ll upsize = 0)
{
  ans += sz[cur] * upsize;
  for (int v : G[cur])
  {
    if (v != parent)
    {
      calcans(v, cur, upsize + sz[cur] - sz[v]);
    }
  }
}
map<int,ll> dfs(int cur, int parent)
{
  vector<map<int, ll > > trees;
  sz[cur] = 1;
  for (int v: G[cur])
  {
    if (v != parent)
    {
      trees.emplace_back(dfs(v, cur));
      sz[cur] += sz[v];
    }
  }
  int main_id = 0;
  int tar = 0;
  for (int v: G[cur])
  {
    if (v != parent)
    {
      ans -= (n - sz[v]) * trees[tar++][c[cur]];
    }
  }
  for (int i = 0; i < trees.size(); i++)
  {
    if (trees[i].size() > trees[main_id].size())
    {
      main_id = i;
    }
  }
  for (int i = 0; i < trees.size(); i++)
  {
    if (i != main_id)
    {
      for (pair<int, ll> x: trees[i])
      {
        ans -= trees[main_id][x.first] * x.second;
        trees[main_id][x.first] += x.second;
      }
    }
  }
  if (!trees.empty())
  {
    //ans -= trees[main_id][c[cur]];
    trees[main_id][c[cur]] = sz[cur];
    return trees[main_id];
  }
  return map<int, ll>({{c[cur], sz[cur]}});
}
int main()
{
  int kase = 1;

  freopen("/home/lais/Downloads/多校联合训练第一场标程及数据/数据/1003.in", "r", stdin);
  while(scanf("%d", &n) !=EOF)
  {
    init();
    for (int i = 0; i < n;i++)
    {
      scanf("%d", c + i);
    }
    int u, v;
    for (int i = 1; i < n; i++)
    {
      scanf("%d%d", &u, &v);
      u--, v--;
      addedge(u,v);
    }
    dfs(0, 0);
    calcans(0,0,0);
    printf("Case #%d: %lld\n",kase++, ans);
  }
}
