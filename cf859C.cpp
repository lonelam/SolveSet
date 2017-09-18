#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n;
int a[maxn];
//token 0 max value
int dp[maxn][2];
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", a + i);
  }
  dp[n][0] = dp[n][1] = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (dp[i+1][0] > dp[i+1][1] + a[i])
    {
      dp[i][0] = dp[i+1][0];
    }
    else
    {
      dp[i][0] = dp[i+1][1] + a[i];
    }
    if (dp[i+1][1]  + a[i] > dp[i+1][0])
    {
      dp[i][1] = dp[i+1][0];
    }
    else
    {
      dp[i][1] = dp[i+1][1] + a[i];
    }
  }
  printf("%d %d\n",accumulate(a, a + n, 0) - dp[0][0],dp[0][0]);
}
