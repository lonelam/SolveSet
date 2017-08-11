#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int moder = 1e9 + 7;
ll fac[maxn], inv[maxn];
int cnt[30];
void init()
{
  fac[0] = inv[0] = 1;
  for (int i = 1; i < maxn; i++)
  {
    fac[i] = fac[i - 1] * i % moder;
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; i++)
  {
    inv[i] = (moder - moder / i) * inv[moder % i]  % moder;
  }
  for (int i = 2; i < maxn; i++)
  {
    inv[i] = inv[i] * inv[i - 1] % moder;
  }
}
ll C(int n, int m)
{
  if (m > n) return 0;
  return fac[n] * inv[m] % moder * inv[n - m] % moder;
}
int main()
{
  init();
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int n, k;
    scanf("%d%d", &n, &k);
    memset(cnt,0,sizeof(cnt));
    for (int i = 0; i < n; i++)
    {
      int x;
      scanf("%d", &x);
      for (int j = 0; j < 20; j++)
      {
        cnt[j] += (x >> j) & 1;
      }
    }
    ll s = 1, ans = 0;
    for (int j = 0; j < 20; j++)
    {
      ans += (C(n, k) - C(n - cnt[j], k) + moder) % moder * s % moder;
      ans %= moder;
      s *= 2;
    }
    printf("%lld\n", ans);
  }
}
