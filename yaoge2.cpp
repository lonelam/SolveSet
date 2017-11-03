#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n;
int P[maxn];
int H[maxn];
int dp[maxn][2];
int main()
{
  while(cin >> n)
  {
    for (int i = 1; i <= n; i++)
    {
      cin >> P[i] >> H[i];
    }
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
      dp[i][1] = dp[i][0] = min(dp[i-1][1], dp[i-1][0]) + 1;
      for (int j = 1; j < i; j++)
      if (P[i] - P[j] < H[i])
      {
        dp[i][0] = min(dp[i][0], dp[j][0]);
      }
      for (int j = 1; j < i; j++)
      if (P[i] - P[j] < H[j])
      {
        dp[i][1] = min(dp[i][1], dp[j][1]);
      }
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
  }
}
