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
    while(T--)
    {
      ll x;
      int k;
      cin >> x >> k;
      ll a = floor(sqrt((ld)x));
      ll ans = (a-1) * 2;
      if (x != a * a)
      {
        ans++;
      }
      if (k == 1)
      {
        ans++;
      }
      if (k == 2 && x >= 10 && x == a * a + 1)
      {
        ans--;
      }
      if (x == 0)
      {
        ans = 0;
      }
      else if (x == 1)
      {
        if (k==1) ans = 1;
        else if (k==2) ans = -1;
      }
      else if (x == 3)
      {
        if (k == 1) ans = 2;
        else if (k == 2) ans = -1;
      }
      cout << ans << endl;
    }
  }
}
