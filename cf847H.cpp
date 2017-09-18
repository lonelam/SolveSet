#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
ll a[maxn];
ll b[maxn];
ll c[maxn];
int n;
ll dp[maxn];
ll rdp[maxn];
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", a + i);
    b[i] = c[i] = a[i];
  }
  for (int i = 1; i < n; i++)
  {
    if (b[i] <= b[i-1])
    {
      dp[i] = dp[i-1] + b[i-1] - b[i] + 1LL;
      b[i] = b[i-1] + 1LL;
    }
    else
    {
      dp[i] = dp[i-1];
    }
  }
  for (int i = n - 2; i >= 0; i--)
  {
    if (c[i] <= c[i+1])
    {
      rdp[i] = rdp[i+1] + c[i+1] - c[i] + 1LL;
      c[i] = c[i+1] + 1LL;
    }
    else
    {
      rdp[i] = rdp[i+1];
    }
  }
  ll ans = min(rdp[0], dp[n-1]);
  for (int i = 1; i < n; i++)
  {
    // cout << dp[i] << " ";
    if (b[i-1] != c[i])
    ans = min(ans, dp[i-1] + rdp[i]);
    else
    ans = min(ans, dp[i-1] + rdp[i] + 1LL);

  }
  // cout << endl;
  printf("%lld\n", ans);
}
