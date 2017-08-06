
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const ll moder = 1e9 + 7;
int A[maxn];
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
    base *= base;
    index >>= 1;
    base %= moder;
  }
  return ret;
}
int main()
{
  int n, k;
  while(scanf("%d%d", &n, &k) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", A+i);
    }
    sort(A, A + n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
      int m = upper_bound(A, A + i + 1, k - A[i]) - A;
      if (m == i + 1)
      {
        ans += 1;
        ans %= moder;
        m--;
      }
      ans += (p_m(2, i) - p_m(2, i - m) + moder) % moder;
      ans %= moder;
    }
    printf("%lld\n", ans);
  }
}
