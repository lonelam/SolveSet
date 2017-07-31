#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
const ll moder = 1e9 + 7;
int n;
char s[maxn];
ll dp[maxn];
int main()
{
  while(scanf("%s", s) != EOF)
  {
    n = strlen(s);
    ll pre = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      pre = (pre * 10 + (ll)(s[i] - '0') * (ll)(i + 1) )%moder;
      ans += pre;
      ans %= moder;
    }
    printf("%lld\n", ans);
  }
}
