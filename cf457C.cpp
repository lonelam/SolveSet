#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000  + 10;
int n, m;
int dp[maxn];
int mstw = 1e8 + 7;
int main()
{
  while(~scanf("%d%d", &n, &m))
  {
    printf("%d %d\n", mstw, mstw);
    int rem = mstw;

    for (int i = 2; i < n; i++)
    {
      dp[i] = dp[i-1] + 1;
    }
    dp[n] = mstw;
    for (int i = 1; i < n; i++)
    {
      printf("%d %d %d\n", i, i + 1, dp[i + 1] - dp[i]);
    }
    m -= n - 1;
    for (int i = 1; i < n && m; i++)
    {
      for (int j = i + 2; j <= n && m; j++)
      {
        printf("%d %d %d\n", i, j, dp[j] - dp[i]);
        m--;
      }
    }
  }
}
