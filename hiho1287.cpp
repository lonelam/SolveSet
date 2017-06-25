#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int s = 12;
ll qmul(ll x, ll y, ll moder)
{
  ll ans = 0;
  while(y)
  {
    if (y & 1)
    {
      ans = (ans + x) % moder;
    }
    x = (x + x) % moder;
    y >>= 1;
  }
  return ans;
}
ll pow_mod(ll base, ll index, ll moder)
{
  ll ans = 1;
  while(index)
  {
    if (index & 1)
    {
      ans = qmul(ans, base, moder);//(ans * base) % moder;
    }
    base = qmul(base, base, moder);//(base * base) % moder;
    index >>= 1;
  }
  return ans;
}
bool RabinTest(ll n)
{
  if (n == 2)
  {
    return true;
  }
  for (int i = 0; i < s; i++)
  {
    ll a = primes[i];
    if (a == n)
    {
      return true;
    }
    ll u = n - 1;
    while(u % 2 == 0)
    {
      u /= 2;
    }
    ll x = pow_mod(a, u, n);
    while(u < n)
    {
      ll y = qmul(x, x, n);//x * x % n;
      if (y == 1 && x != 1 && x != n - 1)
      {
        return false;
      }
      x = y;
      u = u * 2;
    }
    if (x != 1)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int T;
  ll a;
  while(cin >> T)
  {
    while(T--)
    {
      cin >> a;
      if (RabinTest(a))
      {
        cout << "Yes" << endl;
      }
      else
      {
        cout << "No" << endl;
      }
    }
  }
}
