#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;
const int maxa = 1000 + 5;
const int maxm = 1000 + 5;
const int maxb = 10 + 1;
int n, m;
int dp[maxa][maxb];
int k[maxm], p[maxm];
int a[maxn], b[maxn];
int main()
{
  while(scanf("%d%d", &n, &m) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", a + i, b + i);
    }
    memset(dp,inf,sizeof(dp));
    for (int dfn = 0; dfn < 11; dfn++) dp[0][dfn] = 0;
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d", p + i, k + i);
    }
    for (int dfn = 0; dfn < 11; dfn++)
    {
      for (int i = 0; i < m; i++)
      {
        if (k[i] > dfn)
        for (int hp = 0; hp <= 1000; hp++)
        {
          dp[min(hp + k[i] - dfn, 1000)][dfn] = min(dp[min(hp + k[i] - dfn, 1000)][dfn], dp[hp][dfn] + p[i]);
        }
      }
      for (int i = 1000; i >= 1; i--)
      {
        dp[i-1][dfn] = min(dp[i][dfn], dp[i-1][dfn]);
      }
    }
    ll acc = 0;
    for (int i = 0; i < n; i++)
    {
      if (dp[a[i]][b[i]] != inf) acc+= dp[a[i]][b[i]];
      else{acc = -1; break;}
    }
    printf("%I64d\n", acc);
  }
}
