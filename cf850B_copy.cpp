#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 2000000 + 100;
int n, x, y;
int a;
ll acnt[maxn];
ll asum[maxn];
ll ans;
void solve(int g)
{
  ll acc = 0;
  int d = min(x / y, g - 1);
  for (int i = g; i < maxn; i+=g)
  {
    acc += (ll)x * (acnt[i - d - 1] - acnt[i - g]);
    acc += (ll)y * ((acnt[i] - acnt[i - d - 1]) *(ll)(i) - (asum[i] - asum[i - d - 1]));
  }
  ans = min(ans, acc);
}
int main()
{
  scanf("%d%d%d", &n, &x, &y);
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a);
      asum[a]+=a;
      acnt[a]++;
    }
    for (int i = 1; i < maxn; i++)
    {
      asum[i] += asum[i-1];
      acnt[i] += acnt[i-1];
    }
    ans = (ll)n * (ll)x;
    for (int i = 2; i < maxn; i++)
    {
      solve(i);
    }
    printf("%lld\n", ans);
  }
}
