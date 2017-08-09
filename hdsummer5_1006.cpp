#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      ll n, m;
      scanf("%lld%lld", &n, &m);
      m = min(m, n * (n - 1) / 2);
      ll ans = (n - 1) * (n - 1) * 2 - (m - n + 1) * 2;
      if (m < n - 1)
      {
        ans = n * (n - m - 1) * (n - 1) + m * (2 * m - 1 + n * (n - m - 1)) + m + n * (n - m - 1);
      }
      printf("%lld\n", ans);
    }
  }
}
