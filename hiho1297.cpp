#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
  if (!b) {x = 1; y = 0; return a;}
  ll g = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}
int main()
{
  ll s1, s2, v1, v2, m;
  while(scanf("%lld%lld%lld%lld%lld", &s1, &s2, &v1, &v2, &m) != EOF)
  {
    ll t, k;
    if (v1 == v2)
    {
      if (s1 == s2)
      {
        printf("0\n");
      }
      else
      {
        printf("-1\n");
      }
      continue;
    }
    if (v1 > v2)
    {
      swap(v1, v2);
      swap(s1, s2);
    }
    ll c = s1 - s2;
    ll g = exgcd(v2 - v1, m, t, k);
    ll a = (v2 - v1) / g;
    ll b = m / g;
    //exgcd(a, b, t, k);
    if (abs(c) % g)
    {
      printf("-1\n");
    }
    else
    {
      t *= c / g;
      t = (t % b + b) % b;
      printf("%lld\n", t);
    }
  }
}
