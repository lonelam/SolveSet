#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000000 + 10;
ll dp[maxn];
bool np[maxn];
int main()
{
  int N;
  scanf("%d", &N);
  np[1] = true;
  for (int i = N; i > 1; i--)
  {
    dp[i] = (ll)(N / i) * (ll)(N / i);
    for (int j = i + i; j <= N; j += i)
    {
      np[j] = true;
      dp[i] -= dp[j];
    }
  }
  ll ans = 0;
  for (int i = 2; i <= N; i++)
  {
    if (!np[i])
    {
      ans += dp[i];
    }
  }
  printf("%lld\n", ans);
}
