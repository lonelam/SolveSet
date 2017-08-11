#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 250000 + 100;
int a[maxn * 2], b[maxn], limit[maxn * 2];
int postmax[maxn];
bool vis[maxn];
int n;
const ll moder = 1e9 + 7;
int main()
{
  while(scanf("%d", &n)!=EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a + i);
      limit[i] = a[i] - i - 1;
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%d", b + i);
      b[i]--;
    }
    postmax[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      postmax[i] = max(postmax[i + 1], limit[i]);
    }
    sort(b, b + n);
    a[n] = postmax[b[0]];
    limit[n] = a[n] - n - 1;
    for (int i = 0; i < n; i++)
    {
      postmax[i] = max(postmax[i], limit[n]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
//      cout << postmax[b[i] - 1]
      ans += postmax[b[i]];
      ans %= moder;
    }
    printf("%lld\n", ans);
  }
}
