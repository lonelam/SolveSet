#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int dp[205][8010];
int tdp[205][8010];
int in[205][2];
int main()
{
  int N, K, i, j, k;
  scanf("%d%d", &N, &K);
  for (i = 1; i <= N; i++)
  {
    ll t;
    scanf("%lld", &t);
    while(t % 2 == 0)
    {
      in[i][0]++;
      t /= 2;
    }
    while(t % 5 == 0)
    {
      in[i][1]++;
      t /= 5;
    }
  }
  for (i = 0; i <= K; i++)
  {
    for (j = 0; j <= 3600; j++)
    {
      dp[i][j] = -inf;
    }
  }
  dp[0][0] = 0;
  for (i = 1; i <= N; i++)
  {
    for (j = 0; j <= K; j++)
    {
      for (int k = 0; k <= 3600; k++)
      {
        tdp[j][k] = dp[j][k];
      }
    }
    for (int j = 0;j < K; j++)
    {
      for (int k = 0; k <= 3600; k++)
      {
        int j2 = j + 1, k2 = min(k + in[i][1], 3600);

          tdp[j2][k2] = max(tdp[j2][k2], dp[j][k] + in[i][0]);
      }
    }
    for (int j = 0; j <= K; j++)
    {
      for (int k = 0; k <= 3600; k++)
      {
        dp[j][k] = tdp[j][k];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= K; i++) for (int j = 0; j <= 3600; j++) ans = max(ans, min(j, dp[i][j]));
  return !printf("%d\n", ans);
}
