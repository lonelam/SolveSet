#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n, T;
int dp[105];
int c[maxn], g[maxn];
int main()
{
  while(scanf("%d%d", &n, &T) !=EOF)
  {
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
      static int m, s;
      scanf("%d%d", &m, &s);
      for (int j = 0; j < m; j++)
      {
        scanf("%d%d", c + j, g + j);
      }
      if (s == 2)
      {
        for (int j = 0; j < m; j++)
        {
          for (int k = T; k >= c[j]; k--)
          {
            if (dp[k-c[j]] != -1)dp[k] = max(dp[k], dp[k - c[j]] + g[j]);
          }
        }
      }
      else if (s == 1)
      {
        static int tdp[105];
        memcpy(tdp, dp, sizeof(dp));
        for (int k = T; k >= 0; k--)
        {
          for (int j = 0; j < m; j++)
          {
            if (k >= c[j] && dp[k-c[j]] != -1) tdp[k] = max(tdp[k], dp[k - c[j]] + g[j]);
          }
        }
        memcpy(dp, tdp, sizeof(dp));
      }
      else if (s == 0)
      {
        static int tdp[105];
        memset(tdp,-1,sizeof(tdp));
        for (int j = 0; j < m; j++)
        {
          for (int k = T; k >= c[j]; k--)
          {
            if (tdp[k-c[j]] != -1) tdp[k] = max(tdp[k], tdp[k - c[j]] + g[j]);
            if (dp[k-c[j]] != -1) tdp[k] = max(tdp[k], dp[k - c[j]] + g[j]);
          }
        }
        memcpy(dp, tdp, sizeof(dp));
      }
    }
    int ans = -1;
    for (int i = 0; i <= T; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);
  }
}
