#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const int moder = 998244353;
ll p_m(ll base, ll index)
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
ll F(ll a, ll b)
{
  if (a > b)
  {
    swap(a, b);
  }
  ll z = 0;
  ll t = 1;
  for (int i = 0; i <= a; i++)
  {
    z = (z + t) % moder;
    t = t * (a - i)%moder * (b - i)%moder *p_m(i + 1, moder - 2) % moder;
  }
  return z;
}
int main()
{
  ll a, b, c;
  while(cin >> a >> b >> c)
  {
    cout << F(a, b) * F(a,c) % moder * F(b, c) % moder << endl;
  }
}
