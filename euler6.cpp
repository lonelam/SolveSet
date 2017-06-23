#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int T;
ll presum[maxn];
ll presq[maxn];
int main()
{
  for (ll i = 1; i < maxn; i++)
  {
    presum[i] = presum[i - 1] + i;
    presq[i] = presq[i - 1] + i * i;
  }
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      ll n;
      scanf("%lld", &n);
      ll ans = presum[n] * presum[n] - presq[n];
      printf("%lld\n", ans);
    }
  }
}
