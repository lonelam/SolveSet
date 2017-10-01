#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
ll dp[maxn][maxn];
ll a[maxn];
int n, m;
int T;
int main()
{
  while(~scanf("%d", &T))
  {
    while(T--)
    {
      scanf("%d%d", &n, &m);
      for (int i = 0; i < n; i++)
      {
        scanf("%d", a + i);
      }
      sort(a, a + n);
      memset(dp, inf, sizeof(dp));
      dp[0][0] = 0;
      for (int i = 1; i <= n; i++)
      {
        for (int j = 1; j <= i; j++)
        {
          for (int k = 0; k < i  ; k++)
          {
            dp[i][j] = min(dp[i][j], dp[k][j-1] + (a[i-1] - a[k]) * (a[i-1] - a[k]));
          }
        }
      }
      printf("%lld\n", dp[n][m]);
    }
  }
}
