#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll n, x, y, c;
bool check(ll s)
{
  ll raw = 1LL + 2LL * s * (1LL + s);
  if (x - 1 < s)
  {
    raw -= (s - x + 1) * (s - x + 1);
  }
  if (n - x < s)
  {
    raw -= (s - n + x) * (s - n + x);
  }
  if (y - 1 < s)
  {
    raw -= (s - y + 1) * (s - y + 1);
  }
  if (n - y < s)
  {
    raw -= (s - n + y) * (s - n + y);
  }
  if (x + y - 2 < s)
  {
    ll t = s - x - y + 2;
    raw += t * (t + 1) / 2;
  }
  if (n + n - x - y  < s)
  {
    ll t = s + x + y - n - n;
    raw += t * (t + 1) / 2;
  }
  if (x + n - y - 1 < s)
  {
    ll t = s - x - n + y + 1;
    raw += t * (t + 1) / 2;
  }
  if (y + n - x - 1 < s)
  {
    ll t = s - y - n + x + 1;
    raw += t * (t + 1) / 2;
  }
  cout << s << " "<<raw << endl;
  return raw >= c;
}
int main()
{
  while(cin >> n >> x >> y >> c)
  {
   // cout << check(3906250) << endl;
    ll L = 0, R = n * 2;
    while(L < R)
    {
      const ll mid = L +  (R - L) / 2LL;
      if (check(mid))
      {
      }
      R = mid;
      else
      {
        L = mid + 1;
      }
    }
    cout << R  + 1<< endl;
  }
}
