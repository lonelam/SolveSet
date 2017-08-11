#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const ll moder = 1e9 + 7;
int n;
int A[maxn];
int nprime[maxn];
int primes[maxn], ptot;
int mu[maxn];
void init()
{
  nprime[1] = mu[1] = 1;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      primes[ptot++] = i;
      mu[i] = 1;
    }
    for (int j = 0; j < ptot && primes[j] * i < maxn; j++)
    {
      nprime[i * primes[j]] = 1;
      if (i % primes[j] == 0)
      {
        mu[i * primes[j]] = 0;
        break;
      }
      mu[primes[j] * i] = -mu[i];
    }
  }
}
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
int main()
{
  // freopen("C:\\hdsummer_data\\r2\\data\\1009.in", "r", stdin);
  init();
  int T;
  int kase = 1;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
        scanf("%d", A + i);
      }
      sort(A, A + n);
      int up = A[n-1];
      ll ans = 0;
      for (int i = 2; i <= up; i++)
      {
        if (!mu[i]) continue;
        ll acc = 1;
        int nex;
        for (int j = 0; j < n; j = nex)
        {
          nex = lower_bound(A, A + n, (A[j] / i + 1) * i) - A;
          acc *= p_m(A[j] / i, nex - j);
          acc %= moder;
        }
        if (mu[i] == 1)
        {
          ans += acc;
          ans %= moder;
        }
        else if (mu[i] == -1)
        {
          ans += (moder - acc);
          ans %= moder;
        }
      }
      printf("Case #%d: %lld\n",kase++, ans);
    }
  }
}
