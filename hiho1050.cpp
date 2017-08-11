#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
vector<int> G[maxn];
int dp[maxn];
int ans = 0;
void dfs(int cur, int parent)
{
  int first = -1, second = -1;
  for (int v: G[cur])
  {
    if (v != parent)
    {
      dfs(v, cur);
      if (dp[v] > first)
      {
        second = first;
        first = dp[v];
      }
      else if (dp[v] > second)
      {
        second = dp[v];
      }
    }
  }
  ans = max(ans, first + second + 2);
  dp[cur] = first + 1;
}
int main()
{
  int n;
  while(cin >> n)
  {
    for (int i = 1; i < n;i ++)
    {
      static int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
      dfs(1,1);
      cout << ans << endl;
  }
}
