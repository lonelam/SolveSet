#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const ll moder = 1e9 + 7;
const int maxn = 100000 + 100;
ll phi(ll n)
{
  ll ans = n;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ans -= ans/ i;
      while(n % i == 0)
      {
        n /= i;
      }
    }
  }
  if (n > 1) ans -= ans / n;
  return ans;
}
ll m, p;
ll solve(ll n)
{
  ll ret = 0;
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ll d = n / i;
      ret += d * d * ((i * phi(i) + (i == 1)) / 2) % moder;
      ret %= moder;
      if (d != i)
      {
        ret += i * i * ((d * phi(d) + (d == 1))/ 2) % moder;
        ret %= moder;
      }
    }
  }
  return ret;
}
int main()
{
  int kase = 1;
  int T;
  scanf("%d", &T);
  while(T-- && scanf("%lld%lld", &m, &p)!= EOF)
  {
    ll ans = (m * solve(p - 1) % moder - (p * (p - 1) / 2)%moder * m % moder) % moder;
    ans += moder;
    ans %= moder;
    printf("Case #%d: %lld\n", kase++, ans);
  }
}
