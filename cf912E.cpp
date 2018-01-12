#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n;
ll ps[100 + 5];
ll check(ll up)
{
  ll ans = 1;
  for (int st = 1; st < (1 << n); st++)
  {
    ll prod = 1;
    for (int i = 0; i < n; i++)
    {
      if (st >> i & 1)
      {
        prod *= ps[i];
      }
    }
    if (__builtin_popcount(st) & 1)
    {
      ans += up / prod;
    }
    else
    {
      ans -= up / prod;
    }
  }
  return ans;
}
int main()
{
  while(~scanf("%d", &n))
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%lld", ps + i);
    }
    ll k;
    scanf("%lld", &k);
    ll L = 2, R = 1e18;
    while(L + 1 < R)
    {
      const ll mid = L + (R - L) / 2;
      // cout << check(mid) << endl;
      if (check(mid) > k)
      {
        R = mid;
      }
      else
      {
        L = mid;
      }
    }
    printf("%lld\n", L);
  }
}
