#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 18;
const int maxs = 1 << maxn;
const ll moder = 1e9 + 7;
int k;
ll dp[maxn + 1][maxs];
inline void add(ll & a, ll & b)
{
  a = (a + b) % moder;
}
int a[maxn];
int n;
int main()
{
  scanf("%d%d", &n, &k);
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a + i);
    }
    memset(dp, 0, sizeof(dp));
    int ups = 1 << n;
    dp[0][ups - 1] = 1;
    for (int i = 0; i < n; ++i)
    {
      for (int s = 0; s < ups; ++s)
      {
        if (!dp[i][s]) continue;
        for (int j = 0; j < n; ++j)
        {
          if (s >> j & 1)
          {
            int ts = s;
            int g = a[j];
            for (int p = j; p < n; p++)
            {
              if (ts >> p & 1)
              {
                ts ^= 1 << p;
                g = __gcd(g, a[p]);
                if (g >= k)
                {
                  add(dp[i + 1][ts], dp[i][s]);
                }
                else
                {
                  break;
                }
              }
            }
          }
        }
      }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
      ans = (ans + i * (ll)dp[i][0]) % moder;
    }
    printf("%lld\n", ans);
  }
}
/*
18 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
