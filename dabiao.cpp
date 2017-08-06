#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000;
  ll m, p;
ll p_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret = (ret * base) % p;
    }
    base = (base * base) % p;
    index >>= 1;
  }
  return ret;
}
int main()
{
  cin >> m >> p;
  ll ans = 0;
  for (ll i = 1; i < p; i++)
  {
    for (ll x = 1; x < p; x++)
    {
      for (ll y = 1; y <= m; y++)
      {
        if (p_m(x + y, i) == p_m(x, i))
        {
          cout << "i="<<i<<",x="<<x<<",y="<<y <<endl;
          ans += i;
        }
      }
    }
  }
  cout << "ans="<< ans << endl;
}
