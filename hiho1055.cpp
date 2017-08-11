#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
const int maxm = 100 + 5;
int v[maxn];
int dp[maxn][maxm];
vector<int> G[maxn];
int n, m;
void dfs(int cur, int parent)
{
  dp[cur][1] = v[cur];
  for (int v : G[cur])
  {
    if (v != parent)
    {
      dfs(v, cur);
      for (int k = m; k > 0; k--)
      {
        for (int j = k - 1; j > 0; j--)
        {
          dp[cur][k] = max(dp[cur][k], dp[v][k-j] + dp[cur][j]);
        }
      }
    }
  }
}
int main()
{
  while(cin >> n >> m)
  {
    for (int i = 1; i <= n; i++)
    {
      cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
      int u,v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(1,1);

    cout << dp[1][m] << endl;
  }
}
