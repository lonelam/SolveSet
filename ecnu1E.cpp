#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
ll gcd(ll a, ll b)
{
  return b == 0 ? a : gcd(b, a % b);
}
int main()
{
  ll x, n;
  while(scanf("%lld%lld", &x, &n) != EOF)
  {
    for (ll i = 2; i <= n; i++)
    {
      printf("%lld\n", i / gcd(x, i));
    }
  }
}
