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
  ll ans = 0;
  for (int d = 2; d < 100; d++)
  {
    cout << d * log10(d) << endl;
  }
}
