#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const int maxb = 35;
const ll moder = 998244353;
int dp[maxb][2];
int a[maxn];
ll q_pow(ll base, ll index)
{
  ll ans = 1;
  while(index)
  {
    if (index & 1)
    {
      ans = (ans * base) % moder;
    }
    base = (base * base) % moder;
    index >>= 1;
  }
  return ans;
}
int main()
{
  int n;
  scanf("%d", &n);
  ll cnt = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d",  a + i);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    int x = a[i];
    int b = 0;
    while(x)
    {
      b++;//dp[b++][x & 1] += 1;
      x >>= 1;
    }
    int k = i - 1;
    ll index = n - 2;
    x = a[i];
    if (!dp[b-1][1]) index++;
    b = 0;
    while(x)
    {
      dp[b++][x & 1] += 1;

      x >>= 1;
    }
    if (a[i]) ans = (ans + q_pow(2, index)) % moder;
  }
  printf("%lld\n", ans);

}
