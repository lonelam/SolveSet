#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  int T;
  while(cin >> T)
  {
    ll n;
    while(T--)
    {
      cin >> n;
      ll lcm = 1;
      for (ll i = 2; i <= n; i++)
      {
        lcm = lcm / __gcd(lcm, i) * i;
      }
      cout << lcm << endl;
    }
  }
}
