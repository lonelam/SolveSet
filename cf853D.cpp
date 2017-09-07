#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 100;
const int maxk = 21;
int a[maxn];
int dp[maxn][21];
int n;
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", a + i);
    a[i] /= 1000;
  }
  memset(dp, inf, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < maxk; j++)
    {
      if (dp[i-1][j] == inf) continue;
      //pay with part of bonus, k in bonus, a[i] * 10 - k in cash
      for (int k = 1; k <= min(j, a[i]*10); k++)
      {
        dp[i][j - k] = min(dp[i][j-k], dp[i-1][j] + a[i] * 10 - k);
      }
      //pay with cash
      if (j + a[i] < maxk) dp[i][j+a[i]] = min(dp[i][j+a[i]], dp[i-1][j] + a[i] * 10);
    }
  }
  int ans = inf;
  for (int i = 0; i < maxk; i++)
  {
    ans = min(ans, dp[n][i]);
  }
  printf("%d\n", ans * 100);
}
