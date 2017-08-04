#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
int disc[maxn];
int x[maxn], y[maxn], z[maxn];
int xi[maxn], yi[maxn], zi[maxn];
int dp[maxn][maxn];
int tot;
int n;
int main()
{
  int kase = 1;
  while(scanf("%d", &n) != EOF && n)
  {
      tot = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d", x + i, y + i, z + i);
      if (x[i] > y[i])
      {
        swap(x[i], y[i]);
      }
      if (y[i] > z[i]) swap(y[i], z[i]);
      if (x[i] > y[i]) swap(x[i], y[i]);
      disc[tot++] = x[i];
      disc[tot++] = y[i];
      disc[tot++] = z[i];
    }
    disc[tot++] = inf;
    int ans = 0;
    sort(disc, disc + tot);
    tot = unique(disc, disc + tot) - disc;
    memset(dp, 0,sizeof(dp));
    for (int i = 0; i < n; i++)
    {
         xi[i] = lower_bound(disc, disc + tot, x[i])-disc;
         yi[i] = lower_bound(disc, disc + tot, y[i])-disc;
         zi[i] = lower_bound(disc, disc+ tot, z[i]) - disc;
    }
    for (int i = tot - 1; i >= 0; i--)
    {
      for (int j = tot - 1; j >= i; j--)
      {
        for (int k = 0; k < n; k++)
        {
          if (i > xi[k] && j > yi[k]) dp[xi[k]][yi[k]] = max(dp[xi[k]][yi[k]], dp[i][j] + z[k]);
          if (i > xi[k] && j > zi[k]) dp[xi[k]][zi[k]] = max(dp[xi[k]][zi[k]], dp[i][j] + y[k]);
          if (i > yi[k] && j > zi[k]) dp[yi[k]][zi[k]] = max(dp[yi[k]][zi[k]], dp[i][j] + x[k]);

        }
      }
    }
    for (int i = 0; i < tot; i++)
    {
      for (int j = i; j < tot; j++)
      {
        ans = max(ans, dp[i][j]);
      }
    }
    printf("Case %d: maximum height = %d\n", kase++, ans);
  }
}
