#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll n, m;
int main()
{
  while(~scanf("%lld%lld", &n, &m))
  {
    n--;
    m--;
    ll g = __gcd(n, m);
    ll a = m / g, b = n / g;
    ll sum = a * n + 1;
    ll coll = (a - 1) * (b-1);
    ll ans = sum - coll;
    printf("%lld\n", ans );
  }
}
