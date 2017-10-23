#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll n, m, a, d;
ll t[maxn];
int main()
{
  scanf("%lld%lld%lld%lld", &n, &m, &a, &d);
  for (ll i = 0; i < m; i++)
  {
    scanf("%lld", t + i);
  }
  t[m++] = n * a;
  sort(t, t + m);
  l = (d / a + 1) * a;
  ll p = -d;
  ll ans = 0;
  for (int i = 1; i <= m; i++)
  {
    while(p + d < t[i])
    {
      if ((p+d) / a + 1 > n)
      {
        p = t[i];
        ans++;
      }
      else
      {
        ll tmp = ((p+d) / a + 1) * a;
      }
    }
  }
}
