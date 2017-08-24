#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int deg[maxn], use[maxn];
vector<int> G[maxn];
int vis[maxn];
int n;
int m;
int check()
{
  for (int i = 1; i <= n; i++)
  {
    use[i] = false;
    deg[i] = G[i].size();
  }
  int ans = 0;
  while(true)
  {
    int mx = -1, u;
    for (int i = 1; i <= n; i++)
    {
      if (use[i]) continue;
      if (deg[i] >= mx)
      {
        mx = deg[i];
        u = i;
      }
    }
    if (mx <= 0)
    {
      break;
    }
    ++ans;
    use[u] = true;
    // cout << u << endl;
    vis[u] = true;
    for (int v: G[u])
    {
      --deg[v];
      vis[v] = true;
    }
  }
  return ans;
}
int main()
{
  freopen("data.in", "r", stdin);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int u,v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
    assert(u >= 1 && u <= n);
    assert(v >= 1 && v <= n);
  }
  cout << check() << endl;
  for (int i = 1; i <= n; i++)
  {
    // cout << i << endl;
    // assert(vis[i]);
  }
}
