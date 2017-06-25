#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll m, b;
ll calc(ll x, ll y)
{
  ll up = (x + y + y) * (x + 1) / 2;
  ll down = (x + 1) * x / 2;
  return (up + down) * (y + 1) / 2;
}
int main()
{
  cin >> m >> b;
  ll ans = 0;
  for (ll y = b; y >= 0; y--)
  {
    ll x = (b - y) * m;
    //cout << x <<"  " << y << "  "<< calc(x, y) << endl;
    ans = max(ans, calc(x, y));
  }
  cout << ans << endl;
}
