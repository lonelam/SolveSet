#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll a, b;
int main()
{
  while(cin >> a >> b)
  {
    ll ans = 1;
    for (ll i = a + 1; i <= b; i++)
    {
      ans = (ans * i) % 10;
      if (ans == 0)
      {
        break;
      }
    }
    cout << ans << endl;
  }

}
