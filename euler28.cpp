#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll moder = 1e9+7;
int main()
{
  ll n;
  int T;
  cin >> T;
  while(T--)
  {
    cin >> n;
    ll up = (n / 2)%moder;
    ll ans = (1 + 8 * up%moder * (up + 1)%moder * (2*up + 1)%moder * 333333336LL % moder + (up+1)%moder*up%moder*2 % moder + 4*up%moder)% moder;

    cout << ans << endl;
  }
}
