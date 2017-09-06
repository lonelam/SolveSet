#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int dp[maxn][maxn][2];
int f[maxn][maxn][2];
int g[maxn][maxn][2];
  int n;
  int x, ans, flip;
int main()
{
  while(scanf("%d", &n)!=EOF)
  {
    memset(f, 0, sizeof(f));
    memset(dp, inf, sizeof(dp));
    x = 0;
    ans = inf;
    dp[1][1][0] = dp[1][1][1] = 0;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        int tmp;
        scanf("%d", &tmp);
        if (tmp)
        {
          while(tmp % 2 == 0)
          {
            tmp /= 2;
            f[i][j][0]++;
          }
          while(tmp % 5 == 0)
          {
            tmp /= 5;
            f[i][j][1]++;
          }
        }
        else
        {
          x = i;
        }
        for (int k = 0; k < 2; k++)
        {
          g[i][j][k] = dp[i - 1][j][k] > dp[i][j - 1][k];
          if (i > 1)
          {
            dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
          }
          if (j > 1)
          {
            dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k]);
          }
          dp[i][j][k] += f[i][j][k];
        }
      }
    }
    flip = dp[n][n][0] > dp[n][n][1];
    ans = dp[n][n][flip];
    if (x && ans >= 1)
    {
      puts("1");
      for (int i = 1; i < x; i++)
      {
        putchar('D');
      }
      for (int j = 1; j < n; j++)
      {
        putchar('R');
      }
      for (int i = x; i < n; i++)
      {
        putchar('D');
      }
      putchar('\n');
    }
    else
    {
      string ret;
      int px = n;
      int py = n;
      while(px != 1 || py != 1)
      {
        if (g[px][py][flip])
        {
          ret.push_back('R');
          py--;
        }
        else
        {
          px--;
          ret.push_back('D');
        }
      }
      reverse(ret.begin(), ret.end());
      printf("%d\n", ans);
      printf("%s\n", ret.c_str());
    }
  }
}
