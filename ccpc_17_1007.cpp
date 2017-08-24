#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll bint[maxn];
int T;
int n;
ll base;
ll raw;
ll p_m(ll b, ll ind)
{
  ll ret = 1;
  while(ind)
  {
    if (ind & 1)
    {
      ret *= b;
    }
    b*= b;
    ind >>= 1;
  }
  return ret;
}
ll solve()
{
  bool flg = true;
  for (int i = n / 2; i < n; i++)
  {
    if (bint[i] < bint[n - i - 1])
    {
      flg = false;
      break;
    }
    else if (bint[i] > bint[n - i - 1])break;
  }
  ll acc = 0;
  ll mask = 1;
  for (int i = 0; i + i < n; i++)
  {
    acc *= base;
    acc += bint[i];
    mask *= base;
  }
  if (!flg)
  {
    acc--;
  }
  if (n & 1)
  {
    acc += mask / base - 1;
  }
  else
  {
    acc += mask - 1;
  }
  acc *= base - 1;
  return acc;
}
ll l, r;
ll trans()
{
  ll ret = 0;
  for (base = l; base <= r; base++)
  {
    ll mask = 1;
    ll rem = raw;
    n = 0;
    while(rem)
    {
      bint[n++] = rem % base;
      rem /= base;
    }
    reverse(bint, bint + n);
    ret += raw + solve();
  }
  return ret;
}
int main()
{
  while(scanf("%d", &T) != EOF)
  {
    ll L, R;
    int kase = 1;
    while(T--)
    {
      scanf("%lld%lld%lld%lld", &L, &R, &l, &r);
      raw = R;
      ll ans = trans();
      raw = L - 1;
      if (raw) ans -= trans();
      printf("Case #%d: %lld\n", kase++, ans);
    }

  }
}
