#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll ds[maxn];
int main()
{
  int n;
  cin >> n;
  {
    ll up = 1e7;
    ll sum = 0;
    for (ll s = 10; s < up; s++)
    {
      ll ts = s;
      ll tsum = 0;
      int cnt = 0;
      while(ts)
      {
        ds[cnt] = 1;
        ll tmp = ts % 10;
        for (int j = 0; j < n; j++)
        {
          ds[cnt] *= tmp;
        }
        tsum += ds[cnt++];
        ts/=10;
      }
//      cout << s << "  "<< tsum << endl;
      if (s == tsum)
      {
        sum += tsum;
      }
    }
    cout << sum << endl;
  }
}
