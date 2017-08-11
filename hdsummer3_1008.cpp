#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const int moder = 1e9 + 7;
ll p_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret *= base;
      ret %= moder;
    }
    base *= base;
    base %= moder;
    index >>= 1;
  }
  return ret;

}
int main()
{
  ll n, k;
  int kase = 1;
  while(scanf("%lld%lld", &n, &k)!= EOF)
  {
    printf("Case #%d: %lld\n", kase++, p_m(n%moder, k));
  }
}
