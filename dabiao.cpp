#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000;
ll f(int n)
{
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      if (__gcd(i, j) == 1)
      {
        ans += (i + j - 1) / j;
      }
    }
  }
  return ans;
}
ll g(int n)
{
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
        ans += (i + j - 1) / j;
    }
  }
  return ans;
}
const ll moder = 1e9 + 7;
ll p_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret = (ret * base) % moder;
    }
    index >>= 1;
    base = (base * base) % moder;
  }
  return ret;
}
int main()
{
  cout << p_m(2, moder -2) << endl;

}
