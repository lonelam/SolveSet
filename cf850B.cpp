#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
int cnt[maxn];
bool nprime[maxn];
int n, x, y;
ll ans;
void solve()
{
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      for (int j = i + i; j < maxn; j += i) nprime[j] = true;
      ll tot = 0;
      ll cost = 0;
      for (int k = 0; k < i; k++)
      {
        tot += cnt[i - k];
        cost += (ll)(k) * (ll)y * cnt[i-k];
        for (int j = i + i; j < maxn; j += i)
        {
          tot += cnt[j - k];
          cost += (ll)(k) * (ll)y * cnt[j-k];
        }
        if (tot == n)
        {
          ans = min(ans, cost);
          break;
        }
        else if (cost + (ll)(n - tot) * (ll)y * (ll)(k) >= cost + (ll)(n-tot) * x)
        {
          break;
        }
        else
        {
          ans = min(ans, cost + (ll)(n - tot) * (ll)x);
        }
      }
    }
  }
}
int main()
{
  scanf("%d%d%d", &n, &x, &y);
  int a;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a);
    cnt[a]++;
  }
  ans = (ll)x * (ll)n;
  solve();
  printf("%lld\n", ans);
}
