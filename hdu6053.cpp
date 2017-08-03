#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int mu[maxn], primes[maxn], ptot, nprime[maxn];
int A[maxn];
int F[maxn];
int up;
int low;
const ll moder = 1e9 + 7;
void init()
{
  mu[1] = 1;
  nprime[1] = 1;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      mu[i] = -1;
      primes[ptot++] = i;
    }
    for (int j = 0; j < ptot && primes[j] * i < maxn; j++)
    {
      if (i % primes[j] == 0)
      {
        nprime[i * primes[j]] = 1;
        mu[i * primes[j]] = 0;
        break;
      }
      mu[i * primes[j]] = -mu[i];
    }
  }
}
int n;
ll p_m(ll base, int index)
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
int lb[maxn * 2];
void get_F()
{
  sort(A, A + n);
  int nex;
  for (int t = 1; t <= up * 2; t++)
  {
    lb[t] = n;
  }
  for (int i = n - 1; i >= 0; i--)
  {
    lb[A[i]] = i;
  }
  // lb[up * 2] = n;
  for (int j = up * 2 - 1; j >= 0; j--)
  {
    lb[j] = min(lb[j + 1], lb[j]);
  }
  for (int t = 1; t <= up; t++)
  {
    F[t] = 1;
    for (int i = 0; i < n; i = nex)
    {
      const int k = A[i] / t;
      nex = lb[(k+1) * t];
      F[t] = ((ll)F[t] * p_m(k, nex - i)) % moder;
    }
  }
}
ll calc()
{
  get_F();
  ll ans = 0;
  for (int d = 2; d <= up; d++)
  {
    for (int k = 1; k * d <= up; k++ )
    {
      if (mu[k] == -1) ans += (moder - F[k * d]);
      else ans += (ll)mu[k] * (ll) F[k * d] % moder;
      ans %= moder;
      // ans = (ans + moder) % moder;
    }
  }
  return ans;
}
int main()
{
  // freopen("C:\\hdsummer_data\\r2\\data\\1009.in", "r", stdin);

  init();
  int T;
  int kase = 1;
  scanf("%d", &T);
    while(T--)
    {
      scanf("%d", &n);
      up = 0;
      low = inf;
      for (int i = 0; i < n; i++)
      {
        scanf("%d", A + i);
        up = max(up, A[i]);
        low = min(low, A[i]);
      }
      printf("Case #%d: %lld\n", kase++, calc());
    }
}
/*
10
10
12 56 561 156 156 156 23 789 456 789
*/
