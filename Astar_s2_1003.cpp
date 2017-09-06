#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 100;
const ll moder = 1e9 + 7;
ll fac[maxn];
ll inv2 = 500000004;
ll dp[maxn];
ll p_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret = (ret * base) % moder;
    }
    index >>= 1;
    base = (base * base) % moder;
  }
  return ret;
}
void init()
{
  dp[1] = 1;
  dp[2] = 6;
  for (int i = 3; i < maxn; i++)
  {
    dp[i] = (2 * dp[i - 1] + 4 * dp[i - 2]+ p_m(2, i - 1)) % moder;
  }
}
int n;
int main()
{
  int T;
  init();
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);

      ll ans = 4 * dp[n] % moder;
      if (n == 1)
      {
        ans = 2;
      }
      for (int i = 2; i < n; i++)
      {
        ans = (ans + p_m(2, i - 1) * dp[n - i]%moder * 8 % moder)% moder;
      }
      printf("%d\n", (int)ans);
    }
  }
}
