
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
const ll moder = 1e9 + 7;
ll ans;
map<pair<int, int>, int> pos;
ll inv_fact[maxn];
ll fact[maxn];
int n;
ll pow_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret *= base;
      ret %= moder;
    }
    index >>= 1;
    base *= base;
    base %= moder;
  }
  return ret;
}
void getinv()
{
  fact[1] = fact[0] = 1;
  for (ll i = 2; i <= n; i++)
  {
    fact[i] = fact[i-1] * (ll)i % moder;
  }
  inv_fact[n] = pow_m(fact[n], moder - 2);
  for (int i = n - 1; i >= 0; i--)
  {
    inv_fact[i] = inv_fact[i + 1] * (ll)(i + 1) % moder;
  }
}
ll comb(int n, int m)
{
  return fact[n] * inv_fact[n - m] % moder * inv_fact[m] % moder;
}
void quickpartition(int L = 1, int R = n)
{
  if (L >= R)
  {
    return;
  }
  const int mid = pos[{L, R}];
  ans *= comb(R - L, mid - L);
  quickpartition(L, mid - 1);
  quickpartition(mid + 1, R);
  return;
}
void init()
{
  ans = 1;
  pos.clear();
  getinv();
}
int l[maxn], r[maxn];
int main()
{
  int kase = 1;
  while(scanf("%d", &n) != EOF)
  {
    init();
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", l + i);
    }
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", r + i);
    }
    for (int i = 1; i <= n; i++)
    {
      pos[{l[i], r[i]}] = i;
    }
    quickpartition();
    printf("Case #%d: %lld\n",kase++,  ans);
  }
}
