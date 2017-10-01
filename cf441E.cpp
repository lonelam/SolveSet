#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300;
// dp[step][how many ones][total_len][lastone];
ld dp[2][maxn][maxn][2];
int main()
{
  ll x, k;
  ld p;
  cin >> x >> k >> p;
  p /= 100.0;
  int len = 0;
  int bone = 0;
  while(x)
  {
    if (x & 1) bone++;
    x /= 2;
    len++;
  }
  dp[0][bone][len][x & 1] = 1;
  for (int i = 1; i <= k; i++)
  {
    memset(dp[i & 1], 0, sizeof(dp[i & 1]));
    for (int b = 1; b <= len + i; b++)
    {
      for (int j = b; j <= len + i; j++)
      {
        dp[i&1][b][j+1][0] += dp[i&1^1][b][j][0] * p;
        dp[i&1][b+1][j][1] += dp[i&1^1][b][j][0] * (1-p);
        dp[i&1][b][j+1][0] += dp[i&1^1][b][j][1] * p;
        if (b < j) dp[i&1][b][j][0] += dp[i&1^1][b][j][1] * (1-p);
        else dp[i&1][1][j+1][0] += dp[i&1^1][b][j][1] * (1-p);
      }
    }
  }
    ld ans = 0;
    for (int b = 1; b < maxn; b++)
    {
      for (int j = b; j <= len + k; j++)
      {
        ans += (dp[k & 1][b][j][0] + dp[k & 1][b][j][0]) * j;
      }
    }
  cout << ans << endl;
}
