#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 2000000 + 10;
const ll moder = 1e9 + 7;
ll fac[maxn];
ll rfac[maxn];
int n, k;
ll dp[maxn];
int inline lsb(int x)
{
  return x & (-x);
}
void add(int x, int a)
{
  while(x < maxn)
  {
    dp[x] = (dp[x] + a) % moder;
    x += lsb(x);
  }
}
ll query(int x)
{
  ll ret = 0;
  while(x)
  {
    ret = (ret + dp[x]) % moder;
    x -= lsb(x);
  }
  return ret;
}
ll p_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1LL)
    {
      ret = (ret * base) % moder;
    }
    base = (base * base) % moder;
    index >>= 1;
  }
  return ret;
}
int main()
{
  fac[0] = 1LL;
  for (int i = 1; i < maxn; i++)
  {
    fac[i] = fac[i-1] * (ll)i % moder;
  }
  rfac[maxn-1] = p_m(fac[maxn-1LL], moder - 2LL);
  for (int i = maxn - 2; i >= 0; i--)
  {
    rfac[i] = rfac[i+1] * (ll)(i+1LL) % moder;
  }
  while(~scanf("%d%d", &n, &k))
  {
    memset(dp, 0, sizeof(dp));
    add(k+1, fac[k]);
    ll ans = fac[k] % moder * rfac[k+1] % moder;
  //  dp[k+1] = 1;
    for (int i = k + 2; i < n; i++)
    {
      //dp[i] = (fac[i-1]*(ll)(i-k) % moder + (query(i) - query(i-k) + moder) % moder) % moder;
      ll tmp = (fac[i-1]*(ll)(i-k) % moder + (query(i-1) - query(i-k - 1) + moder) % moder*fac[i-1] % moder) % moder;
      ans = ( ans + tmp % moder * rfac[i] % moder) % moder;
      add(i,  tmp * rfac[i] % moder);
    }
    if (k + 1 >= n) ans = 0;
    else ans = (ans * fac[n-1]) % moder;
    printf("%lld\n", ans);
  }
}
