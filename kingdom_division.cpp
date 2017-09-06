#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const ll moder = 1e9 + 7;
vector<int> G[maxn];
ll dp[maxn][2][2];
void dfs(int u, int fa)
{
  for (int k = 0; k < 2; k++)
  {
    for (int s = 0; s < 2; s++)
    {
      dp[u][k][s] = 1;
    }
  }
  for (int v: G[u])
  {
    if (v != fa)
    {
      dfs(v, u);
      for (int k = 0; k < 2; k++)
      {
        dp[u][k][1] = (dp[u][k][1] * dp[v][k^1][0]) % moder;
        dp[u][k][0] = (dp[u][k][0] * (dp[v][k][0] + dp[v][k][1] + dp[v][k^1][0])) % moder;
      }
    }
  }
  for (int k = 0; k < 2; k++)
  {
    dp[u][k][0] = (dp[u][k][0] + moder - dp[u][k][1])% moder;
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++)
  {
    int u,v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1,1);
  printf("%lld\n", (dp[1][0][0] + dp[1][1][0])% moder);
}
