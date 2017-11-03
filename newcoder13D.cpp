#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
vector<int> G[maxn];
int deg[maxn];
int vis[maxn];
int tot;
void dfs(int u)
{
  vis[u] = 1;
  tot++;
  for(int v: G[u])
  {
    if (!vis[v])
    {
      dfs(v);
    }
  }
}
    map<int,int> cnt;
int n, m;
void solve()
{
  dfs(1);
    for (int i = 1; i <= n; i++)
    {
      if (deg[i] > 4)
      {
        cout << "NotValid\n";
        return;
      }
      cnt[deg[i]]++;
    }
      if (tot != n)
      {
        cout << "NotValid\n";
        return;
      }
    if (cnt[4] == 1 && cnt[3] == 0)
    {
      cout << "X"<< endl;
      return;
    }
    if (cnt[3] == 1 && cnt[4] == 0)
    {
      cout << "Y" << endl;
      return;
    }
    if (cnt[3] == cnt[4] && cnt[3] == 0)
    {
      cout << "I" << endl;
      return;
    }
        cout << "NotValid\n";
        return;
}
int main()
{
  while(cin >> n >> m)
  {
    cnt.clear();
    tot = 0;
    int u, v;
    memset(vis,0,sizeof(vis));
    for (int i = 0; i < m; i++)
    {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
      deg[u]++;
      deg[v]++;
    }
    solve();
  }
}
