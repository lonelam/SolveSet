#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  ll n, k;
  while(cin >> n >> k)
  {
    ll times = n / k;
    if (times & 1)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }
}
