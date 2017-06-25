#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
ll f(ll n, ll k)
{
  if (k >= n)
  {
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
      ans = (ans + k) % (i + 1);
    }
    return ans;
  }
  ll exceed = (f(n - n / k, k) + n / k * k);
  if (exceed < n) return exceed;
  return exceed % n / (k - 1) * k + exceed % n % (k - 1) ;
}
int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      ll n, k;
      scanf("%lld%lld", &n, &k);
      printf("%lld\n", f(n, k));
    }
  }
}
