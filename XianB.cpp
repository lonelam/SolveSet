#define _CRT_SECURE_NO_WARNINGS

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll moder = 1e9 + 7;
int T;
ll p_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret = ret * base % moder;
    }
    index >>= 1;
    base = base * base % moder;
  }
  return ret;
}
ll p, q, k;
ll inv(ll x)
{
  return p_m(x, moder - 2);
}
// ll mem[10000000 + 10];
int main()
{
  scanf("%d", &T);
  while(T--)
  {
    scanf("%llu%llu%llu", &p, &q, &k);
    assert(p_m(p, moder - 1) == 1);
    assert(inv(p) * p % moder== 1);
    ll pinv = inv(p);
    ll p_qinv = inv((moder + p - q)% moder);
    ll item = p_m((moder  + 1 - q * pinv% moder) % moder, k);
    // cout << (moder  + 1 - q * pinv % moder) % moder << endl;
    // cout << ((p + moder - q) % moder * pinv % moder) << endl;
    ll aq = q * q % moder * p_qinv % moder * p_qinv % moder;
    // ll ans = p_m(((p - q + moder) % moder * pinv % moder), k);
    ll ans = (1 + p_m(moder + 1 - 2 * q % moder * pinv % moder, k)) % moder * inv(2) % moder;
    // cout << item << endl;
    // cout << ans <<endl;
    // assert(item == ans);
    // ll m = k / 2;
    // ll ad = p_m((moder + 1  - aq)% moder, moder - 2);
    // ll au = (moder  + 1 - p_m(aq, m)) % moder;
    // ll res = (az * au % moder * ad) % moder;

    printf("%llu\n", ans);
  }
}
