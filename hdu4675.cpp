#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 100;
const ll moder = 1e9 + 7;
int n, m, k;
int a[maxn];
ll p_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index &1)
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
int num[maxn];
ll ans[maxn];
ll fac[maxn], inv[maxn];
ll comb(ll n, ll m)
{
  return (fac[n] * inv[m] % moder) * inv[n - m] % moder;
}
void init()
{
  fac[0] = inv[0] = 1;
  for (int i =1; i < maxn; i++)
  {
    fac[i] = fac[i - 1] * i % moder;
    inv[i] = p_m(fac[i], moder-2);
  }
}
int main()
{
  init();
  while(scanf("%d%d%d", &n, &m, &k) != EOF)
  {
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++)
    {
      static int tmp;
      scanf("%d", &tmp);
      num[tmp]++;
    }
    for (int i = m; i >= 1; i--)
    {
      int sum = 0;
      for (int j = i; j <= m; j+= i)
      {
        sum += num[j];
      }
      if (n - sum > k)
      {
        ans[i] = 0;
      }
      else
      {
        ans[i] = (p_m(m / i, n - sum) * p_m(m / i - 1, k - n + sum) % moder) * comb(sum, k - n + sum) % moder;
        for (int j = i + i; j <= m; j+= i)
        {
          ans[i] = (ans[i] - ans[j] + moder) % moder;
        }
      }
    }
    printf("%I64d", ans[1]);
    for (int i = 2; i <= m; i++)
    {
      printf(" %I64d", ans[i]);
    }
    puts("");
  }
  return 0;
}
