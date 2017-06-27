#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
//reference :https://en.wikipedia.org/wiki/Zeller%27s_congruence
int calc(ll yy, ll mm, ll dd)
{
  if (mm <= 2)
  {
    mm += 12;
    yy--;
  }
  int h = (dd + (13 * (mm+1))/5 + yy + yy/4 - yy/100+yy/400) % 7LL;
  return h;
}
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    ll y1, m1,d1,y2,m2,d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    int ans = 0;
    if (y1 != y2)
    for (int m = (d1==1)?m1:m1+1; m <= 12; m++)
    {
      if (calc(y1, m, 1) == 1)
      {
        ans++;
      }
    }
    else for (int m = (d1 == 1)?m1:m1+1; m <= m2; m++)
    {
      if (calc(y1,m,1) == 1)
      {
        ans++;
      }
    }
    for (ll y = y1+1; y < y2; y++)
    {
      for (int m = 1; m <= 12; m++)
      {
        if (calc(y, m, 1) == 1)
        {
          ans++;
        }
      }
    }
    if (y1 != y2)
    for (int m = 1; m <= m2; m++)
    {
      if (calc(y2, m, 1) == 1)
      {
        ans++;
      }
    }
    cout << ans << endl;
  }
}
