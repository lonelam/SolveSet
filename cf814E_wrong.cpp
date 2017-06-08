
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50 + 5;
ll dp[maxn][maxn][maxn][maxn];
const ll moder = 1e9 + 7;
int d[maxn];
int main()
{
  int n;
  while(cin >> n)
  {
    for (int i = 0; i < n; i++)
    {
      cin >> d[i];
    }
    memset(dp, 0, sizeof(dp));
    if (d[0] == 2)
    {
      dp[0][0][1][0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
      if (d[i] == 2)
      {
        for (int j = 0; j <= n; j++)
        {
          for (int k = 0; k <= n; k++)
          {
            for (int s = 0; s <= 1; s++)
            {
              dp[i][j][k][s] = (dp[i - 1][j + 2][k][s] * (j + 2) * (j + 1) / 2 + dp[i - 1][j][k + 1][s] * (k + 1) + dp[i - 1][j][k + 1][s] * (k + 1) * j +dp[i - 1][j][k][s] * j ) % moder;
              if (j) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j - 1][k][s + 1] + dp[i - 1][j - 1][k][s + 1] * k) % moder;
              if (j >= 2) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j - 2][k + 1][s] * (k + 1)) % moder;
              if (k) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j + 1][k - 1][s + 1] * (j + 1)) % moder;
              if (j && k) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j - 1][k - 1][s + 1] ) % moder;
            }
          }
        }
      }
      cout << dp[i][0][0][0] << endl;
    }

    cout << dp[n - 1][0][0][0] << endl;
  }
}
