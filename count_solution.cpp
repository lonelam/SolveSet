#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ld eps = 1e-8;
int main()
{
  int q;
  ll a, b, c, d;
  while(cin >> q)
  {
    while(q--)
    {
      cin >> a >> b >> c >> d;
      int ans = 0;
      for (int y = 1; y <= d; y++)
      {
        ld delta = (a * (ld)a) - 4 * (y * (ld)y - (ld)b * y);
        ld x1 = (a + sqrt(delta)) / 2;
        ld x2 = (a - sqrt(delta)) / 2;
        if (abs(x1 - (ll)x1) <= eps && 1 <= x1 && x1 <= c)
        {
 //         cout << y << " "<< x1 << endl;
          ans++;
        }
        if (delta != 0 && abs(x2 - (ll)x2) <= eps && 1 <= x2 && x2 <= c)
        {
//          cout << y << " "<< x2 << endl;
          ans++;
        }
      }
      cout << ans << endl;
    }
  }
}
