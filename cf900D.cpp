#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const ll moder = 1e9 + 7;
map<ll, ll> mem;
ll p2(ll index, ll base = 2LL)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret = (ret * base) % moder;
    }
    base = (base * base) % moder;
    index >>= 1;
  }
  return ret;
}
ll f(ll n)
{
  if (mem.find(n) != mem.end())
  {
    return mem[n];
  }
  ll acc = 1;
  ll m = n;
  ll b;
  for (b = 2; b * b < m; b++)
  {
    if (m % b == 0)
    {
      acc += f(b);
      acc %= moder;
      acc += f(m / b);
      acc %= moder;
    }
  }
  if (b * b == m)
  {
    acc += f(b);
    acc %= moder;
  }
  return mem[n] = (p2(n - 1) - acc + moder) % moder;
}
int main()
{
  ll x, y;
  mem[1] = 1;
  mem[2] = 1;
  while(cin >> x >> y)
  {
    if (y % x)
    {
      cout << 0 << endl;
    }
    else
    {
      cout << f(y / x) << endl;
    }
  }
}
