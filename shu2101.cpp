#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll lcm(ll a, ll b)
{
  return a / __gcd(a, b) * b;
}
int main()
{
  ll a, b, c, d, t;
  while(cin >> a >> b >>c >> d >> t)
  {
    ll ans2 = t / lcm(a,b) + t/lcm(c,d) + t/lcm(b,c) + t/lcm(a,c) + t/lcm(a, d) + t/lcm(b,d);
    ll ans3 = t / lcm(d, lcm(b,c)) + t/lcm(a, lcm(c,d)) + t/ lcm(lcm(a,b), d) + t/lcm(lcm(a, b), c);
    ll ans4 = t / lcm(lcm(a,b), lcm(c,d));
    cout << ans2 - 2 * ans3 + ans4 * 3<< endl;
  }
}
